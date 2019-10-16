#include "derp_engine.h"

#include <glad/glad.h>

void Workshop::DerpEngine::InitializeEngine(Distribution dist_, const WinInfo& window_info_)
{
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

	// Window
	window =
		SDL_CreateWindow
		(
			window_info_.title.c_str(),
			window_info_.x,
			window_info_.y,
			window_info_.width,
			window_info_.height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
		);

	// Set context
	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);

	// Load GLAD
	if (!gladLoadGLLoader(static_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
	{
		printf("%s \n", "Failed to initialize GLAD");
		return;
	}

	glEnable(GL_DEPTH_TEST);

	// Make scene system
	scene_system = std::make_unique<SceneSystem>();
}

void Workshop::DerpEngine::Update()
{
	while (true)
	{
		SDL_Event sdl_event;
		SDL_PollEvent(&sdl_event);

		// Update scene logic
		scene_system->UpdateLogic();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Scene render code here
		scene_system->UpdateRender();

		SDL_GL_SwapWindow(window);
	}
}

void Workshop::DerpEngine::StopEngine()
{
	SDL_Quit();
}
