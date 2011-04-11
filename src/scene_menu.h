#ifndef SCENEMENU_H
#define SCENEMENU_H

#include "scene_manager.h"

class SceneMenu : public Scene {

	static SceneMenu* ms_instance;

public:
	static SceneMenu* Instance();
	static void Release();

private:
	SceneMenu();
	~SceneMenu();
	
	void Init();
	void Update(float time);
	void Draw();
};

#endif // SCENEMENU_H
