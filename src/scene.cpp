#include "scene.h"
#include "director.h"

Scene::Scene()
{
	Director *dir = Director::Instance();
	this->window = &dir->window;
}

Scene::~Scene()
{
}

void Scene::Update(float time)
{
}

void Scene::Draw()
{
}
