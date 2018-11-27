cmake_minimum_required(VERSION 3.12)
project(IOptimizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(IOptimizer main.cpp Classes/User.cpp Classes/User.h Classes/Database.cpp Classes/Database.h Classes/ProductIN.cpp Classes/ProductIN.h Classes/ProductOUT.cpp Classes/ProductOUT.h)