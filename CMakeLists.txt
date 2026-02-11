cmake_minimum_required(VERSION 3.23)
project(CourseSubjectDiagrams)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(d_SRC "./src")
set(d_LIB "./lib")

add_executable(coursediagramapp ${d_SRC}/main.cpp)
target_include_directories(coursediagramapp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${d_LIB}/)

########################

# LIBRARIES 
  add_library(Application ${CMAKE_CURRENT_SOURCE_DIR} ${d_SRC}/Application.cpp)
  #add_library(...)

  # glad
  set(d_GLAD ./deps/glad)
  add_library(glad ${CMAKE_CURRENT_SOURCE_DIR} ${d_GLAD}/src/glad.c)
  target_include_directories(Application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${d_GLAD}/include/)

  # GLFW
  find_package(glfw3 3.4 REQUIRED)
  target_link_libraries(coursediagramapp glfw)
  find_package(OpenGL REQUIRED)
  target_link_libraries(coursediagramapp OpenGL::GL)

# SOURCES
  target_link_libraries(coursediagramapp Application)
  #target_link_libraries(...)

target_sources(coursediagramapp
  PRIVATE
  ${d_SRC}/main.cpp
  ${d_SRC}/Application.cpp
  ${d_GLAD}/src/glad.c
)
