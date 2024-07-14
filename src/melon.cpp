#include "melon.h"

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"uniform mat4 u_MVP;\n"
"uniform mat4 transform;\n"
"out vec2 TexCoord;\n"
"void main()\n"
"{\n"
"   gl_Position = u_MVP * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 TexCoord;\n"
"uniform vec4 color;\n"
"uniform sampler2D texture1;\n"
"void main()\n"
"{\n"
"   FragColor = texture(texture1, TexCoord) + color;\n"
"}\n\0";

namespace mln {
	master::~master() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void master::display(int width, int height, const char* title, int aspectRatio) {
		glfwInit();

		windowWidth = width;
		windowHeight = height;

		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window)
		{
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		glewInit();

		mainCamera.aspectRatio = aspectRatio;

		genBuffers();
	}
	void master::clear() {
		updateDeltaTime();
		glClearColor(BackgroundColor.x, BackgroundColor.y, BackgroundColor.z, BackgroundColor.w);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-mainCamera.position.x, -mainCamera.position.y, 0));
		glm::mat4 mvp = proj * view;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "u_MVP"), 1, GL_FALSE, &mvp[0][0]);
	}
	void master::update() {
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	void master::genBuffers() {
		// Vertices coordinates
		GLfloat vertices[] =
		{
			-0.5f, -0.5f, 0.0f,    1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,    1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,    0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,    0.0f, 1.0f
		};

		// Indices for vertices order
		GLuint indices[] =
		{
			0, 1, 3,
			1, 2, 3 
		};

		// allows for transparent images
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Generate Shader
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glUseProgram(shaderProgram);

		// Generate VAO,VBO,EBO
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// Create Camera
		if (mainCamera.aspectRatio == A3x2) {
			proj = glm::ortho(-1.5f, 1.5f, -1.0f, 1.0f, -1.0f, 1.0f);
		} else if (mainCamera.aspectRatio == A4x3) {
			proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
		} else if (mainCamera.aspectRatio == A5x3) {
			proj = glm::ortho(-2.5f, 2.5f, -1.5f, 1.5f, -1.0f, 1.0f);
		} else if (mainCamera.aspectRatio == A5x4) {
			proj = glm::ortho(-2.5f, 2.5f, -2.0f, 2.0f, -1.0f, 1.0f);
		} else if (mainCamera.aspectRatio == A16x9) {
			proj = glm::ortho(-8.0f, 8.0f, -4.5f, 4.5f, -1.0f, 1.0f);
		} else if (mainCamera.aspectRatio == A16x10) {
			proj = glm::ortho(-8.0f, 8.0f, -5.0f, 5.0f, -1.0f, 1.0f);
		}
	}
	bool master::checkClosedState() {
		return glfwWindowShouldClose(window);
	}
	void master::changeDisplaySize(int x, int y) {
		glfwSetWindowSize(window, x, y);
		glViewport(0, 0, x, y);
	}
	void master::changeDisplayTitle(const char* title) {
		glfwSetWindowTitle(window, title);
	}
	void master::createQuad(Vec2 position, float rotation, Vec2 scale, Vec4 color) {
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(position.x, position.y, 0.0f));
		transform = glm::rotate(transform, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		transform = glm::scale(transform, glm::vec3(scale.x, scale.y, 0.0));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transform"), 1, GL_FALSE, glm::value_ptr(transform));

		glUniform4f(glGetUniformLocation(shaderProgram, "color"), color.x, color.y, color.z, 1.0f);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
	}
	void master::changeAspectRatio(int aspectRatio) {
		mainCamera.aspectRatio = aspectRatio;

		// Create Camera
		if (mainCamera.aspectRatio == A3x2) {
			proj = glm::ortho(-1.5f, 1.5f, -1.0f, 1.0f, -1.0f, 1.0f);
		}
		else if (mainCamera.aspectRatio == A4x3) {
			proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
		}
		else if (mainCamera.aspectRatio == A5x3) {
			proj = glm::ortho(-2.5f, 2.5f, -1.5f, 1.5f, -1.0f, 1.0f);
		}
		else if (mainCamera.aspectRatio == A5x4) {
			proj = glm::ortho(-2.5f, 2.5f, -2.0f, 2.0f, -1.0f, 1.0f);
		}
		else if (mainCamera.aspectRatio == A16x9) {
			proj = glm::ortho(-8.0f, 8.0f, -4.5f, 4.5f, -1.0f, 1.0f);
		}
		else if (mainCamera.aspectRatio == A16x10) {
			proj = glm::ortho(-8.0f, 8.0f, -5.0f, 5.0f, -1.0f, 1.0f);
		}
	}
	void master::setFullScreenState(bool state) {
		if (state == true) {
			glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), windowWidth/2, windowHeight, windowWidth, windowHeight, 0);
		}
		else if (state == false) {
			glfwSetWindowMonitor(window, NULL, windowWidth/2, windowHeight/2, windowWidth, windowHeight, 0);
		}
	}
	Vec2 master::getScreenSize() {
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		Vec2 windowSize = { mode->width, mode->height };
		return windowSize;
	}
	float lastFrame = 0;
	void master::updateDeltaTime() {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}
	bool master::getKeyPressed(int key) {
		int state = glfwGetKey(window, key);
		if (state == GLFW_PRESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool master::getKeyReleased(int key) {
		int state = glfwGetKey(window, key);
		if (state == GLFW_RELEASE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}