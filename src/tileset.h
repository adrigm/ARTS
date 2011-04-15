#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Tileset
{
public:
	Tileset();
	~Tileset();
	
	bool Init();
	void Draw(sf::RenderWindow *window, int x, int y, int indx);
	void CreateRects();
	
	// Nombre del tileset
	std::string name;
	
	// ruta de la imagen
	std::string src_image;
	
	// Numero del tile inicial
	unsigned int firstgid;
	
	// Tamaño de los tiles
	unsigned int tile_width;
	unsigned int tile_height;
	
	// Tamaño del tileset
	unsigned int width;
	unsigned int height;
	
	// Numero de filas y columnas
	unsigned int fil;
	unsigned int col;
	
	sf::Image image;
	sf::Sprite sprite;
	std::vector<sf::IntRect> rects;
};

#endif // TILESET_H
