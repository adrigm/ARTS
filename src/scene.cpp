#include "scene.h"
#include "scene_manager.h"

Scene::Scene()
{
	SceneManager *sm = SceneManager::Instance();
	this->window = &sm->window;
}

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Update(float time)
{
}

void Scene::Draw()
{
}