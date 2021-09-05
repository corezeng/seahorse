project(seahorse)
cmake_minimum_required(VERSION 3.2)

set(CXX_STANDARD 14)
set(COMPILE_FLAGS -lpthread -O3 -Wall -fPIC)

aux_source_directory(./src/base src_list)
aux_source_directory(./src/network src_list)
aux_source_directory(./src/algorithm src_list)

add_library(seahorse ${src_list})

set_target_properties(seahorse PROPERTIES output_name "seahorse")

install(DIRECTORY src/ DESTINATION include/seahorse FILES_MATCHING PATTERN "*.h")
install(TARGETS seahorse DESTINATION lib)