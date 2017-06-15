//
//  noteSelector.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef noteSelector_h
#define noteSelector_h

#include "global.h"

class noteSelector {
public:
    std::vector<Solution> operator()(const std::vector<Solution> p) {
        std::vector<Solution> newPopulation;
        
        // Loop p.size() times, but the resulting population is unlikely this size.
        for (int i = 0; i < p.size(); ++i) {
            int rnd = 100 - (rand() % 100);
            
            // Get the score as a percentage
            int percentage = p[i].getScore() * 100 / maxCollisionsPossibles;
            
            if (percentage > rnd)
                newPopulation.push_back(p[i]);
        }
        
        return newPopulation;
    }
};

#endif /* noteSelector_h */
