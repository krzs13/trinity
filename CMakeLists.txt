cmake_minimum_required(VERSION 3.0.0)
project(trinity_main VERSION 0.1.0)
add_subdirectory(trinity)

include(CTest)
enable_testing()

add_executable(trinity_main main.cc)
target_link_libraries(trinity_main INTERFACE trinity)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
