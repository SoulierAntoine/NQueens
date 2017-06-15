//
//  iterationLimit.h
//  NQueens
//
//  Created by Soulier Antoine on 20/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef iterationLimit_h
#define iterationLimit_h

class iterationLimit {
private:
    int iterationsMax_;
    int iterationCourante_ = 0;
public:
    iterationLimit(int i = 10) {
        iterationsMax_ = i;
    }
    bool operator()(const std::vector<Solution> p) {
        iterationCourante_++;
        
        return (iterationCourante_ >= iterationsMax_);
    }
};

#endif /* iterationLimit_h */
