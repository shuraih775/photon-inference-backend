#pragma once

#include "attribute.hpp"
#include <string>
#include "node.hpp"
#include "value.hpp"

namespace photon_backend::ir {
enum class OP_TYPE {
    MATMUL,
    BATCHNORM,
    RELU,
    CONV,
    PLUS,
    POOL,
    SUB, 
    MUL,
    DIV,
    GEMM
    
};

class Operation : Node {
    public:
        OP_TYPE op_type;
        Value input, output;
        Attribute attribute;

};
}
