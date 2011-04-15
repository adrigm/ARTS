#include "director.h"

Director* Director::ms_instance = 0;

Director::Director()
{
	this->window.Create(sf::VideoMode(1600, 1200, 32), "ARTS", sf::Style::Titlebar | sf::Style::Close);
	this->window.UseVerticalSync(true);
	this->quit_flag = false;
}

void Director::loop()
{
	// Bucle principal del juego
	while (!this->quit_flag)
	{
		// Comprobamos si hay cambio de escena
		if (this->new_scene)
		{
			this->scene = this->new_scene;
			this->new_scene = 0;
		}
		
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
		
		// Llamar a los métodos update, event y draw de la escena activa
		this->scene->Update(time);
		this->scene->Draw();
		
		// Refrescamos la ventana
		this->window.Display();
	}
}


// Cambia el puntero de la escena a mostrar
void Director::changeScene(Scene *scene)
{
	this->new_scene = scene;
}

Director::~Director()
{
}

Director* Director::Instance()
{
	if(ms_instance == 0){
		ms_instance = new Director();
	}
	return ms_instance;
}

void Director::Release()
{
	if(ms_instance){
		delete ms_instance;
	}
	ms_instance = 0;
}