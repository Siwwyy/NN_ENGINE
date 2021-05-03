cmake_minimum_required(VERSION 3.12)
# ----------------------------------------------------------------------------
#  Root CMake file
#
#
# ----------------------------------------------------------------------------


# ----------------------------------------------------------------------------

project(NN_ENGINE VERSION 1.0.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
	MathLib
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)
