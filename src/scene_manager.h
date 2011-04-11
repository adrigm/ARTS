#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene.h"

#include "scene_map.h"
#include "scene_menu.h"

class SceneManager
{
	static SceneManager* ms_instance;

public:
	static SceneManager* Instance();
	static void Release();

	void Loop();
	void ChangeScene(Scene *scene);

	sf::RenderWindow window;

private:
	SceneManager();
	~SceneManager();

	sf::Clock clock;
	Scene *scene; // Puntero a escena activa
	bool quit_flag; // Control de salida del bucle
	
	void SetSceneMap();
	void SetSceneMenu();

};

#endif // SCENEMANAGER_H
