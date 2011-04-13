#ifndef SCENESTART_H
#define SCENESTART_H

#include "scene_manager.h"

class SceneStart : public Scene {

	static SceneStart* ms_instance;

public:
	static SceneStart* Instance();
	static void Release();

private:
	SceneStart();
	~SceneStart();
	
	void on_event();
	void on_update(float time);
	void on_draw();

};

#endif // SCENESTART_H
