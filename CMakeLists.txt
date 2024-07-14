cmake_minimum_required(VERSION 3.10)
project(melon VERSION 1.0)

include(FetchContent)

FetchContent_Declare(glew
  # GIT_REPOSITORY https://github.com/edoren/glew.git
  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
  GIT_TAG        origin/master
)

FetchContent_MakeAvailable(glew)

if(NOT glew_POPULATED)
  FetchContent_Populate(glew)

  add_subdirectory(${glew_SOURCE_DIR} ${glew_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


FetchContent_Declare(glfw 
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(glfw)

FetchContent_Declare(glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(glm)

FetchContent_Declare(stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(stb)

add_library(melon STATIC src/melon.cpp src/math.cpp src/stb.cpp src/texture.cpp)
# target_include_directories(melon PUBLIC build/_deps/glew-src/include)
# target_include_directories(melon PUBLIC build/_deps/stb-src)

target_link_libraries(melon libglew_static)
target_link_libraries(melon glfw)
target_link_libraries(melon glm)
target_include_directories(melon PUBLIC ${stb_SOURCE_DIR})
find_package(OpenGL REQUIRED)
target_link_libraries(melon OpenGL::GL)
