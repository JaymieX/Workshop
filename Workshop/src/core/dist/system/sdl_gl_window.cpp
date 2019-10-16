#include "sdl_gl_window.h"

Workshop::SDL_GL_Window::SDL_GL_Window() :
	window(nullptr, SDL_DestroyWindow)
{
}

void Workshop::SDL_GL_Window::CreateWindow(const WinInfo& window_info_)
{
	window.reset
	(
		SDL_CreateWindow
		(
			window_info_.title.c_str(),
			window_info_.x,
			window_info_.y,
			window_info_.width,
			window_info_.height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
		)
	);
}

void Workshop::SDL_GL_Window::SetThisWindowAsContext()
{
	SDL_GLContext context = SDL_GL_CreateContext(window.get());
	SDL_GL_MakeCurrent(window.get(), context);
}
