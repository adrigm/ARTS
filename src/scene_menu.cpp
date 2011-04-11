#include "scene_menu.h"

SceneMenu* SceneMenu::ms_instance = 0;

SceneMenu::SceneMenu()
{
}

SceneMenu::~SceneMenu()
{
}

void SceneMenu::Init()
{
}

void SceneMenu::Update(float time)
{
	std::cout << "Scene MENU\n";
}

void SceneMenu::Draw()
{
}

SceneMenu* SceneMenu::Instance()
{
	if(ms_instance == 0){
		ms_instance = new SceneMenu();
	}
	return ms_instance;
}

void SceneMenu::Release()
{
	if(ms_instance){
		delete ms_instance;
	}
	ms_instance = 0;
}

