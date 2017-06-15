//
//  flatResultsLimit.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef flatResultsLimit_h
#define flatResultsLimit_h

class flatResultsLimit {
private:
    int checkLastSolutions_;
public:
    flatResultsLimit(int i = 10) {
        checkLastSolutions_ = i;
    }
    bool operator()(std::vector<Solution> p) {
        sort(p.begin(), p.end());
        int note = p[p.size() - 1].getScore(), plateau = 0;
        // Check 3 lasts solutions, if they're all the same, stop algorithm.
        for (size_t i = p.size() - 1; i >= p.size() - checkLastSolutions_; --i) {
            if (p[i].getScore() == note)
                plateau++;
        }
        
        if (plateau >= checkLastSolutions_)
            return true;
        
        return false;
    }
};

#endif /* flatResultsLimit_h */
