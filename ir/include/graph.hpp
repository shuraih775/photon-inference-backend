#pragma once
#include "node.hpp"
#include <string>
namespace photon_backend::ir {

class graph{
    Node root;
    std::string name;
};
}