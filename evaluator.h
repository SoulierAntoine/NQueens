//
//  evaluator.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef evaluator_h
#define evaluator_h

#include "global.h"

class evaluator {
public:
    int operator()(const Solution &s) {
        int nbCollisions = 0;
        std::vector<int> queensPosition = s.getQueensPosition();
        
        nbCollisions += checkRows(queensPosition);
        nbCollisions += checkDiagonals(queensPosition);
        
        return maxCollisionsPossibles - nbCollisions;
    }
private:
    int checkRows(std::vector<int> v) {
        int result = 0;
        
        for (int i = 0; i < v.size(); ++i) {
            if (i == v.size() - 1)
                break;
            
            for (int j = (i + 1); j < v.size(); ++j) {
                if (v[i] == v[j]) {
                    result++;
                    break;
                }
            }
        }
        
        return result;
    }
    
    int checkDiagonals(std::vector<int> v) {
        int result = 0;
        bool diagUp = false, diagDown = false;
        
        for (int i = 0; i < v.size(); ++i) {
            if (i == v.size() - 1)
                break;
            
            diagUp = false;
            diagDown = false;
            
            for (int j = (i + 1); j < v.size(); ++j) {
                int deltaRow = v[i] - v[j];
                int deltaCol = i - j;
                
                if (deltaRow == deltaCol) {
                    result++;
                    diagUp = true;
                }
                
                if (deltaRow == -(deltaCol)) {
                    result++;
                    diagDown = true;
                }
                
                if (diagUp && diagDown)
                    break;
            }
        }
        
        return result;
    }
};

#endif /* evaluator_h */
