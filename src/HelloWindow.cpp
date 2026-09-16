#include <glad/glad.h> // Function address finder for openGL driver
#include <GLFW/glfw3.h> // Input, window parameters, context manager 
#include <iostream> 


void framebuffer_size_callback(GLFWwindow* window, int w, int h) //Resize window
{
	glViewport(0,0, w, h);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		glClearColor(0.2f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Creating window with glfw
	GLFWwindow* window = glfwCreateWindow(800, 600, "First Step", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//GLAD loads the correct adress according to OS
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initiliaze GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600); // viewport dimensions not the render res.

	// get called every resize of the window and binded to the framebuffer_size_callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Checks is closing executed
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glfwSwapBuffers(window); //changes colors, usually double buffer are commonly used front and back buffers check the notes for further info.
		glfwPollEvents(); //Events such as input,resize, subscribers etc.
	}

	glfwTerminate(); // cleans the all allocated memory


	return 0;
}