//
//  Solution.hpp
//  NQueens
//
//  Created by Soulier Antoine on 13/07/2016.
//  Copyright © 2016 Soulier Antoine. All rights reserved.
//

#ifndef Solution_h
#define Solution_h

#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<int> queensPosition_;
    int score_;
public:
    Solution();
    Solution(std::vector<int>);
    Solution(const Solution &s);

    int getScore() const;
    void setScore(int s);
    
    int getAQueenPosition(int index) const;
    std::vector<int> getQueensPosition() const;
    
    void setAQueenPosition(int position, int index);
    void setQueensPosition(std::vector<int> queensPosition);
    
    bool operator<(const Solution& s)const {
        return score_ < s.score_;
    }
    
    bool operator>(const Solution& s)const {
        return s < (*this);
    }
    
    bool operator<=(const Solution& s)const {
        return !((*this) > s);
    }
    
    bool operator>=(const Solution& s)const {
        return !((*this) < s);
    }
    
    bool operator==(const Solution& s)const {
        return ((*this) >= s) && ((*this) <= s);
    }
    
    bool operator!=(const Solution& s)const {
        return ((*this) > s) || ((*this) < s);
    }
};

std::ostream& operator<<(std::ostream& os, const Solution& s);


#endif /* Solution_h */
