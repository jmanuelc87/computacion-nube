cmake_minimum_required(VERSION 3.18)
project(openmp_task)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


find_package(OpenMP REQUIRED)


add_executable(hello_world)

target_include_directories(hello_world PRIVATE include)

target_sources(hello_world PRIVATE src/hello_world.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(hello_world PUBLIC OpenMP::OpenMP_CXX)
endif()


add_executable(pi)

target_include_directories(pi PRIVATE include)

target_sources(pi PRIVATE src/pi.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(pi PUBLIC OpenMP::OpenMP_CXX)
endif()


add_executable(pi_roundrobin)

target_include_directories(pi_roundrobin PRIVATE include)

target_sources(pi_roundrobin PRIVATE src/pi_roundrobin.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(pi_roundrobin PUBLIC OpenMP::OpenMP_CXX)
endif()



add_executable(pi_parallelfor)

target_include_directories(pi_parallelfor PRIVATE include)

target_sources(pi_parallelfor PRIVATE src/pi_parallelfor.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(pi_parallelfor PUBLIC OpenMP::OpenMP_CXX)
endif()


add_executable(sum_arrays)

target_include_directories(sum_arrays PRIVATE include)

target_sources(sum_arrays PRIVATE src/sum_arrays.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(sum_arrays PUBLIC OpenMP::OpenMP_CXX)
endif()


add_executable(mandel)

target_include_directories(mandel PRIVATE include)

target_sources(mandel PRIVATE src/mandel.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(mandel PUBLIC OpenMP::OpenMP_CXX)
endif()


add_executable(linked)

target_include_directories(linked PRIVATE include)

target_sources(linked PRIVATE src/linked.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(linked PUBLIC OpenMP::OpenMP_CXX)
endif()


add_executable(prod_cons)

target_include_directories(prod_cons PRIVATE include)

target_sources(prod_cons PRIVATE src/prod_cons.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(prod_cons PUBLIC OpenMP::OpenMP_CXX)
endif()


add_library(random src/random.cpp)

add_executable(pi_mc)

target_include_directories(pi_mc PRIVATE include)

target_sources(pi_mc PRIVATE src/pi_mc.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(pi_mc PUBLIC OpenMP::OpenMP_CXX random)
endif()