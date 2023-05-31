#ifndef MELON_H
#define MELON_H

#define 	KEY_UNKNOWN   -1
#define 	KEY_SPACE   32
#define 	KEY_APOSTROPHE   39 /* ' */
#define 	KEY_COMMA   44 /* , */
#define 	KEY_MINUS   45 /* - */
#define 	KEY_PERIOD   46 /* . */
#define 	KEY_SLASH   47 /* / */
#define 	KEY_0   48
#define 	KEY_1   49
#define 	KEY_2   50
#define 	KEY_3   51
#define 	KEY_4   52
#define 	KEY_5   53
#define 	KEY_6   54
#define 	KEY_7   55
#define 	KEY_8   56
#define 	KEY_9   57
#define 	KEY_SEMICOLON   59 /* ; */
#define 	KEY_EQUAL   61 /* = */
#define 	KEY_A   65
#define 	KEY_B   66
#define 	KEY_C   67
#define 	KEY_D   68
#define 	KEY_E   69
#define 	KEY_F   70
#define 	KEY_G   71
#define 	KEY_H   72
#define 	KEY_I   73
#define 	KEY_J   74
#define 	KEY_K   75
#define 	KEY_L   76
#define 	KEY_M   77
#define 	KEY_N   78
#define 	KEY_O   79
#define 	KEY_P   80
#define 	KEY_Q   81
#define 	KEY_R   82
#define 	KEY_S   83
#define 	KEY_T   84
#define 	KEY_U   85
#define 	KEY_V   86
#define 	KEY_W   87
#define 	KEY_X   88
#define 	KEY_Y   89
#define 	KEY_Z   90
#define 	KEY_LEFT_BRACKET   91 /* [ */
#define 	KEY_BACKSLASH   92 /* \ */
#define 	KEY_RIGHT_BRACKET   93 /* ] */
#define 	KEY_GRAVE_ACCENT   96 /* ` */
#define 	KEY_WORLD_1   161 /* non-US #1 */
#define 	KEY_WORLD_2   162 /* non-US #2 */
#define 	KEY_ESCAPE   256
#define 	KEY_ENTER   257
#define 	KEY_TAB   258
#define 	KEY_BACKSPACE   259
#define 	KEY_INSERT   260
#define 	KEY_DELETE   261
#define 	KEY_RIGHT   262
#define 	KEY_LEFT   263
#define 	KEY_DOWN   264
#define 	KEY_UP   265
#define 	KEY_PAGE_UP   266
#define 	KEY_PAGE_DOWN   267
#define 	KEY_HOME   268
#define 	KEY_END   269
#define 	KEY_CAPS_LOCK   280
#define 	KEY_SCROLL_LOCK   281
#define 	KEY_NUM_LOCK   282
#define 	KEY_PRINT_SCREEN   283
#define 	KEY_PAUSE   284
#define 	KEY_F1   290
#define 	KEY_F2   291
#define 	KEY_F3   292
#define 	KEY_F4   293
#define 	KEY_F5   294
#define 	KEY_F6   295
#define 	KEY_F7   296
#define 	KEY_F8   297
#define 	KEY_F9   298
#define 	KEY_F10   299
#define 	KEY_F11   300
#define 	KEY_F12   301
#define 	KEY_F13   302
#define 	KEY_F14   303
#define 	KEY_F15   304
#define 	KEY_F16   305
#define 	KEY_F17   306
#define 	KEY_F18   307
#define 	KEY_F19   308
#define 	KEY_F20   309
#define 	KEY_F21   310
#define 	KEY_F22   311
#define 	KEY_F23   312
#define 	KEY_F24   313
#define 	KEY_F25   314
#define 	KEY_KP_0   320
#define 	KEY_KP_1   321
#define 	KEY_KP_2   322
#define 	KEY_KP_3   323
#define 	KEY_KP_4   324
#define 	KEY_KP_5   325
#define 	KEY_KP_6   326
#define 	KEY_KP_7   327
#define 	KEY_KP_8   328
#define 	KEY_KP_9   329
#define 	KEY_KP_DECIMAL   330
#define 	KEY_KP_DIVIDE   331
#define 	KEY_KP_MULTIPLY   332
#define 	KEY_KP_SUBTRACT   333
#define 	KEY_KP_ADD   334
#define 	KEY_KP_ENTER   335
#define 	KEY_KP_EQUAL   336
#define 	KEY_LEFT_SHIFT   340
#define 	KEY_LEFT_CONTROL   341
#define 	KEY_LEFT_ALT   342
#define 	KEY_LEFT_SUPER   343
#define 	KEY_RIGHT_SHIFT   344
#define 	KEY_RIGHT_CONTROL   345
#define 	KEY_RIGHT_ALT   346
#define 	KEY_RIGHT_SUPER   347
#define 	KEY_MENU   348
#define 	KEY_LAST   KEY_MENU

#define A3x2 0
#define A4x3 1
#define A5x3 2
#define A5x4 3
#define A16x9 4
#define A16x10 5

#define GLEW_STATIC

#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb/stb_image.h>

#include "math.h"
#include "texture.h"

namespace mln {
	class master {
	private:
		struct camera {
			Vec2 position;
			int aspectRatio;
		};
		glm::mat4 proj;
		GLFWwindow* window;
		int windowWidth;
		int windowHeight;
		GLuint VAO, VBO, EBO;
		void genBuffers();
		void updateDeltaTime();
	public:

		GLuint shaderProgram;

		Vec4 BackgroundColor = { 0.0f, 0.0f, 0.0f, 0.0f };
		camera mainCamera;
		float deltaTime;

		~master();

		void display(int width, int height, const char* title, int aspectRatio);
		void clear();
		void update();
		bool checkClosedState();
		void changeDisplaySize(int x, int y);
		void changeDisplayTitle(const char* title);
		void changeAspectRatio(int aspectRatio);
		void setFullScreenState(bool state);
		Vec2 getScreenSize();

		void createQuad(Vec2 position, float rotation, Vec2 scale, Vec4 color = { 0.0f, 0.0f, 0.0f, 1.0f });

		bool getKeyPressed(int key);
		bool getKeyReleased(int key);
	};
}

#endif