add_library(ir)

target_include_directories(
    ir
    PUBLIC
        include
)

target_sources(
    ir
    PRIVATE
        src/temp.cpp   
)
