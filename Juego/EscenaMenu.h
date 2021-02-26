#ifndef ESCENAMENU_H
#define ESCENAMENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "EscenaBase.h"
#include "EscenaMenu.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Global.h"
using namespace sf;
class EscenaMenu : public EscenaBase{
public:
	EscenaMenu();
	void update();
	void draw(RenderWindow &w);
private:

	
	Texture texNave1;
	Texture texNave2;
	Texture texMenu;
	
	Sprite spNave1;
	Sprite spNave2;
	Sprite spMenu;
	
	Text PuntajeTexto;				
	Font FuentePuntajeTexto;	
	float Puntaje;
};

#endif

