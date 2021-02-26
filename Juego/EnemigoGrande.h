#ifndef ENEMIGOGRANDE_H
#define ENEMIGOGRANDE_H
#include "Entidad.h"
#include "Nave.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class EnemigoGrande : public Entidad {
public:
	EnemigoGrande();
	void update() override;
	void draw(RenderWindow &w) override;
	Sprite &getSpriteNAVEG();
	Sprite &getSpriteDISPAROG();
	bool DisparoGNave(Nave *n);
	bool ChocaGNave(Nave *n);
	bool EsDestruidaG(Nave *n);
	void DestruyeNaveG();
	
private:
	Texture texNaveG;
	Texture texNaveGIzq;
	Texture texNaveGDer;
	Texture texDisparoG;
	Texture texExplosionNaveG;
	
	Vector2f movNaveG;
	
	Sprite spNaveG;
	Sprite spNaveGIzq;
	Sprite spNaveGDer;
	Sprite spDisparoG;
	Sprite spExplosionNaveG;
};

#endif

