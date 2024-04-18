#include <iostream>

#include "../include/TS.h"
#include "../include/shader_templates.h"

int main()
{
    TS t = TS(500, 500, "Test");
    
    Shader s = Shader((char*)vert_bouncy, (char*)frag_unlit);

    

	while (!glfwWindowShouldClose(t.window))
	{
		glClearColor(0, 0.2f, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(s);
        s.SetValue((float)glfwGetTime(), "time");
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(t.window);
		glfwPollEvents();
	}
}