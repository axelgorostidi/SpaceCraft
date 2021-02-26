#include "EnemigoChico.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics/Rect.hpp>
#include "Nave.h"
using namespace std;
using namespace sf;

EnemigoChico::EnemigoChico() {
	//cargo texturas
	texNaveC.loadFromFile("imagenes/naveEnemigaC.png");
	texNaveCIzq.loadFromFile("imagenes/naveEnemigaCizq.png");
	texNaveCDer.loadFromFile("imagenes/naveEnemigaCder.png");
	texExplosionNaveC.loadFromFile("imagenes/ExplosionNaveC.png");
	
	//creo sprites de la nave
	spNaveC.setTexture(texNaveC);
	spNaveCIzq.setTexture(texNaveCIzq);
	spNaveCDer.setTexture(texNaveCDer);
	spExplosionNaveC.setTexture(texExplosionNaveC);
	
	spNaveC.setScale(1.5,1.5);
	spNaveCIzq.setScale(1.5,1.5);
	spNaveCDer.setScale(1.5,1.5);        
	spExplosionNaveC.setScale(1,1);
	
	srand(time(NULL));
	int posx = rand()%1230; 
	spNaveC.setPosition(posx, 0);
	spExplosionNaveC.setPosition(2000,2000);
	
	//movimiento Nave
	srand(time(NULL));
	movNaveC.x = (-5+rand()%10)+0.5;
	movNaveC.y = 2+rand()%5;
	
	//Disparo
	texDisparoC.loadFromFile("imagenes/disparoEnemigoC.png");
	spDisparoC.setTexture(texDisparoC);
	spDisparoC.setPosition(2000,2000);
	spDisparoC.setScale(2.3,2.3);
}

int cuenta = 0;
int cuenta2 = 0;
void EnemigoChico::update(){
	cuenta++;
	cuenta2++;
	spNaveC.move(movNaveC);
	
	int aux = rand()%100;
	
	if(cuenta>30){
		if(aux==20){
			spDisparoC.setPosition(spNaveC.getPosition().x+20, spNaveC.getPosition().y+20);
			cuenta = 0;
		}
	}
	
	
	//CAMBIO SPRITES EN MOVIMIENTO
		if(movNaveC.x < 0){
			spNaveCIzq.setPosition(spNaveC.getPosition().x, spNaveC.getPosition().y);
			spNaveC = spNaveCIzq;
		}
		if(movNaveC.x > 0){
			spNaveCDer.setPosition(spNaveC.getPosition().x, spNaveC.getPosition().y);
			spNaveC = spNaveCDer;
		}
	
	
	//limito movimiento a la pantalla
	Vector2f naveCPos = spNaveC.getPosition();
	if(naveCPos.x<0 && naveCPos.x>-1700){
		naveCPos.x=0;
		movNaveC.x *= -1;
	}
	if(naveCPos.x>1200){
		naveCPos.x=1200;
		movNaveC.x *= -1;
	}
	if(naveCPos.y<0 && naveCPos.y>-1000){
		naveCPos.y=0;
		movNaveC.y *= -0.5;
	}
	if(naveCPos.y>200){
		naveCPos.y=200;
		movNaveC.y *= -0.5;
	}
	spNaveC.setPosition(naveCPos);
	spDisparoC.move(0,15);
	spExplosionNaveC.move(0,4);
	if(cuenta2>30){
		spExplosionNaveC.setPosition(-2000,-2000);
		cuenta2=0;
	}
}

void EnemigoChico::draw(RenderWindow &w){
	w.draw(spNaveC);
	w.draw(spDisparoC);
	w.draw(spExplosionNaveC);
}

Sprite &EnemigoChico::getSpriteNAVEC(){
	return spNaveC;
}
Sprite &EnemigoChico::getSpriteDISPAROC(){
	return spDisparoC;
}

bool EnemigoChico::DisparoCNave(Nave *n){
	FloatRect DispRect = getSpriteDISPAROC().getGlobalBounds();
	FloatRect NaveRect = n->getSpriteNAVE().getGlobalBounds();
	return DispRect.intersects(NaveRect);
}

bool EnemigoChico::ChocaCNave(Nave *n){
	FloatRect NaveCRect = getSpriteNAVEC().getGlobalBounds();
	FloatRect NaveRect = n->getSpriteNAVE().getGlobalBounds();
	return NaveCRect.intersects(NaveRect);
}

bool EnemigoChico::EsDestruidaC(Nave *n){
	FloatRect DisparoNaveRect = n->getSpriteDISPARO1().getGlobalBounds();
	FloatRect NaveCRect = getSpriteNAVEC().getGlobalBounds();
	return NaveCRect.intersects(DisparoNaveRect);
}

void EnemigoChico::DestruyeNaveC(){
	spExplosionNaveC.setPosition(spNaveC.getPosition().x, spNaveC.getPosition().y);
	spNaveC.setPosition(-2000,-2000);
	spDisparoC.setPosition(-2000,-2000);
}
