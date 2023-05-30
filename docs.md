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
  melon.clear()
  
  melon.update();
}
```
* ```melon.checkClosedState``` returns if the display was closed
* ```melon.clear()``` clears the display
* ```melon.update()``` updates the display
### Creating Quads
```cpp
void createQuad(Vec2 position, float rotation, Vec2 scale, Vec3 color);
```
#### Parameters
