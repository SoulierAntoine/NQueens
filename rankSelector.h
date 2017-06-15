//
//  rankSelector.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef rankSelector_h
#define rankSelector_h

class rankSelector {
public:
    std::vector<Solution> operator()(std::vector<Solution> p) {
        std::vector<Solution> newPopulation;
        std::vector<int> weight;
        sort(p.begin(), p.end());
        
        int k = 100;
        // weight<int> = 50, 25, 12, ... depending on the size of p
        for (int i = 0; i < p.size(); ++i) {
            weight.push_back(k / 2);
            k -= weight[i];
        }
        
        
        // Loop p.size() times, but the resulting population is unlikely this size.
        for (int i = 0; i < p.size(); ++i) {
            int rnd = 100 - (rand() % 100);
            
            if (weight[i] > rnd)
                newPopulation.push_back(p[i]);
        }
        
        return newPopulation;
    }
};

#endif /* rankSelector_h */
