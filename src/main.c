#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>

static void error(int error, const char *desc) {
	fprintf (stderr, "glfw: (#%d) %s\n", error, desc);
}

int main(void) {
	GLFWwindow *window;

	glfwSetErrorCallback (error);
	
	if (!glfwInit ()) {
		return EXIT_FAILURE;
	}

	window = glfwCreateWindow (640, 480, "Untitled Window", NULL, NULL);
	if (!window) {
		glfwTerminate ();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose (window)) {
		/* Render here */

		glfwSwapBuffers (window);
		glfwPollEvents ();
	}

	glfwDestroyWindow (window);
	glfwTerminate ();

	return EXIT_SUCCESS;
}
