//
//  miscLimit.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef miscLimit_h
#define miscLimit_h

#include "flatResultsLimit.h"
#include "qualityLimit.h"
#include "iterationLimit.h"

class miscLimit {
public:
    bool operator()(const std::vector<Solution> p) {
        if (frl(p) && ql(p) && il(p))
            return true;
        
        return false;
    }
private:
    flatResultsLimit frl;
    qualityLimit ql;
    iterationLimit il;
};

#endif /* miscLimit_h */
