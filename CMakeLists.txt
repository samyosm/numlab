cmake_minimum_required(VERSION 3.15)
project(NumericalLab LANGUAGES C CXX Fortran)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-O3 -march=native -ffast-math -Wall -Wextra)
endif()

function(add_lab_test name source_file)
    add_executable(${name} ${source_file})
    target_link_libraries(${name} PRIVATE numlab_c numlab_fortran)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

include_directories(include src)

add_library(numlab
    src/root_solver/root_solver.hpp
    src/root_solver/regula_falsi.cpp
    src/root_solver/fixed_point.cpp
    src/root_solver/bisection.cpp 
    src/integration/integration.hpp
    src/integration/riemann.cpp
)

add_executable(run_lab src/main.cpp)
target_link_libraries(run_lab PRIVATE numlab)


# ###
# ### Benchmarking
# ###
#
# add_executable(bench_bisection benchmarks/bench_bisection.cpp)
# target_link_libraries(bench_bisection PRIVATE numlab_core)


# ###
# ### Testing
# ###

enable_testing()
add_subdirectory(tests)
