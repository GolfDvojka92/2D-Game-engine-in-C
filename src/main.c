#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define ERROR_EXIT(...) fprintf(stderr, __VA_ARGS__); exit(1)
#define ERROR_RETURN(R, ...) fprintf(stderr, __VA_ARGS__); return R

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    (void)window;
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(void) {
    // initializing GLFW
    if (!glfwInit()) {
        ERROR_EXIT("Failed to initialize GLFW\n");
    }
    // GLFW settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFW window creation
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Blank OpenGL window", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        ERROR_EXIT("Failed to create GLFW window\n");
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // setting current context to the created window
    glfwMakeContextCurrent(window);

    // GLAD: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        ERROR_EXIT("Failed to initialize GLAD\n");
    }

    // render loop
    while (!glfwWindowShouldClose(window)) {
        // input processing
        processInput(window);

        // rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // GLFW: swap buffers and poll IO events, an event entails a key press/release, mouse movement etc.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // GLFW: terminate, this clears all allocated GLFW resources
    glfwTerminate();
    return 0;
}
