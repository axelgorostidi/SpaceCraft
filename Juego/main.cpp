#include <SFML/Graphics.hpp>
#include "Juego.h"
#include <SFML/Window/VideoMode.hpp>
#include "EscenaBase.h"
#include "EscenaMenu.h"
using namespace sf;

int main(int argc, char *argv[]){
	EscenaBase *escena = new EscenaMenu();
	Juego &j = Juego::create(VideoMode(1280, 650), escena, "SpaceCraft");
	j.run();
	return 0;
}

