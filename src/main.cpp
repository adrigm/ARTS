#include "scene_manager.h"
#include "scene_map.h"

int main (int argc, char *argv[])
{
	SceneManager *sm = SceneManager::Instance();
	SceneMap *scene = SceneMap::Instance();
	sm->ChangeScene(scene);
	sm->Loop();

	// Liberamos la memoria
	sm->Release();
	
	return 0;
}
