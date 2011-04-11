#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

/**
 * @brief Representa una escena abstracta del juego.
 * 
 * Todas las escenas del juego deben de heredar de esta.
 */
class Scene {

public:
	Scene();
	virtual ~Scene();
	
	virtual void Init();
	
	/** Se llama una vez en cada frame del juego.
	 * 
	 * Utilizar para actualizar la escena.
	 * @param time Tiempo pasado desde la última llamada.
	 */
	virtual void Update(float time);
	
	/** Se llama una vez en cada frame del juego.
	 * 
	 * Se llama despuesde update, utilizar para dibujar.
	 */
	virtual void Draw();
	
	sf::RenderWindow *window;

};

#endif // SCENE_H
