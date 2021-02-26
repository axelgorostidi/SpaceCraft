#include "Nave.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "AsteroideGrande.h"
#include <SFML/Graphics/Rect.hpp>

using namespace sf;
Nave::Nave() {
	//cargo texturas
	texNave.loadFromFile("imagenes/navenave.png");
	texNaveIzq.loadFromFile("imagenes/naveIZQ1.png");
	texNaveDer.loadFromFile("imagenes/naveDER1.png");
	texPropulsion.loadFromFile("imagenes/navePropulsion.png");
	//creo sprites
	spNave.setTexture(texNave);
	spNaveIzq.setTexture(texNaveIzq);
	spNaveDer.setTexture(texNaveDer);
	spPropulsion.setTexture(texPropulsion);
	spNave.setScale(0.2,0.2);
	spNaveIzq.setScale(0.2,0.2);
	spNaveDer.setScale(0.2,0.2);
	spPropulsion.setScale(0.2,0.2);
	spNave.setPosition(570,530);
	//Disparo1
	texDisparo1.loadFromFile("imagenes/disparo1.png");
	spDisparo1.setTexture(texDisparo1);
	spDisparo1.setPosition(2000,2000);
	spDisparo1.setScale(0.2,0.2);
	//Disparo2
	texDisparo2.loadFromFile("imagenes/misil.png");
	spDisparo2.setTexture(texDisparo2);
	spDisparo2.setPosition(2000,2000);
	spDisparo2.setScale(0.08,0.08);
}

int contador1 =0;
int contador2 =0;
void Nave::update(){
	contador1++;
	contador2++;
	spNave.setTexture(texNave);
	if(Keyboard::isKeyPressed(Keyboard::A)){
		spNaveIzq.setPosition(spNave.getPosition().x,spNave.getPosition().y);
		spNave = spNaveIzq;
		spNave.move(-15,0);
	}else if(Keyboard::isKeyPressed(Keyboard::D)){
		spNaveDer.setPosition(spNave.getPosition().x,spNave.getPosition().y);
		spNave = spNaveDer;
		spNave.move(15,0);
	}else if(Keyboard::isKeyPressed(Keyboard::W)){
		spPropulsion.setPosition(spNave.getPosition().x,spNave.getPosition().y);
		spNave = spPropulsion;
		spNave.move(0,-15);
	}else if(Keyboard::isKeyPressed(Keyboard::S)){
		spNave.move(0,15);
	}
	if(contador1>19){
		if(Keyboard::isKeyPressed(Keyboard::P)){
		spDisparo1.setPosition(spNave.getPosition().x+14, spNave.getPosition().y);
		contador1 = 0;
	}
	}
	spDisparo1.move(0,-30);
	
	if(contador2>60){
		if(Keyboard::isKeyPressed(Keyboard::O)){
			spDisparo2.setPosition(spNave.getPosition().x+25, spNave.getPosition().y-50);
			contador2 = 0;
		}
	}
	spDisparo2.move(0,-10);
	//limito movimiento a la pantalla
	Vector2f navePos = spNave.getPosition();
	if(navePos.x<0){ navePos.x=0;}
	if(navePos.x>1200){navePos.x=1200;}
	if(navePos.y<0){navePos.y=0;}
	if(navePos.y>550){navePos.y=550;}
	spNave.setPosition(navePos);
	
}

void Nave::draw(RenderWindow &w){
	w.draw(spNave);
	w.draw(spDisparo1);
	w.draw(spDisparo2);
}
Sprite &Nave::getSpriteNAVE(){
	return spNave;
}
Sprite &Nave::getSpriteDISPARO1(){
	return spDisparo1;
}
Sprite &Nave::getSpriteDISPARO2(){
	return spDisparo2;
}
void Nave::ReposicionarDisparo2(){
	spDisparo2.setPosition(2000,2000);
}
void Nave::ReposicionarDisparo1(){
	spDisparo1.setPosition(2000,2000);
}
bool Nave::DisparoAsteroideG(AsteroideGrande *AG){
	FloatRect Disp2Rect = getSpriteDISPARO2().getGlobalBounds();
	FloatRect AstRect = AG->getSprite().getGlobalBounds();
	return Disp2Rect.intersects(AstRect);
}

bool Nave::ChocaAsteroideG(AsteroideGrande *AG){
	FloatRect NaveRect = getSpriteNAVE().getGlobalBounds();
	FloatRect AstRect = AG->getSprite().getGlobalBounds();
	return NaveRect.intersects(AstRect);
}
