//
//  Solution.cpp
//  NQueens
//
//  Created by Soulier Antoine on 13/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#include "Solution.h"

Solution::Solution() : score_(0) {}

Solution::Solution(std::vector<int> v) : queensPosition_(v), score_(0) {}

Solution::Solution(const Solution &s) : queensPosition_(s.queensPosition_), score_(s.score_) {}

int Solution::getScore() const {
    return this->score_;
}

void Solution::setScore(int s) {
    this->score_ = s;
}

void Solution::setAQueenPosition(int position, int index) {
    this->queensPosition_[index] = position;
}

void Solution::setQueensPosition(std::vector<int> queensPosition) {
    this->queensPosition_ = queensPosition;
}

int Solution::getAQueenPosition(int index) const {
    return this->queensPosition_[index];
}

std::vector<int> Solution::getQueensPosition() const {
    return this->queensPosition_;
}

std::ostream& operator<<(std::ostream& os, const Solution& s){
    std::vector<int> v = s.getQueensPosition();
    
    for (int i = 0; i < v.size(); ++i)
        os << v[i] << " ";
    
    return os;
}
