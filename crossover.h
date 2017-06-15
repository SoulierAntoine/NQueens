//
//  crossover.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef crossover_h
#define crossover_h

#include "global.h"

class crossover {
public:
    Solution operator()(const Solution &s1, const Solution &s2) {
        std::vector<int> queensPosition;
        std::vector <int> v1 = s1.getQueensPosition();
        std::vector <int> v2 = s2.getQueensPosition();
        
        for (int i = 0; i < chessboardSize; ++i) {
            if (i % 2 == 0) {
                if (i > 0) {
                    // Avoid consecutive duplicates
                    if (v2[i - 1] == v1[i]) {
                        queensPosition.push_back(v2[i]);
                        continue;
                    }
                }
                queensPosition.push_back(v1[i]);
            } else {
                if (i > 0) {
                    if (v1[i - 1] == v2[i]) {
                        queensPosition.push_back(v1[i]);
                        continue;
                    }
                }
                queensPosition.push_back(v2[i]);
            }
        }
        
        Solution s(queensPosition);
        return s;
    }
};

#endif /* crossover_h */
