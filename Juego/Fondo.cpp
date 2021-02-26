#include "Fondo.h"
using namespace sf;
Fondo::Fondo() {
	texFondo.loadFromFile("imagenes/fondofondo.png");
	spFondo.setTexture(texFondo);
	spFondo.setPosition(0,-1300);
}

void Fondo::update(){
	if(spFondo.getPosition().y<0){
		spFondo.move(0,10);
	}
	if(spFondo.getPosition().y>=0){
		spFondo.setPosition(0,-1300);
	}
}

void Fondo::draw(RenderWindow &w){
	w.draw(spFondo);
}
Sprite &Fondo::getSprite(){
	return spFondo;
}


