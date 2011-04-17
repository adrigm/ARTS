#include "map.h"

Map::Map()
{
	this->name = "";
}

Map::~Map()
{
}

bool Map::Init(std::string src)
{
	// Cargamos el mapa
	if(!this->LoadFile(src))
	{
		std::cerr << "Error al cargar el mapa" << std::endl;
		return false;
	}
	
	// Iniciamos los tilesets
	for (int i = 0; i < this->tilesets.size(); i++)
	{
		if(!this->tilesets[i].Init())
		{
			std::cerr << "Error al inicializar el tileset " << i << std::endl;
			return false;
		}
	}
	
	// Establecemos la altura base de los tiles
	this->height_base = this->tilesets[0].tile_height;
	
	return true;
}

bool Map::LoadFile(std::string filename)
{
	// Cargamos el archivo de mapa
	pugi::xml_document doc;
	if (!doc.load_file(filename.c_str()))
	{
		std::cerr << "Map::LoadFile: Error al cargar el fichero xml " << filename << std::endl;
		return false;
	}

	// Cogemos el nodo principal
	pugi::xml_node root_node;
	if (!(root_node = doc.child("map")))
	{
		std::cerr << "Map::LoadFile: Error al leer el fichero xml en elemento map" << std::endl;
		return false;
	}

	// Tamaño del mapa
	this->width = root_node.attribute("width").as_uint();
	this->height = root_node.attribute("height").as_uint();

	// Tamaño de los tiles
	this->tile_width = root_node.attribute("tilewidth").as_uint();
	this->tile_height = root_node.attribute("tileheight").as_uint();

	// Recorremos todos los nodos del mapa
	for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling())
	{
		// Obtenemos el nombre del nodo
		std::string name = node.name();

		// Si es el nodo de propiedades
		if (name == "properties")
		{
			// Recorremos las propiedades
			for (pugi::xml_node property = node.first_child(); property; property = property.next_sibling())
			{
				// Extraemos el nombre
				std::string name = property.attribute("name").value();
				if (name == "name")
					this->name = property.attribute("value").value();
			}
		}

		// Si es un nodo de tileset
		else if (name == "tileset")
		{
			// Creamos un objeto Tileset
			Tileset tileset;

			// Nombre del tileset
			tileset.name = node.attribute("name").value();

			// Número del primer tile
			tileset.firstgid = node.attribute("firstgid").as_uint();

			// Tamaño de los tiles
			tileset.tile_width = node.attribute("tilewidth").as_uint();;
			tileset.tile_height = node.attribute("tileheight").as_uint();;

			// Obtenemos el nodo image
			pugi::xml_node image = node.child("image");

			// Ruta de la imagen del tileset
			tileset.src_image =  extrac_name(image.attribute("source").value());

			// Tamaño de la imagen
			tileset.width = image.attribute("width").as_uint();
			tileset.height = image.attribute("height").as_uint();
			
			// Añadimos el tileset a la lista de tilesets
			this->tilesets.push_back(tileset);
		}
		
		// Si es un nodo de layer
		else if (name == "layer")
		{
			// Creamos un objeto Layer
			Layer layer;

			// Nombre da la capa
			layer.name = node.attribute("name").value();

			// Tamaño de la capa
			layer.width = node.attribute("width").as_uint();
			layer.height = node.attribute("height").as_uint();

			// Obtenemos el nodo data
			pugi::xml_node data = node.child("data");
			
			// Creamos array auxuliar
			std::vector<unsigned int> values;

			// Tipo de compresión
			const std::string compression = data.attribute("compression").value();
			
			// Descomprimimos y decodifamos la capa
			int len = strlen((const char*)data.child_value()) + 1;
			unsigned char *charData = new unsigned char[len + 1];
			const char *charStart = (const char*) data.child_value();
			unsigned char *charIndex = charData;

			while (*charStart)
			{
				if (*charStart != ' ' && *charStart != '\t' &&
				        *charStart != '\n')
				{
					*charIndex = *charStart;
					charIndex++;
				}
				charStart++;
			}
			*charIndex = '\0';

			int binLen;
			unsigned char *binData = php3_base64_decode(charData, strlen((char*)charData), &binLen);

			delete[] charData;

			if (binData)
			{
				if (compression == "gzip" || compression == "zlib")
				{
					// Inflate the gzipped layer data
					unsigned char *inflated;
					unsigned int inflatedSize = inflateMemory(binData, binLen, inflated);

					//free(binData);
					binData = inflated;
					binLen = inflatedSize;

					if (!inflated)
					{
						std::cerr << "Error: Could not decompress layer!" << std::endl;
						return false;
					}
				}
				for (int i = 0; i < binLen - 3; i += 4)
				{
					const int gid = binData[i] | binData[i + 1] << 8 | binData[i + 2] << 16 | binData[i + 3] << 24;
					values.push_back(gid);
				}
				//free(binData);
			}
			
			// Creamos un array bidimensional para los datos
			int cont = 0;
			for(int f=0; f < this->height; f++)
			{
				std::vector<unsigned int> aux;
				for(int c=0; c < this->width; c++)
				{
					aux.push_back(values[cont]);
					cont++;
				}
				layer.data.push_back(aux);
			}
			
			// Añadimos la capa a la lista de capas
			this->layers.push_back(layer);
		}
	}
	return true;
}

sf::Vector2i Map::Plot(int x, int y, int n_tileset)
{
	int posx = ((x-y) * (this->tile_width / 2)) + 400; 
	int posy = (((x+y) * (this->tile_height / 2)) - this->tilesets[n_tileset].tile_height) + this->tile_height;
	return sf::Vector2i(posx, posy);
}

void Map::Draw(sf::RenderWindow *window)
{
	for (int i = 0; i < this->layers.size(); i++)
	{
		for (int f = 0; f < this->height; f++)
		{
			for (int c = 0; c < this->width; c++)
			{
				if (this->layers[i].data[f][c] != 0)
				{
					int n_tileset = this->NumberTileset(this->layers[i].data[f][c]);
					this->tilesets[n_tileset].Draw(window, 
					this->Plot(c, f, n_tileset), this->layers[i].data[f][c]);
				}
			}
		}
	}
}

// Devuelve el tileset al que pertenece una posición
int Map::NumberTileset(int tile)
{
	for (int i = 0; i < this->tilesets.size(); i++)
	{
		if (tile < this->tilesets[i].num_tiles+this->tilesets[i].firstgid)
			return i;
	}
	return -1;
}
