#include "tileset.h"
#include <iostream>

Tileset::Tileset()
{
}

Tileset::~Tileset()
{
}

bool Tileset::Init()
{
	// Cargamos la imagen
	if(!this->image.LoadFromFile("resources/graphics/tilesets/"+this->src_image))
		return false;
	
	// Desactivamos el suavizado
	this->image.SetSmooth(false);
	
	// Creamos el sprite a partir de la imagen
	this->sprite.SetImage(this->image);
	
	// Calculamos las filas y columnas
	this->fil = this->height / this->tile_height;
	this->col = this->width / this->tile_width;
	
	// Numero de tiles
	this->num_tiles = this->fil * this->col;
	
	// Creamos los rects
	this->CreateRects();
	
	return true;
}

void Tileset::CreateRects()
{
	/*// Añadimos un Rect vacio en la pos 0
	sf::IntRect _void;
	this->rects.push_back(_void);*/
	
	// Creamos una lista con los rects del tileset
	for (int f = 0; f < this->fil; f++)
	{
		for (int c = 0; c < this->col; c++)
		{
			unsigned int x1 = c * this->tile_width;
			unsigned int y1 = f * this->tile_height;
			unsigned int x2 = x1 + this->tile_width;
			unsigned int y2 = y1 + this->tile_height;
			sf::IntRect rect(x1, y1, x2, y2);
			this->rects.push_back(rect);
		}
	}
}

void Tileset::Draw(sf::RenderWindow *window, sf::Vector2i pos, int indx)
{
	this->sprite.SetSubRect(this->rects[indx-this->firstgid]);
	this->sprite.SetPosition(float(pos.x), float(pos.y));
	window->Draw(this->sprite);
}