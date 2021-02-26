#include "EscenaPerder.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "EscenaMenu.h"
#include <SFML/Window/Keyboard.hpp>
#include "EscenaJuego.h"
#include <sstream>
#include "Global.h"
using namespace std;
using namespace sf;
EscenaPerder::EscenaPerder() {
	texfondoGO.loadFromFile("imagenes/gameover.png");
	spfondoGO.setTexture(texfondoGO);
	
	Puntaje = Global::UltPuntaje;
	
	FuentePuntajeTexto.loadFromFile("fuentes/Gravedigger.otf");
	PuntajeTexto.setFont(FuentePuntajeTexto);
	PuntajeTexto.setColor(Color::White);
	
	stringstream tmp;
	tmp<<"SCORE: "<<int(Puntaje);
	PuntajeTexto.setString(tmp.str());
	
	PuntajeTexto.setPosition(530,500);
	
	if(Puntaje > Global::MaxPuntaje){
		Global::MaxPuntaje = Puntaje;
		g->outPuntajeMaximo();
	}
	Global::UltPuntaje = 0;
}

void EscenaPerder::update(){
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		Juego::getInstancia().CambiarEscena(new EscenaMenu());
	}
}

void EscenaPerder::draw(RenderWindow &w){
	w.draw(spfondoGO);
	w.draw(PuntajeTexto);
}

