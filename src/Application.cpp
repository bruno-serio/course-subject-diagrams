#include "../lib/Application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* s_window;

static int terminate(int exitCode);
static bool windowShouldClose(GLFWwindow* window);

int Application::init() {
        if (!glfwInit()) { return -1; }

        s_window = glfwCreateWindow(600, 400, "Window", NULL, NULL);
        if (!s_window) { return terminate(-1); }

        // set this as the active window
        glfwMakeContextCurrent(s_window);

        gladLoadGL();
        glClearColor(0.1f, 0.05f, 0.2f, 1.f); // placeholder
        return 0;
}

int Application::run() {

        while (1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glfwSwapBuffers(s_window);

                if (windowShouldClose(s_window)) {
                        return terminate(0);
                }

                glfwWaitEvents();
        }
}

int terminate(int exitCode) {
        glfwTerminate();
        return exitCode;
}

bool windowShouldClose(GLFWwindow* window) {
        return glfwGetKey(window, GLFW_KEY_ESCAPE) || glfwWindowShouldClose(window);
}
