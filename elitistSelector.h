//
//  elitistSelector.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef elitistSelector_h
#define elitistSelector_h

class elitistSelector {
public:
    std::vector<Solution> operator()(std::vector<Solution> p) {
        std::vector<Solution> newPopulation;
        
        sort(p.begin(), p.end());
        for (size_t i = (p.size() - 1); i >= (p.size() / 2); --i)
            newPopulation.push_back(p[i]);
        
        return newPopulation;
    }
};

#endif /* elitistSelector_h */
