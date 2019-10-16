#include "engine.h"
#include "dist/graphics/sdl_gl_graphics_system.h"

void Workshop::Engine::InitializeEngine(Distribution dist_, const WinInfo& window_info_)
{
	// Pick a distribution
	switch (dist_)
	{
	case SDL_GL:
		graphics_system = std::make_unique<SDL_GL_GraphicsSystem>();
		break;
	case SDL_DX11:
		break;
	}

	// Make scene system
	scene_system = std::make_unique<SceneSystem>();

	// Initialize the graphics system
	graphics_system->InitializeGraphicsSystem(window_info_);
}

void Workshop::Engine::Update()
{
	while (true)
	{
		// Update scene logic
		scene_system->UpdateLogic();

		// Begin render
		graphics_system->BeginRenderProtocol();

		// Scene render code here
		scene_system->UpdateRender();

		graphics_system->EndRenderProtocol();
		// End render
	}
}

void Workshop::Engine::StopEngine()
{
	graphics_system->EndRenderProtocol();
}
