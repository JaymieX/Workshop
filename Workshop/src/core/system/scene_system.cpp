#include "scene_system.h"

void Workshop::SceneSystem::SwitchScene(const std::string& name_)
{
	if (scenes.find(name_) != scenes.end())
	{
		if (current_scene != nullptr)
		{
			current_scene->EndScene();
		}

		current_scene = scenes.at(name_);
		current_scene->InitializeScene();
	}
}
