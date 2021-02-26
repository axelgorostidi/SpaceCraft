#ifndef ESCENABASE_H
#define ESCENABASE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entidad.h"
#include <vector>
#include "Global.h"
using namespace std;
using namespace sf;
class EscenaBase {
public:
	EscenaBase();
	
	virtual void update();
	
	virtual void draw(RenderWindow &w);
	
	void agregar(Entidad *e);
	
	void eliminar(Entidad *e);
	
	Global *g = new Global();
private:
	
	vector<Entidad *> entidades;
	vector<Entidad *> a_borrar;
};

#endif

