#include "main_scene.h"

#include <cstdio>
#include <glad/glad.h>

// Derp scene
// Try not to do this

const char* vertex_shader_source = "#version 450 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragment_shader_source = "#version 450 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

float trig_vertices[] =
{
	-0.5f, -0.5f, 0.0f, // vec3 Point A
	 0.5f, -0.5f, 0.0f, // vec3 Point B
	 0.0f,  0.5f, 0.0f	// vec3 Point C
};

GLuint vao;
GLuint vbo;
GLint shader_program;

void MainScene::InitializeScene()
{
	printf("Main Scene");

	// OpenGL Object section
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);

		// Vbo data
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(trig_vertices), trig_vertices, GL_STATIC_DRAW);

		// Layout pos
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// Unbind
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
		glBindVertexArray(NULL);
	}

	// Shader section
	{
		// VS
		int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);

		// FS
		int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);

		// link shaders
		shader_program = glCreateProgram();
		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);

		// Delete shader
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
	}
}

void MainScene::UpdateLogic()
{
}

void MainScene::UpdateRender()
{
	// Shader
	glUseProgram(shader_program);

	// Uniform in future
	// Texture in future

	// Render
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(NULL);
}

void MainScene::EndScene()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}
