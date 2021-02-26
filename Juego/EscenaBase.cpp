#include "EscenaBase.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entidad.h"
#include <algorithm>
using namespace std;
using namespace sf;

EscenaBase::EscenaBase() {
	
}

void EscenaBase::update(){
	for(auto e: entidades){
		e->update();
	}


for(auto b: a_borrar){
	auto it = find(entidades.begin(), entidades.end(), b);
	if(it!=entidades.end()){
		entidades.erase(it);
	}
	}
	a_borrar.clear();
}

void EscenaBase::draw(RenderWindow &w){
	for(auto e: entidades){
		e->draw(w);
	}
}

void EscenaBase::agregar(Entidad *e){
	entidades.push_back(e);
}

void EscenaBase::eliminar(Entidad *e){
	a_borrar.push_back(e);
}
