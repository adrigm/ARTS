#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <SFML/Graphics.hpp>
#include "scene.h"

class Director {

	static Director* ms_instance;

public:
	static Director* Instance();
	static void Release();
	
	void loop();
	void changeScene(Scene *scene);
	
	sf::RenderWindow window;
	
private:
	Director();
	~Director();
	
	sf::Clock clock;
	Scene *scene; // Puntero a escena activa
	Scene *new_scene; // Próxima escena activa
	bool quit_flag; // Control de salida del bucle
	
};

#endif // DIRECTOR_H
