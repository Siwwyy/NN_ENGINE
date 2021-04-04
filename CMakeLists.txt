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
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/Activation_Functions/Activation_Functions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Activation_Functions/Activation_Functions.hpp
)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME} MathLib)