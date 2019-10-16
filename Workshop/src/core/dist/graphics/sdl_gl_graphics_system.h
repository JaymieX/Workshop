#ifndef SDL_GL_GRAPHICS_SYSTEM_H
#define SDL_GL_GRAPHICS_SYSTEM_H

#include "../../graphics/i_graphics_system.h"
#include "../system/sdl_gl_window.h"

#include <SDL2/SDL.h>


namespace Workshop
{
	class SDL_GL_GraphicsSystem : public IGraphicsSystem
	{
	private:
		SDL_Event sdl_event;
		SDL_GL_Window* win;
		
	public:
		SDL_GL_GraphicsSystem();
		
		void InitializeGraphicsSystem(const WinInfo& window_info_) override;
		
		void BeginRenderProtocol() override;
		
		void EndRenderProtocol() override;
		
		void StopGraphicsSystem() override;
	};
}

#endif // SDL_GL_GRAPHICS_SYSTEM_H
