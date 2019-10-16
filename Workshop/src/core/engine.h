#ifndef ENGINE_H
#define ENGINE_H

#include "graphics/i_graphics_system.h"
#include "system/i_window.h"
#include "system/scene_system.h"

#include <memory>

namespace Workshop
{
	enum Distribution
	{
		SDL_GL,
		SDL_DX11
	};
	
	class Engine final
	{
	private:
		std::unique_ptr<IGraphicsSystem> graphics_system;

	public:
		std::unique_ptr<SceneSystem> scene_system;

		// Default construct
		Engine() = default;

		// Default deconstruct
		~Engine() = default;

		// Deleted copy constructor
		Engine(const Engine&) = delete;

		// Deleted move constructor
		Engine(Engine&&) = delete;

		// Deleted copy assignment operator
		Engine& operator=(const Engine&) = delete;

		// Deleted move assignment operator
		Engine& operator=(Engine&&) = delete;

		// Singleton? Disgusting~
		// Lets try use dependency injection for a change
		void InitializeEngine(Distribution dist_, const WinInfo& window_info_);

		void Update();

		void StopEngine();
	};
}

#endif // ENGINE_H