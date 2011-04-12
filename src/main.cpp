#include "director.h"
#include "scene_manager.h"

using namespace std;

int main()
{
	Director *dir = Director::Instance();
	SceneManager *manager = SceneManager::Instance();
	manager->SetSceneMap();
	dir->loop();

	// Liberamos la memoria
	dir->Release();
	manager->Release();

	return 0;
}