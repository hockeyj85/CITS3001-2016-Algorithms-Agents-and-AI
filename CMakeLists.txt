cmake_minimum_required(VERSION 3.3)
project(CITS3001)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

add_subdirectory(src/week1)
add_subdirectory(src/week2)
add_subdirectory(test)

# To use the sandbox file uncomment the following links
# add_executable(run_sandbox main.cpp)
# target_link_libraries(run_sandbox week2)

