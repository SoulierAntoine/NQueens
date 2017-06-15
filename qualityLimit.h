//
//  qualityLimit.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef qualityLimit_h
#define qualityLimit_h

#include "global.h"

class qualityLimit {
public:
    bool operator()(const std::vector<Solution> p) {
        for (int i = 0; i < p.size(); ++i) {
            if (p[i].getScore() == maxCollisionsPossibles)
                return true;
        }
        
        return false;
    }
};

#endif /* qualityLimit_h */
