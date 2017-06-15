//
//  tournamentSelector.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef tournamentSelector_h
#define tournamentSelector_h

class tournamentSelector {
private:
    int nbRandomSelected_;
public:
    tournamentSelector(int i = 20) {
        nbRandomSelected_ = i;
    }
    std::vector<Solution> operator()(const std::vector<Solution> p) {
        std::vector<Solution> newPopulation;
        std::vector<Solution> randomPopulation;
        
        // Create a p.size() / 2 size newPopulation
        for (int j = 0; j < p.size() - 2; ++j) {
            
            // Choose nbRandomSelected_ solution randomly from p (depending on the size of p, can be several times the same)
            for (int i = 0; i < nbRandomSelected_; ++i) {
                int rnd = rand() % (p.size() - 1);
                randomPopulation.push_back(p[rnd]);
            }
            
            // Sort the nbRandomSelected solutions
            sort(randomPopulation.begin(), randomPopulation.end());
            
            // Add the best solution to newPopulation
            newPopulation.push_back(randomPopulation[randomPopulation.size() - 1]);
        }
        
        return newPopulation;
    }
};

#endif /* tournamentSelector_h */
