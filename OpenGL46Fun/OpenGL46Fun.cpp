// OpenGL46Fun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <GLFW/glfw3.h>
#include <glad\glad.h>
#include <glm\glm.hpp>

#include "Window.h"

Window MainWindow;

int main()
{
	MainWindow = Window(900, 700);
	MainWindow.Initialise();

	while (!MainWindow.GetWindowShouldClose())
	{
		glClearColor(0.04f, 0.0f,0.1f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT); //| GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();


		//draw here.

		MainWindow.SwapBuffers();

	}


}
