#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "EscenaBase.h"
#include "Juego.h"
#include <SFML/Window/VideoMode.hpp>
#include <string>
using namespace std;
using namespace sf;

class Juego {
public:
	
	void run();
	
	void CambiarEscena(EscenaBase *escena);
	
	static Juego &getInstancia();
	
	static Juego &create(const VideoMode &videoMode, EscenaBase *escena, const string &nombre = "");
private:
	RenderWindow window;
	EscenaBase *ActualEscena, *ProximaEscena;
	
	void ProcesarEventos();
	void update();
	void draw();
	static Juego *instancia;
	
	Juego();
	
};

#endif

