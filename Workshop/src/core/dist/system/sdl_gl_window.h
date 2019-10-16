#ifndef SDL_GL_WINDOW_H
#define SDL_GL_WINDOW_H

#include "../../system/i_window.h"

#include <memory>
#include <SDL2/SDL.h>

namespace Workshop
{
	class SDL_GL_Window : public IWindow
	{
	private:
		friend class SDL_GL_GraphicsSystem;
		
		std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
		
	public:
		SDL_GL_Window();
		
		void CreateWindow(const WinInfo& window_info_) override;
		void SetThisWindowAsContext() override;
	};
}

#endif // SDL_GL_WINDOW_H