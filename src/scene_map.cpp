#include "scene_map.h"

SceneMap* SceneMap::ms_instance = 0;

SceneMap::SceneMap()
{
	this->image.LoadFromFile("resources/graphics/granjero.png");
	this->image.SetSmooth(false);
	this->sprite.SetImage(this->image);
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
	this->window->Clear(sf::Color(200, 220, 255));
	this->window->Draw(this->sprite);
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

