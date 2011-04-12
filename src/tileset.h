#ifndef TILESET_H
#define TILESET_H

#include <string>

class Tileset
{
public:
	Tileset();
	~Tileset();
	
	std::string name;
	std::string src_image;
	unsigned int firstgid;
	unsigned int tile_width;
	unsigned int tile_height;
	unsigned int width;
	unsigned int height;
};

#endif // TILESET_H
