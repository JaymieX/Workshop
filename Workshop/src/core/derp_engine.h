#ifndef DERP_ENGINE_H
#define DERP_ENGINE_H

#include "engine.h"

#include <SDL2/SDL.h>

namespace Workshop
{
	// Don't write class like this
	class DerpEngine
	{
		SDL_Window* window;
		
	public:
		std::unique_ptr<SceneSystem> scene_system;
		
		void InitializeEngine(Distribution dist_, const WinInfo& window_info_);

		void Update();

		void StopEngine();
	};
}

#endif // DERP_ENGINE_H