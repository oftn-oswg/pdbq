#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

static void error (int error, const char *desc) {
	fprintf (stderr, "GLFW: %s\n", desc);
}

int main (void) {
	GLenum err;
	GLFWwindow *window;

	glfwSetErrorCallback (error);
	
	if (!glfwInit ()) {
		return EXIT_FAILURE;
	}

	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 1);
	// Context profiles only exist for OpenGL version 3.2 and above.
	// glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow (640, 480, "Untitled Window", NULL, NULL);
	if (!window) {
		glfwTerminate ();
		return EXIT_FAILURE;
	}

	err = glewInit ();
	if (err != GLEW_OK) {
		fprintf (stderr, "GLEW: %s\n", glewGetErrorString(err));
		glfwTerminate ();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent (window);

	while (!glfwWindowShouldClose (window)) {
		/* Begin rendering code */
		float ratio;
		int width, height;

		glfwGetFramebufferSize (window, &width, &height);
		ratio = width / (float) height;

		glViewport (0, 0, width, height);
		glClearColor (1.f, 1.f, 1.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT);

		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		glOrtho (-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode (GL_MODELVIEW);

		glLoadIdentity ();
		glRotatef ((float) glfwGetTime () * 50.f, 0.f, 0.f, 1.f);

		glBegin (GL_TRIANGLES);
		glColor3f (1.f, 0.f, 0.f);
		glVertex3f (-0.6f, -0.4f, 0.f);
		glColor3f (0.f, 1.f, 0.f);
		glVertex3f (0.6f, -0.4f, 0.f);
		glColor3f (0.f, 0.f, 1.f);
		glVertex3f (0.f, 0.6f, 0.f);
		glEnd ();
		/* End rendering code */

		glfwSwapBuffers (window);
		glfwPollEvents ();
	}

	glfwDestroyWindow (window);
	glfwTerminate ();

	return EXIT_SUCCESS;
}
