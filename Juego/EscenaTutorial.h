#ifndef ESCENATUTORIAL_H
#define ESCENATUTORIAL_H
#include "EscenaBase.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "EscenaTutorial.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace std;
using namespace sf;
class EscenaTutorial : public EscenaBase {
public:
	EscenaTutorial();
	void update();
	void draw(RenderWindow &w);
private:
	Texture texTutorial;
	
	Sprite spTutorial;
};

#endif

