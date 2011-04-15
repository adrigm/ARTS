#ifndef SCENEMAP_H
#define SCENEMAP_H

#include <SFML/Graphics.hpp>
#include "scene_manager.h"
#include "map.h"

class SceneMap : public Scene {

	static SceneMap* ms_instance;

public:
	static SceneMap* Instance();
	static void Release();

private:
	SceneMap();
	~SceneMap();
	
	Map mapa;
	
	void Init();
	void Update(float time);
	void Draw();
};

#endif // SCENEMAP_H
