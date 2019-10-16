#ifndef SCENE_H
#define SCENE_H

namespace Workshop
{
	class Scene
	{
	public:
		Scene() = default;

		virtual ~Scene() = default;
		
		virtual void InitializeScene() = 0;

		virtual void UpdateLogic() = 0;

		virtual void UpdateRender() = 0;

		virtual void EndScene() = 0;
	};
}

#endif // SCENE_H