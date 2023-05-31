# Getting Started
This is the official tutorial for Melon 2D. For more tutorials and information check out our youtube channel https://www.youtube.com/@blastshieldstudios
# How to Install
Visual studio 2022 is recommended. It could potentialy work on other versions of visual studio but it hasn't been tested yet.
1. Download Dependencies 
* ###### Melon 2D requires that glew, glfw, glm, and stb image are added to the project. The installation guide for those will not be included here but there will be a video on our youtube channel.
2. Download Melon 2D
* ###### Yet again I will not cover how to install melon 2D here but a video is available on our youtube channel

# Master Class
The master class allows us to create a display, control the camera, get user input, and render quads on screen.
```cpp
#include <mln/melon.h>

mln::master melon;
```
### Creating The Display
```cpp
melon.display(int width, int height, const char title, int aspectRatio);
```
#### Parameters
* _width_ sets the desired width of the display
* _height_ sets the desired height of the display
* _title_ sets the desired title of the display
* _aspectRatio_ sets the desired aspect ratio of the display
> **Note**
> the definitions for the aspect ratio are
> A3x2, A4x3, A5x3, A5x4, A16x9, A16x10
#### Example
```cpp
melon.display(1024, 576, "Melon", A16x9);
```
### Creating Display Loop
To prevent the display from closing immediately you can use a while loop.
```cpp
while (!melon.checkClosedState()) {
  melon.clear();
  
  melon.update();
}
```
* ```melon.checkClosedState()``` returns if the display was closed
* ```melon.clear()``` clears the display
* ```melon.update()``` updates the display
### Creating Quads
```cpp
void createQuad(Vec2 position, float rotation, Vec2 scale, Vec4 color);
```
#### Parameters
* _position_ sets the position of the quad
* _rotation_ sets the rotation of the quad
* _scale_ sets the scale of the quad
* _color_ sets the color of the quad
> _color_ is optional and is defaulted to { 0.0f, 0.0f, 0.0f, 1.0f }
> **Note**
> all colors in melon 2D are set up in RGBA format
#### Example
```cpp
while (!melon.checkClosedState()) {
  melon.clear();
  
    createQuad({ 2.0f, 2.0f }, 0.0f, { 3.0f, 3.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });
    
  melon.update();
}
```
> **Note**
> make sure that createQuad is in between ```melon.clear()``` and ```melon.update()```
### Adding Background Color
```cpp
melon.BackgroundColor = { float red, float green, float blue, float alpha };
```
> **Note**
> ```melon.BackgroundColor``` is considered a Vec4 just like all colors in melon 2D
### Getting User Input
```cpp
melon.getKeyPressed(int key)
```
> This function returns a boolean
#### Parameters
* _key_ key that you want to check
> **Note**
> you can find all key definitions in "input.md" 
#### Checking if Key is Released
```cpp
getKeyReleased(int key)
```
> This function returns a boolean
#### Parameters
* _key_ key that you want to check
> **Note**
> you can find all key definitions in "input.md" 
### Changing Display size
```cpp
changeDisplaySize(int width, int height);
```
#### Parameters
* _width_ new display width
* _height_ new display height
### Changing Display Title
```cpp
changeDisplayTitle(const char* title);
```
#### Parameters
* _title_ new display title
### Changing Aspect Ratio
```cpp
changeAspectRatio(int aspectRatio);
```
* _aspectRatio_ new display aspect ratio
### Full Screen
```cpp
setFullScreenState(bool state);
```
* _state_ controls weither the display should fullscreen or not
### How to retrieve
```cpp
getScreenSize();
```
> This function returns a Vec2
# Math Library
### Creating 2D Vectors
```cpp
mln::Vec2 vector2d = { float x, float y };
```
### Adding 2D Vectors
```cpp
AddVec2(Vec2 vector1, Vec2 vector2);
```
> This function returns a Vec2
#### Parameters
* _vector1_ first vector you would like to add
* _vector2_ second vector you would like to add
### Normalizing 2D Vectors
```cpp
mln::Vec2 vector2d = { 1.0f, 1.0f };
vector2d.Normalize();
```
### Creating 3D Vectors
```cpp
mln::Vec3 vector3 = { float x, float y, float z };
```
### Adding 3D Vectors
```cpp
AddVec3(Vec3 vector1, Vec3 vector2);
```
> This function returns a Vec3
#### Parameters
* _vector1_ first vector you would like to add
* _vector2_ second vector you would like to add
### Creating 4D Vectors
```cpp
mln::Vec4 vector4 = { float x, float y, float z, float w };
```
### Adding 4D Vectors
```cpp
AddVec4(Vec4 vector1, Vec4 vector2);
```
> This function returns a Vec4
#### Parameters
* _vector1_ first vector you would like to add
* _vector2_ second vector you would like to add

# Texture Class
### Creating Texture
```cpp
mln::texture img(const char* path, int filetype);
```
#### Parameters
* _path_ path to image
* _filetype_ type of image
> **Note**
> the definitions for filetype are
> PNG, JPG
### How to use texture
```cpp
mln::texture img("melonimage.png", PNG);

while (!melon.checkClosedState()) {
  melon.clear();
    
    img.activate();
    createQuad({ 2.0f, 2.0f }, 0.0f, { 3.0f, 3.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });
    
  melon.update();
}
```
> **Note**
> you must activate the texture before calling ```createQuad()``` if you want the quad to use the texture.
> Also if you activate another texture it will automatically deactivate the previous texture.
### How to deactivate texture
```cpp
mln::texture img("melonimage.png", PNG);

while (!melon.checkClosedState()) {
  melon.clear();
    
    img.activate();
    createQuad({ 2.0f, 2.0f }, 0.0f, { 3.0f, 3.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });
    img.deactivate();
    
  melon.update();
}
```
