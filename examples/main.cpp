#include <onnx.hpp>
#include <graph.hpp>
int main(){
    ONNXFrontend onnxparser;
    std::string path = "/home/test/Desktop/photon-inference-backend/examples/mnist.onnx";
    photon_backend::ir::graph graph =  onnxparser.convertToPhotonIr(path);
    return 0;
}