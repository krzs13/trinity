cmake_minimum_required(VERSION 3.0.0)
project(trinity VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(trinity INTERFACE)
target_sources(trinity
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/trinity.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/ones.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/random.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/initializers/zeros.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/add.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/divide.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/dot.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/multiply.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/subtract.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math_operations/sum.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ndarray/matrix.h
)
target_include_directories(trinity INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
