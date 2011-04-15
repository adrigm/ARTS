#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <SFML/Graphics.hpp>
#include "libs/pugixml/pugixml.hpp"
#include "utils/base64.h"
#include "utils/zlib.h"
#include "utils/strings_utils.h"
#include "tileset.h"
#include "layer.h"

class Map {

public:
	Map();
	~Map();
	
	bool Init(std::string src);
	bool LoadFile(std::string filename);
	void Draw(sf::RenderWindow *window);
	
	sf::Vector2i Plot(int x, int y, int n_tileset);

private:
	// Nombre del mapa
	std::string name;
	
	// Tamaño del mapa
	unsigned int width;
	unsigned int height;
	
	// Tamaño de los tiles
	unsigned int tile_width;
	unsigned int tile_height;
	
	// Establecemos la altura de la base de los tiles
	unsigned int height_base;
	
	// Lista de tilesets
	std::vector<Tileset> tilesets;
	
	// Lista de capas
	std::vector<Layer> layers;
	
	int NumberTileset(int tile);
};

#endif // MAP_H
