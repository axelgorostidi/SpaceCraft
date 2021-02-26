#ifndef ASTEROIDEGRANDE_H
#define ASTEROIDEGRANDE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entidad.h"
using namespace sf;
class AsteroideGrande : public Entidad {
public:
	AsteroideGrande();
	void update() override;
	void draw(RenderWindow &w) override;
	Sprite &getSprite();
	Vector2f movAS;
	void DestruyeAsteroideG();
	bool EstaDestruido();
	//bool Limite();

private:
	Texture texAsteroideGrande;
	Sprite spAsteroideGrande;
	Texture texExplosion;
	Sprite spExplosion;
};

#endif

