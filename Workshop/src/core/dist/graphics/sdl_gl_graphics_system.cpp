#include "sdl_gl_graphics_system.h"

#include "../system/sdl_gl_window.h"

#include <cstdio>
#include <glad/glad.h>

Workshop::SDL_GL_GraphicsSystem::SDL_GL_GraphicsSystem() :
win(nullptr)
{
}

void Workshop::SDL_GL_GraphicsSystem::InitializeGraphicsSystem(const WinInfo& window_info_)
{
	window_system = std::make_unique<SDL_GL_Window>();
	
	// Init OpenGL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL init error\n");
		return;
	}

	// Init OpenGL
	if (SDL_GL_LoadLibrary(nullptr) == -1)
	{
		printf("SDL OpenGL init error\n");
		return;
	}

	// OpenGL 4.5
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	// Use core profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Misc
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Enable double buffer
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);  // Enable 24bit z buffer
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	window_system->CreateWindow(window_info_);
	window_system->SetThisWindowAsContext();

	win = static_cast<SDL_GL_Window*>(window_system.get());  // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

	// Load GLAD
	if (!gladLoadGLLoader(static_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
	{
		printf("%s \n", "Failed to initialize GLAD");
		return;
	}

	glEnable(GL_DEPTH_TEST);
}

void Workshop::SDL_GL_GraphicsSystem::BeginRenderProtocol()
{
	SDL_PollEvent(&sdl_event);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Workshop::SDL_GL_GraphicsSystem::EndRenderProtocol()
{
	SDL_GL_SwapWindow(win->window.get());
}

void Workshop::SDL_GL_GraphicsSystem::StopGraphicsSystem()
{
	SDL_Quit();
}
