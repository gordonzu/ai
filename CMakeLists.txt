cmake_minimum_required(VERSION 3.9)
project(ai)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -O3")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

# Doxygen Build
# option(BUILD_DOC "Build Documentation" OFF)
#
# find_package(Doxygen)
# if(DOXYGEN_FOUND)
#     set(BUILD_DOC_DIR ${CMAKE_SOURCE_DIR}/build/docs)
#     if(NOT EXISTS ${BUILD_DOC_DIR})
#         file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
#     endif()
#
#     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#
#     message("Doxygen buld started")
#     add_custom_target(Doxygen ALL
#             COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#             COMMENT "Generating API documentation with Doxygen"
#             VERBATIM)
# else(DOXYGEN_FOUND)
#     message("Doxygen needs to be installed to generate the documentation.")
# endif(DOXYGEN_FOUND)
