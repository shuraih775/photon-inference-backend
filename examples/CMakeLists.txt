add_library(examples)
target_sources(examples
    PUBLIC
        main.cpp
)
target_link_libraries(examples
    PUBLIC
        frontend
        ir
)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE examples)