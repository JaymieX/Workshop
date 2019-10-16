#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include "../../core/system/scene.h"

class MainScene : public Workshop::Scene
{
public:
	void InitializeScene() override;
	void UpdateLogic() override;
	void UpdateRender() override;
	void EndScene() override;
};

#endif // MAIN_SCENE_H