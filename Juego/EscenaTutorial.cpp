#include "EscenaTutorial.h"
#include "Juego.h"
#include "EscenaMenu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf;
EscenaTutorial::EscenaTutorial() {
	texTutorial.loadFromFile("imagenes/tutorial.png");
	spTutorial.setTexture(texTutorial);
}

void EscenaTutorial::update(){
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		Juego::getInstancia().CambiarEscena(new EscenaMenu());
	}
}

void EscenaTutorial::draw(RenderWindow &w){
	w.draw(spTutorial);
}
