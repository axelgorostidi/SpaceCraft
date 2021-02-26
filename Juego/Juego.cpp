#include "Juego.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EscenaBase.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

Juego *Juego::instancia = nullptr;

Juego::Juego(){}

Juego &Juego::create(const VideoMode &videoMode, EscenaBase *escena, const string &nombre){
	if(instancia){
		cerr<<"ERROR: El juego ya esta en ejecución."<<endl;
	}else{
		Juego &j = getInstancia();
		j.window.create(videoMode, nombre, Style::Close);
		j.ProximaEscena = nullptr;
		j.ActualEscena = escena;
		j.window.setFramerateLimit(60);
	}
	return getInstancia();
}

Juego &Juego::getInstancia(){
	if(!instancia){
		instancia = new Juego();
	}
	return *instancia;
}

void Juego::run(){
	while(window.isOpen() && ActualEscena != nullptr) {
		Event e;
		while(window.pollEvent(e)) {
			if(e.type == Event::Closed){
				window.close();	
			}
		}
		update();
		draw();
		if(ProximaEscena != nullptr){
			delete ActualEscena;
			ActualEscena = ProximaEscena;
			ProximaEscena = nullptr;
		}
	}
}

void Juego::update(){
	ActualEscena->update();
}

void Juego::draw(){
	window.clear(Color::Black);
	ActualEscena->draw(window);
	window.display();
}

void Juego::CambiarEscena(EscenaBase *escena){
	ProximaEscena = escena;
}
