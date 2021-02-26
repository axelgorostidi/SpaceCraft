#ifndef ESCENAPERDER_H
#define ESCENAPERDER_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "EscenaPerder.h"
#include "EscenaBase.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
using namespace std;
using namespace sf;
class EscenaPerder : public EscenaBase {
public:
	EscenaPerder();
	void update();
	void draw(RenderWindow &w);
private:
	
	Texture texfondoGO;
	
	Sprite spfondoGO;
	
	Text PuntajeTexto;				
	Font FuentePuntajeTexto;	
	float Puntaje;
};

#endif

