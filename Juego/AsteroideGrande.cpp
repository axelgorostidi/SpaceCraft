#include "AsteroideGrande.h"
#include <cstdlib>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <ctime>
using namespace std;
using namespace sf;
AsteroideGrande::AsteroideGrande() {
	texAsteroideGrande.loadFromFile("imagenes/AGmarron.png");
	texExplosion.loadFromFile("imagenes/Explosion.png");
	
	spAsteroideGrande.setTexture(texAsteroideGrande);

	spExplosion.setTexture(texExplosion);
	spExplosion.setPosition(2000,2000);
	
	
	spAsteroideGrande.setPosition(rand()%1280,-200);
	spAsteroideGrande.setScale(0.35,0.35);
	srand(time(0));
	movAS.x = 0;
	movAS.y = 3+rand()%10;

	spExplosion.setScale(0.3,0.3);
}
int contador=0;
void AsteroideGrande::update(){
contador++;
	spAsteroideGrande.move(movAS);
	spExplosion.move(movAS);
	if(contador>30){
	spExplosion.setPosition(-2000,-2000);
	contador=0;
	}
}	
void AsteroideGrande::draw(RenderWindow &w){
	w.draw(spAsteroideGrande);
	w.draw(spExplosion);
}
Sprite &AsteroideGrande::getSprite(){
	return spAsteroideGrande;
}

void AsteroideGrande::DestruyeAsteroideG(){
	spExplosion.setPosition(spAsteroideGrande.getPosition().x, spAsteroideGrande.getPosition().y);
	spAsteroideGrande.setPosition(0,1000);
	
}

/*bool pasaLimite(*/
//bool AsteroideGrande::Limite(){
//	Vector2f pos;
//	pos = spAsteroideGrande.getPosition();
//int lim = 400;
//	if(pos.y>lim){
//		return true;
//	}
//}

