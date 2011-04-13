#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "libs/pugixml/pugixml.hpp"
#include "utils/base64.h"
#include "utils/zlib.h"
#include "tileset.h"
#include "layer.h"

class Map {

public:
	Map();
	Map(std::string filename);
	~Map();
	
	bool LoadFile(std::string filename);
	
	// Nombre del mapa
	std::string name;
	
	// Tamaño del mapa
	unsigned int width;
	unsigned int height;
	
	// Tamaño de los tiles
	unsigned int tile_width;
	unsigned int tile_height;
	
	// Lista de tilesets
	std::vector<Tileset> tilesets;
	
	// Lista de capas
	std::vector<Layer> layers;
};

#endif // MAP_H
