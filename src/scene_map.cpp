#include <iostream>

#include "scene_map.h"

SceneMap* SceneMap::ms_instance = 0;

SceneMap::SceneMap()
{
	if(!this->mapa.Init("resources/maps/test.tmx"))
	{
		std::cerr << "No se ha podido inicializar el mapa" << std::endl;
	}
	/*for (int i = 0; i < this->mapa.tilesets.size(); i++)
	{
		this->mapa.tilesets[i].Init();
	}*/
}

SceneMap::~SceneMap()
{
}

void SceneMap::Init()
{
}

void SceneMap::Update(float time)
{
}

void SceneMap::Draw()
{
	mapa.Draw(this->window);
}

SceneMap* SceneMap::Instance()
{
	if(ms_instance == 0){
		ms_instance = new SceneMap();
	}
	return ms_instance;
}

void SceneMap::Release()
{
	if(ms_instance){
		delete ms_instance;
	}
	ms_instance = 0;
}

