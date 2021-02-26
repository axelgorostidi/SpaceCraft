#include "EscenaMenu.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "EscenaJuego.h"
#include "EscenaTutorial.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>
#include "Global.h"
using namespace sf;
using namespace std;
EscenaMenu::EscenaMenu() {
	texNave1.loadFromFile("imagenes/navePropulsion.png");
	texNave2.loadFromFile("imagenes/navePropulsion2.png");
	texMenu.loadFromFile("imagenes/menu.png");
	
	spNave1.setTexture(texNave1);
	spNave2.setTexture(texNave2);
	spMenu.setTexture(texMenu);
	spNave1.setScale(0.4,0.4);
	spNave2.setScale(0.4,0.4);
	spNave1.setPosition(560,230);
	spNave2.setPosition(560,230);
	
	FuentePuntajeTexto.loadFromFile("fuentes/Gravedigger.otf");
	PuntajeTexto.setFont(FuentePuntajeTexto);
	PuntajeTexto.setColor(Color::Red);
	
	g->getPuntajeMaximo();
	Puntaje = Global::MaxPuntaje;
	stringstream tmp;
	tmp<<"HIGHSCORE: "<<int(Puntaje);
	PuntajeTexto.setString(tmp.str());
	PuntajeTexto.setPosition(480,150);
}
int conta=0;

void EscenaMenu::update(){
	
	conta++;
	if(conta>10){
		spNave1 = spNave2;
	}
	if(conta>20){
		spNave1.setTexture(texNave1);
		conta=0;
	}
	if(Keyboard::isKeyPressed(Keyboard::Return)){
		Juego::getInstancia().CambiarEscena(new EscenaJuego());
	}
	if(Keyboard::isKeyPressed(Keyboard::T)){
		Juego::getInstancia().CambiarEscena(new EscenaTutorial());
	}
}

void EscenaMenu::draw(RenderWindow &w){
	EscenaBase::draw(w);
	w.draw(spMenu);
	w.draw(spNave1);
	w.draw(PuntajeTexto);
	
}
