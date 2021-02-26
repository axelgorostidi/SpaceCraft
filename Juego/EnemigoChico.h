#ifndef ENEMIGOCHICO_H
#define ENEMIGOCHICO_H
#include "Entidad.h"
#include "Nave.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class EnemigoChico : public Entidad{
public:
	EnemigoChico();
	void update() override;
	void draw(RenderWindow &w) override;
	Sprite &getSpriteNAVEC();
	Sprite &getSpriteDISPAROC();
	bool DisparoCNave(Nave *n);
	bool ChocaCNave(Nave *n);
	bool EsDestruidaC(Nave *n);
	void DestruyeNaveC();
private:
	
	Texture texNaveC;
	Texture texNaveCIzq;
	Texture texNaveCDer;
	Texture texDisparoC;
	Texture texExplosionNaveC;
	
	Vector2f movNaveC;
	
	Sprite spNaveC;
	Sprite spNaveCIzq;
	Sprite spNaveCDer;
	Sprite spDisparoC;
	Sprite spExplosionNaveC;
};

#endif

