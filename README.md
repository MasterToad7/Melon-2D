# Melon 2D
A simple 2D graphics framework created by Blast Shield Studios that can be use to create simple 2D applications and games.

# How to Install/Compile
Download melon 2D to what ever directory you want in your project then add this to your CMakeLists file
```
add_subdirectory({PATH_TO_MELON2D}/Melon2D)
target_link_libraries({YOUR_PROJECT_NAME} melon)
target_include_directories(test PRIVATE {PATH_TO_MELON2D}/Melon2D/src)
```
Then just build cmake
```
mkdir build
cd build
cmake ../
cmake --build .
```

# What Comes Next
A remake of the entirety of Melon 2D is planned and is already being worked on. Because of this there will be no updates to Melon 2D for the time being. This remake of Melon 2D is going to be coded in C instead of C++. A Melon game engine is also panned and will feature lua as the scripting language.
