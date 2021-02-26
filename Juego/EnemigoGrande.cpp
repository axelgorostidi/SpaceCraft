#include "EnemigoGrande.h"
#include "Nave.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
EnemigoGrande::EnemigoGrande() {
	//cargo texturas
	texNaveG.loadFromFile("imagenes/naveEnemigaG.png");
	texNaveGIzq.loadFromFile("imagenes/naveEnemigaGizq.png");
	texNaveGDer.loadFromFile("imagenes/naveEnemigaGder.png");
	texExplosionNaveG.loadFromFile("imagenes/ExplosionNaveG.png");
	
	//creo sprites de la nave
	spNaveG.setTexture(texNaveG);
	spNaveGIzq.setTexture(texNaveGIzq);
	spNaveGDer.setTexture(texNaveGDer);
	spExplosionNaveG.setTexture(texExplosionNaveG);
	
	spNaveG.setScale(2,2);
	spNaveGIzq.setScale(2,2);
	spNaveGDer.setScale(2,2);
	spExplosionNaveG.setScale(2,2);
	
	srand(time(NULL));
	int posx = rand()%1230; 
	spNaveG.setPosition(posx, 0);
	spExplosionNaveG.setPosition(2000,2000);
	//movimiento Nave
	srand(time(NULL));
	movNaveG.x = -1.5+rand()%3;
	movNaveG.y = 1+rand()%1;
	
	//Disparo
	texDisparoG.loadFromFile("imagenes/disparoEnemigoG.png");
	spDisparoG.setTexture(texDisparoG);
	spDisparoG.setPosition(2000,2000);
	spDisparoG.setScale(0.07,0.07);
}
int cont = 0;
int cont2 = 0;
void EnemigoGrande::update(){
	cont++;
	cont2++;
	spNaveG.move(movNaveG);
	
	int aux = rand()%100;
	
	if(cont>30){
		if(aux==20){
			spDisparoG.setPosition(spNaveG.getPosition().x+20, spNaveG.getPosition().y+20);
			cont = 0;
		}
	}
	
	
	//CAMBIO SPRITES EN MOVIMIENTO
//	if(movNaveG.x < 0){
//		spNaveGIzq.setPosition(spNaveG.getPosition().x, spNaveG.getPosition().y);
//		spNaveG = spNaveGIzq;
//	}
//	if(movNaveG.x > 0){
//		spNaveGDer.setPosition(spNaveG.getPosition().x, spNaveG.getPosition().y);
//		spNaveG = spNaveGDer;
//	}
	
	
	//limito movimiento a la pantalla
	Vector2f naveGPos = spNaveG.getPosition();
	if(naveGPos.x<0 && naveGPos.x>-1700){
		naveGPos.x=0;
		movNaveG.x *= -1;
	}
	if(naveGPos.x>1200){
		naveGPos.x=1200;
		movNaveG.x *= -1;
	}
	if(naveGPos.y<0 && naveGPos.y>-1000){
		naveGPos.y=0;
		movNaveG.y *= -0.5;
	}
	if(naveGPos.y>200){
		naveGPos.y=200;
		movNaveG.y *= -0.5;
	}
	spNaveG.setPosition(naveGPos);
	spDisparoG.move(0,15);
	spExplosionNaveG.move(0,4);
	if(cont2>30){
		spExplosionNaveG.setPosition(-2000,-2000);
		cont2=0;
	}
}

void EnemigoGrande::draw(RenderWindow &w){
	w.draw(spNaveG);
	w.draw(spDisparoG);
	w.draw(spExplosionNaveG);
}

Sprite &EnemigoGrande::getSpriteNAVEG(){
	return spNaveG;
}
Sprite &EnemigoGrande::getSpriteDISPAROG(){
	return spDisparoG;
}

bool EnemigoGrande::DisparoGNave(Nave *n){
	FloatRect DispRect = getSpriteDISPAROG().getGlobalBounds();
	FloatRect NaveRect = n->getSpriteNAVE().getGlobalBounds();
	return DispRect.intersects(NaveRect);
}

bool EnemigoGrande::ChocaGNave(Nave *n){
	FloatRect NaveGRect = getSpriteNAVEG().getGlobalBounds();
	FloatRect NaveRect = n->getSpriteNAVE().getGlobalBounds();
	return NaveGRect.intersects(NaveRect);
}

bool EnemigoGrande::EsDestruidaG(Nave *n){
	FloatRect DisparoNaveRect = n->getSpriteDISPARO2().getGlobalBounds();
	FloatRect NaveGRect = getSpriteNAVEG().getGlobalBounds();
	return NaveGRect.intersects(DisparoNaveRect);
}

void EnemigoGrande::DestruyeNaveG(){
	spExplosionNaveG.setPosition(spNaveG.getPosition().x, spNaveG.getPosition().y);
	spNaveG.setPosition(-2000,-2000);
	spDisparoG.setPosition(-2000,-2000);
}
