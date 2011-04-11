#ifndef SCENEMAP_H
#define SCENEMAP_H

#include <SFML/Graphics.hpp>
#include "scene_manager.h"

class SceneMap : public Scene {

	static SceneMap* ms_instance;

public:
	static SceneMap* Instance();
	static void Release();

private:
	SceneMap();
	~SceneMap();
	
	sf::Image image;
	sf::Sprite sprite;
	
	void Init();
	void Update(float time);
	void Draw();
};

#endif // SCENEMAP_H
