#pragma once

#include <vector>
#include <iostream>

namespace photon_backend::ir {

class Shape {
    public:
    Shape(int rank, std::vector<int> shape):
    rank(rank), shape(shape)
    {
        
    }

    const std::vector<int>& getShape() const {
        return shape;
    }

    const int getRank()const {
        return rank;
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape){
        std::string output;
        for (const auto &dim: shape.getShape()){
            output += std::to_string(dim) + "x";
        }
        os << output;
        return os;

    }
    
    private:
        int rank;
        std::vector<int> shape;
    
    
};
}

