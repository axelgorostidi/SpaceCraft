#ifndef FONDO_H
#define FONDO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entidad.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
class Fondo : public Entidad {
public:
	Fondo();
	void update() override;
	void draw(RenderWindow &w);
	Sprite &getSprite();
private:
	Texture texFondo;
	Sprite spFondo;
};

#endif

