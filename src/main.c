#include <stdio.h>
#include <GLFW/glfw3.h>

int main(void) {
    printf("Game Engine - Week 0 Complete!\n");
    
    // Test GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
    
    printf("GLFW initialized successfully!\n");
    glfwTerminate();
    
    return 0;
}
