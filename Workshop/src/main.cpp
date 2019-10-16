#include "core/engine.h"
#include "asset/scene/main_scene.h"
#include "core/derp_engine.h"

template <typename TY>
void RunTypeEraseEngine(Workshop::Distribution dist_, const Workshop::WinInfo& win_info_)
{
	// Workshop::Engine* e = new Workshop::Engine();
	std::unique_ptr<TY> e = std::make_unique<TY>();

	e->InitializeEngine(dist_, win_info_); // Init engine with settings

	// Make a new scene and add to scene system
	e->scene_system->template AddScene<MainScene>("MainScene");
	e->scene_system->SwitchScene("MainScene");

	// Game loop
	e->Update();

	e->StopEngine();

	// delete e;
}

int main(int argc_, char* argv_[])
{
	// Derpy but easy to read way~
	Workshop::WinInfo win;
	win.x = 50;
	win.y = 50;
	win.width = 800;
	win.height = 600;
	win.title = "Workshop Engine";

	// Workshop::WinInfo win(50, 50, 800, 600, "Workshop");
	// Workshop::WinInfo win{ 50, 50, 800, 600, "Workshop" };

	// RunTypeEraseEngine<Workshop::Engine>(Workshop::SDL_GL, win);
	RunTypeEraseEngine<Workshop::DerpEngine>(Workshop::SDL_GL, win);
	
	return 0;
}
