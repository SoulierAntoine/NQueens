//
//  mutator.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef mutator_h
#define mutator_h

#include "global.h"

class mutator {
public:
    Solution operator()(const Solution &s) {
        Solution sMuted = s;
        
        int mutatedQueenIndex = rand() % chessboardSize;
        int mutatedQueen = sMuted.getAQueenPosition(mutatedQueenIndex);
        
        int totalGenes = chessboardSize;
        // So that we get a value between 1 and 8
        mutatedQueen = (rand() % totalGenes) + 1;
        
        sMuted.setAQueenPosition(mutatedQueen, mutatedQueenIndex);
        
        return sMuted;
    }
};

#endif /* mutator_h */
