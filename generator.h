//
//  generator.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef generator_h
#define generator_h

#include "global.h"

class generator {
public:
    Solution operator()() {
        int totalGenes = chessboardSize;
        std::deque<int> genes (totalGenes);
        
        int indexGenes = 1;
        generate(genes.begin(), genes.end(), [&indexGenes] () { return indexGenes++; });
        std::vector<int> queensPosition;
        
        for (int j = 0; j < chessboardSize; ++j) {
            int geneIndex = rand() % totalGenes;
            queensPosition.push_back(genes[geneIndex]);
            
            // Prevent from having duplicates
            genes.erase(genes.begin() + geneIndex);
            totalGenes--;
        }
        
        Solution s(queensPosition);
        return s;
    }
};

#endif /* generator_h */
