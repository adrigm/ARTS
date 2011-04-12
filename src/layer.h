#ifndef LAYER_H
#define LAYER_H

#include <string>
#include <vector>

class Layer {

public:
	Layer();
	~Layer();
	
	// Nombre de la capa
	std::string name;
	
	// Tamaño de la capa
	unsigned int width;
	unsigned int height;
	
	// Datos de tiles
	std::vector<unsigned int> data;
};

#endif // LAYER_H
