#pragma once


#include <string>
#include <memory>

#include "shape.hpp"
#include "type.hpp"
#include "node.hpp"

namespace photon_backend::ir {

class Value : Node{
    Shape shape;
    Type d_type;
    Node defining_op;
    std::vector<Node> users;

};
}
