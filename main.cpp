//
//  main.cpp
//  NQueens
//
//  Created by Soulier Antoine on 13/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#include <iostream> 	// cout
#include <algorithm>	// generate
#include <vector>       // vector
#include <deque>        // deque
#include <ctime> 		// srand, time
#include <iomanip>		// setw
#include <string>       // string

#include "global.h"
#include "Solution.h"
#include "generator.h"
#include "mutator.h"
#include "evaluator.h"
#include "crossover.h"



/************/
/* SELECTOR */
/************/


#include "rankSelector.h"
#include "noteSelector.h"
#include "elitistSelector.h"
#include "tournamentSelector.h"




/****************/
/* END CRITERIA */
/****************/


#include "qualityLimit.h"
#include "flatResultsLimit.h"
#include "iterationLimit.h"
#include "miscLimit.h"




using namespace std;

// Display

template<typename T>
void displayContainers(string prefix, T it, T end)
{
    cout << prefix << ": ";
    for (; it != end; ++it) {
        cout << setw(4) << *it;
    }
    cout << endl;
}

void displayChessboard(const Solution &s);
void printUsage();




/*********************/
/* GENETIC ALGORITHM */
/*********************/


template<typename T, typename G, typename E, typename S, typename C, typename M, typename F>
T generate(G generator, E evaluator, S selector, C crossover, M mutator, F stop, int sizePopulation) {
    T result;

    // Create sizePopulation random solutions
    vector<T> solutions;
    generate_n(back_inserter(solutions), sizePopulation, [&generator]() {  return generator(); });
    int i = 0;
    
    do {
        i++;
        // Give a score to each solutions
        for_each(solutions.begin(), solutions.end(), [&evaluator](Solution &s) { s.setScore(evaluator(s)); });

        vector<T> newSolutions = selector(solutions);
        
        sort(solutions.begin(), solutions.end());
        cout << "generation " << i << " : " << solutions[solutions.size() - 1] << "- " << solutions[solutions.size() - 1].getScore() << endl;
        
        // Add 30 solutions from a crossover
        transform(solutions.begin(), solutions.begin() + 30, back_inserter(newSolutions),
                  [&solutions, &crossover](const Solution &s) { return crossover(s, solutions[rand() % solutions.size()]); });
        
        // Add 30 solutions from a mutation
        transform(solutions.begin(), solutions.begin() + 30, back_inserter(newSolutions),
                  [&solutions, &mutator](const Solution& s) { return mutator(s); });
        
        // Add 20 solutions created randomly
        generate_n(back_inserter(newSolutions), 20,
                   [&generator]() { return generator(); });
        
        swap(solutions, newSolutions);
      
        // Give a score to each new solutions (needed for qualityLimit)
        for_each(solutions.begin(), solutions.end(), [&evaluator](Solution &s) { s.setScore(evaluator(s)); });
        
    } while (!stop(solutions));
    
    sort(solutions.begin(), solutions.end());
    result = solutions[solutions.size() - 1];
    return result;
};


template <typename T, typename G, typename E, typename S, typename C, typename M, typename F>
class GeneticAlgorithm {
private:
    G generator;
    E evaluator;
    S selector;
    C crossover;
    M mutator;
    F stop;
public:
    GeneticAlgorithm (G generator, E evaluator, S selector, C crossover, M mutator, F stop) {
        this->generator = generator;
        this->evaluator = evaluator;
        this->selector = selector;
        this->crossover = crossover;
        this->mutator = mutator;
        this->stop = stop;
    }
    
    T run(int sizePopulation) {
        return generate<T>(
                           this->generator,
                           this->evaluator,
                           this->selector,
                           this->crossover,
                           this->mutator,
                           this->stop,
                           sizePopulation);
    }
};




/********/
/* MAIN */
/********/


int main(int argc, const char * argv[]) {

    if (argc != 2)
        printUsage();

    try {
        chessboardSize = stoi(argv[1]);
    } catch (const invalid_argument &ia) {
        cerr << "Invalid argument : " << ia.what() << '\n';
        printUsage();
    }
    
    if (chessboardSize <= 3)
        printUsage();
    
    srand(time(0));

    maxCollisionsPossibles = (chessboardSize * 4) - 4;
    
    generator G;
    evaluator E;
    crossover C;
    mutator M;
    
    // Choose end criteria
    
    qualityLimit F;
    // flatResultsLimit F(10);
    // iterationLimit F(10);
    // miscLimit F;
    
    // Choose selector
    
    elitistSelector S;
    // rankSelector S;
    // noteSelector S(maxCollisionsPossible);
    // tournamentSelector S(20);
    
    GeneticAlgorithm<Solution, generator, evaluator, elitistSelector, crossover, mutator, qualityLimit> GA (G, E, S, C, M, F);
    
    cout << "Running..." << endl;
    Solution s = GA.run(100);
    cout << "solution : " << s << endl;
    cout << "score : " << s.getScore() << endl;
    displayChessboard(s);
    
    return 0;
}

void printUsage() {
    cout << "\nUSAGE";
    cout << "\n./NQueens <chessboard_size>";
    
    cout << "\n\nDESCRIPTION";
    cout << "\nGenetic algorithm that resolves the N-queens problem.";
    cout << "\nchessboard_size must be a natural number superior to 3." << endl;
    exit(0);
}

void displayChessboard(const Solution &s) {
    vector<int> solution = s.getQueensPosition();
    int k = chessboardSize;
    
    cout << endl;
    
    for (int i = 0; i <= (2 * chessboardSize); ++i) {
        if (i % 2 != 0) {
            for (int j = 0; j < chessboardSize; ++j) {
                if (j == 0)
                    cout << "\t";
                
                if (solution[j] == k)
                    cout << "o\t\t";
                else
                    cout << " \t\t";
            }
            k--;
        } else {
            cout << "\n";
            for (int j = 0; j <= chessboardSize; ++j) {
                if (j == 0 ) {
                    cout << "+\t\t";
                } else if (j == chessboardSize) {
                    cout << "+\n";
                } else {
                    cout << "-\t\t";
                }
            }
        }
    }
}
