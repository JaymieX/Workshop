#ifndef SCENE_SYSTEM_H
#define SCENE_SYSTEM_H

#include "scene.h"

#include <string>
#include <unordered_map>

namespace Workshop
{
	class SceneSystem
	{
	private:
		std::unordered_map<std::string, Scene*> scenes;

		Scene* current_scene;
		
	public:
		inline SceneSystem() :
			current_scene(nullptr)
		{
		}

		inline ~SceneSystem()
		{
			for (auto& s : scenes)
			{
				delete s.second;
			}
		}
		
		template <typename SceneType>
		inline void AddScene(const std::string& name_)
		{
			if (scenes.find(name_) == scenes.end())
			{
				scenes.insert(std::make_pair(name_, new SceneType()));
			}
		}

		void SwitchScene(const std::string& name_);

		inline void UpdateLogic()
		{
			if (current_scene != nullptr)
			{
				current_scene->UpdateLogic();
			}
		}

		inline void UpdateRender()
		{
			if (current_scene != nullptr)
			{
				current_scene->UpdateRender();
			}
		}
	};
}

#endif // SCENE_SYSTEM_H