cmake_minimum_required(VERSION 3.0.0)
project(trinity VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

add_library(trinity INTERFACE)
target_sources(trinity
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/trinity.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/initializer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/ones_like.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/random_like.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/zeros_like.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/add.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/divide.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/dot.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/multiply.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/subtract.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/sum.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/transpose.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ndarray/matrix.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ndarray/ndarray.h
)
target_include_directories(trinity INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
