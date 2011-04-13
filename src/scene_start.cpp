#include "scene_start.h"

SceneStart* SceneStart::ms_instance = 0;

SceneStart::SceneStart()
{
}

void SceneStart::on_event()
{
}

void SceneStart::on_update(float time)
{
	std::cout << "Scene Start!!!\n";
	SceneManager *manager = SceneManager::Instance();
	manager->SetSceneMain();
}

void SceneStart::on_draw()
{
}

SceneStart::~SceneStart()
{
}

SceneStart* SceneStart::Instance()
{
	if(ms_instance == 0)
	{
		ms_instance = new SceneStart();
	}
	return ms_instance;
}

void SceneStart::Release()
{
	if(ms_instance)
	{
		delete ms_instance;
	}
	ms_instance = 0;
}
