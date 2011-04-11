#include "scene_manager.h"

SceneManager* SceneManager::ms_instance = 0;

SceneManager::SceneManager()
{
	this->window.Create(sf::VideoMode(1024, 768, 32), "Proyect Started", sf::Style::Titlebar | sf::Style::Close);
	this->window.UseVerticalSync(true);
	this->scene = 0;
	this->quit_flag = false;
}

SceneManager::~SceneManager()
{
}

void SceneManager::Loop()
{
	// Bucle principal del juego
	while(!this->quit_flag)
	{
		// Obtenemos el tiempo pasado.
		float time = this->clock.GetElapsedTime();
		this->clock.Reset();
		//const sf::Input& input = window.GetInput(); // No necesaria
		
		// Procesar eventos del sistema
        sf::Event Event;
        while (this->window.GetEvent(Event))
        {
            // Cerrar el juego
            if (Event.Type == sf::Event::Closed)
			{
				this->window.Close(); // cierra la ventana
				this->quit_flag = true; // Sale del bucle
			}
        }
		
		// Llamar a los métodos update y draw de la escena activa
		this->scene->Update(time);
		this->scene->Draw();
		
		// Refrescamos la ventana
		this->window.Display();
	}
}

void SceneManager::SetSceneMap()
{
	SceneMap *scene = SceneMap::Instance();
	this->scene = scene;
}

void SceneManager::SetSceneMenu()
{
	SceneMenu *scene = SceneMenu::Instance();
	this->scene = scene;
}

// Cambia el puntero de la escena a mostrar
void SceneManager::ChangeScene(Scene *scene)
{
	this->scene = scene;
}

SceneManager* SceneManager::Instance()
{
	if(ms_instance == 0){
		ms_instance = new SceneManager();
	}
	return ms_instance;
}

void SceneManager::Release()
{
	if(ms_instance){
		delete ms_instance;
	}
	ms_instance = 0;
}
