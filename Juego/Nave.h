#ifndef NAVE_H
#define NAVE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Nave.h"
#include "Entidad.h"
#include <SFML/System/Vector2.hpp>
#include "AsteroideGrande.h"
using namespace sf;
class Nave : public Entidad{
public:
	Nave();
	void update() override;
	void draw(RenderWindow &w) override;
	Sprite &getSpriteNAVE();
	Sprite &getSpriteDISPARO1();
	Sprite &getSpriteDISPARO2();
	bool DisparoAsteroideG(AsteroideGrande *AG);
	void ReposicionarDisparo2();
	void ReposicionarDisparo1();
	bool ChocaAsteroideG(AsteroideGrande *AG);
private:
	Texture texNave;
	Texture texNaveIzq;
	Texture texNaveDer;
	Texture texPropulsion;
	Texture texDisparo1;
	Texture texDisparo2;
	Sprite spNave;
	Sprite spNaveIzq;
	Sprite spNaveDer;
	Sprite spPropulsion;
	Sprite spDisparo1;
	Sprite spDisparo2;
};

#endif

