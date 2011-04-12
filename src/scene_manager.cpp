#include "scene_manager.h"

SceneManager* SceneManager::ms_instance = 0;

SceneManager::SceneManager()
{
	this->dir = Director::Instance();
}

void SceneManager::SetSceneMap()
{
	SceneMap *scene = SceneMap::Instance();
	this->dir->changeScene(scene);
}

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::Instance()
{
	if(ms_instance == 0)
	{
		ms_instance = new SceneManager();
	}
	return ms_instance;
}

void SceneManager::Release()
{
	if(ms_instance)
	{
		delete ms_instance;
	}
	ms_instance = 0;
}
