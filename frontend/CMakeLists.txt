add_library(frontend)

target_include_directories(
    frontend
    PUBLIC
        include
)

target_sources(
    frontend
    PRIVATE
        onnx.cpp   
)

find_package(Protobuf REQUIRED)

include(FetchContent)

FetchContent_Populate(
    onnx_source
    URL "https://github.com/onnx/onnx/archive/refs/heads/main.zip"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(GENERATED_PROTO_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated_proto")
file(MAKE_DIRECTORY "${GENERATED_PROTO_DIR}/onnx")

set(GENERATED_PROTO_SRCS "${GENERATED_PROTO_DIR}/onnx/onnx.pb.cc")
set(GENERATED_PROTO_HDRS "${GENERATED_PROTO_DIR}/onnx/onnx.pb.h")

set(ONNX_PROTO_FILE "${onnx_source_SOURCE_DIR}/onnx/onnx.proto")
if(NOT EXISTS ${ONNX_PROTO_FILE})
    set(ONNX_PROTO_FILE "${onnx_source_SOURCE_DIR}/onnx/onnx.in.proto")
endif()

add_custom_command(
    OUTPUT ${GENERATED_PROTO_SRCS} ${GENERATED_PROTO_HDRS}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
            --cpp_out=${GENERATED_PROTO_DIR}
            -I${onnx_source_SOURCE_DIR}
            ${ONNX_PROTO_FILE}
    DEPENDS ${ONNX_PROTO_FILE}
    COMMENT "Building isolated C++ protobuf bindings for onnx.proto"
    VERBATIM
)

add_library(onnx_proto_lib STATIC ${GENERATED_PROTO_SRCS} ${GENERATED_PROTO_HDRS})

target_include_directories(
    onnx_proto_lib 
    PUBLIC 
        ${GENERATED_PROTO_DIR} 
        ${Protobuf_INCLUDE_DIRS}
)

target_link_libraries(
    onnx_proto_lib 
    PUBLIC 
        ${Protobuf_LIBRARIES}
)

target_link_libraries(
    frontend
    PUBLIC
        ir
        onnx_proto_lib
)