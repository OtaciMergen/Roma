#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* window = glfwCreateWindow(800, 600, "FirstStep", NULL, NULL);



int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}