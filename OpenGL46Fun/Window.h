#pragma once
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Window
{
public:
	Window();
	Window(GLuint WindowWidthIn, GLuint WindowHeightIn);

	~Window();

	int Initialise();

	GLuint GetBufferHeight() { return BufferHeight; }
	GLuint GetBufferWidth() { return BufferWidth; }
	bool GetWindowShouldClose() { return glfwWindowShouldClose(MainWindow); }

	void SwapBuffers() { glfwSwapBuffers(MainWindow); }

private:

	GLFWwindow* MainWindow;

	GLuint WindowHeight, WindowWidth;

	GLint BufferHeight, BufferWidth;

	
};

