#pragma once

#include <string>

enum class NodeType {
    Operation,
    Values
};

class Node{
    public:
    const std::string getName() const {
        return name;
    }

    const NodeType getType() const {
        return type;
    }
    
    private:
    std::string name;
    NodeType type;
    

};
