#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

class Scene {

public:
	Scene();
	~Scene();
	
	virtual void Update(float time);
	virtual void Draw();
	
	sf::RenderWindow *window;
	
};

#endif // SCENE_H
