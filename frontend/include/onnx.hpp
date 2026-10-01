#pragma once

#include <fstream>
#include <iostream>

#include "onnx/onnx.pb.h"
#include "graph.hpp"

class ONNXFrontend {
    public:
    photon_backend::ir::graph convertToPhotonIr(std::string modelPath){
        std::cout << "The model path is:" << modelPath << std::endl;
        std::ifstream input(modelPath, std::ios::binary);
        photon_backend::ir::graph photonIrGraph;

        if(!input){
            std::cerr << "Error opening the model file" << std::endl;
            return photonIrGraph;

        }
        onnx::ModelProto model;
    
        if (!model.ParseFromIstream(&input)) {
            std::cerr << "Error parsing ONNX file structural layout." << std::endl;
            return photonIrGraph;
        }

        const auto& onnxgraph = model.graph();
        std::cout << "node size is:" << std::to_string(onnxgraph.node_size()) << std::endl;

        for(int i =0; i< onnxgraph.node_size(); i++){
            const auto& node = onnxgraph.node(i);
            std::cout << "\n\nNode " << i << " with node type "<< node.op_type()<< " and name"<< node.name()<<"\n\n" ;
            ssize_t inputsize = node.input_size();
            for (int j=0; j< inputsize; j++) {
                std::cout << " node's  " << std::to_string(j) << "input\t"<< node.input(j) << std::endl;
            }
            ssize_t outputsize = node.output_size();
            for (int j =0; j< outputsize; j++) {
                std::cout << " node's " << std::to_string(j) <<"output\t"<< node.output(j)<< std::endl;
            }
            
        }

        
        
        
        return photonIrGraph;
    }
};