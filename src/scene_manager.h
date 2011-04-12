#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "director.h"
#include "scene.h"
#include "scene_map.h"

class SceneManager {

	static SceneManager* ms_instance;

public:
	static SceneManager* Instance();
	static void Release();
	
	void SetSceneMap();

private:
	SceneManager();
	~SceneManager();
	
	Director *dir;

};

#endif // SCENEMANAGER_H
