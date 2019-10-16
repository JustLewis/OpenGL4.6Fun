#include "Window.h"

Window::Window()
{
	WindowWidth = 600;
	WindowHeight = 400;

	BufferWidth = 0;
	BufferHeight = 0;
}

Window::Window(GLuint WindowWidthIn, GLuint WindowHeightIn)
{
	WindowWidth = WindowWidthIn;
	WindowHeight = WindowHeightIn;

	BufferWidth = 0;
	BufferHeight = 0;
}

Window::~Window()
{
	glfwDestroyWindow(MainWindow);
	glfwTerminate();
}

int Window::Initialise()
{
	if (!glfwInit())
	{
		printf("Failed to initialise GLFW");
		return 1;
	}

	MainWindow = glfwCreateWindow(WindowWidth, WindowHeight, "Fun Window", nullptr, nullptr);

	if (!MainWindow) 
	{
		printf("Failed to initialise main window.");
		glfwTerminate();
		return 1;
	}

	glfwGetFramebufferSize(MainWindow, &BufferWidth, &BufferHeight);

	glfwMakeContextCurrent(MainWindow);
	glfwSetWindowUserPointer(MainWindow, this);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD");
		glfwDestroyWindow(MainWindow);
		glfwTerminate();
		return 1;
	}

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major); //setting version of Opengl
	glGetIntegerv(GL_MINOR_VERSION, &minor); //setting version of Opengl
	printf("GL Version (integer) : %d.%d\n", major, minor);

	glfwWindowHint(GLFW_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_VERSION_MINOR, minor);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	//glEnable(GL_DEPTH_TEST);
	
	glViewport(0, 0, BufferWidth, BufferHeight);

	return 0;
}
