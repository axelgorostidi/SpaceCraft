#include "EscenaJuego.h"
#include "Fondo.h"
#include "EscenaBase.h"
#include <cstdlib>
#include "AsteroideGrande.h"
#include "Nave.h"
#include "Juego.h"
#include "EscenaPerder.h"
#include "EnemigoGrande.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "EnemigoChico.h"
#include <SFML/Graphics/Color.hpp>
#include <sstream>
#include <SFML/Graphics/Text.hpp>
#include "Global.h"
using namespace std;
using namespace sf;

EscenaJuego::EscenaJuego() {
	//Creo el fondo
	Fondo *f= new Fondo();
	agregar(f);
	//Creo la Nave
	agregar(n);
	
	FuentePuntajeTexto.loadFromFile("fuentes/Gravedigger.otf");
	Puntaje = 0;
	PuntajeTexto.setFont(FuentePuntajeTexto);
	PuntajeTexto.setColor(Color::White);
	texLimite.loadFromFile("imagenes/limite.png");
	spLimite.setTexture(texLimite);
	spLimite.setPosition(0,1000);
}
int esperar=0;
int esperar2=500;
int esperar3 = 100;
int tiempo = 0;
void EscenaJuego::update(){
	EscenaBase::update();
	
	int a = rand()%100;
	tiempo++;
	esperar++;
	esperar2++;
	esperar3++;
	if(esperar>400){
		if(a==20){
			CrearAsteroideGrande();
			esperar=0;
		}
	}
	
	if(esperar2>1000){
		if(a==40){
			CrearEnemigoGrande();
			esperar2=0;
		}
	}
	
	if(esperar3>200){
		if(a==50){
			CrearEnemigoChico();
			esperar3=0;
		}
	}
	
	for(const auto &AsteroideGrande : AsteroidesGrandes){
		if(n->DisparoAsteroideG(AsteroideGrande)){
			AsteroideGrande->DestruyeAsteroideG();
			eliminar(AsteroideGrande);
			n->ReposicionarDisparo2();
			Puntaje += 10;
			Global::UltPuntaje = Puntaje;
		}
		if(n->ChocaAsteroideG(AsteroideGrande)){
			esperar=0;
			esperar2=0;
			esperar3=0;
			tiempo=0;
			Juego::getInstancia().CambiarEscena(new EscenaPerder());
		}
		if(AsteroideGPasaLimite(AsteroideGrande)){
			eliminar(AsteroideGrande);
		}
		
	}
	for(const auto &EnemigoGrande : EnemigosGrandes){
		if(EnemigoGrande->EsDestruidaG(n)){
			EnemigoGrande->DestruyeNaveG();
			n->ReposicionarDisparo2();
			eliminar(EnemigoGrande);
			Puntaje += 25;
			Global::UltPuntaje = Puntaje;
		}
		if(EnemigoGrande->DisparoGNave(n)){
			esperar=0;
			esperar2=0;
			esperar3=0;
			tiempo=0;
			Juego::getInstancia().CambiarEscena(new EscenaPerder());
		}
		if(EnemigoGrande->ChocaGNave(n)){
			esperar=0;
			esperar2=0;
			esperar3=0;
			tiempo=0;
			Juego::getInstancia().CambiarEscena(new EscenaPerder());
		}
	}
	for(const auto &EnemigoChico : EnemigosChicos){
		if(EnemigoChico->EsDestruidaC(n)){
			EnemigoChico->DestruyeNaveC();
			n->ReposicionarDisparo1();
			eliminar(EnemigoChico);
			Puntaje += 10;
			Global::UltPuntaje = Puntaje;
		}
		if(EnemigoChico->DisparoCNave(n)){
			esperar=0;
			esperar2=0;
			esperar3=0;
			tiempo=0;
			Juego::getInstancia().CambiarEscena(new EscenaPerder());
		}
		if(EnemigoChico->ChocaCNave(n)){
			esperar=0;
			esperar2=0;
			esperar3=0;
			tiempo=0;
			Juego::getInstancia().CambiarEscena(new EscenaPerder());
		}
	}
	//Actualizo puntaje
	stringstream tmp;
	tmp<<"SCORE: "<<int(Puntaje);
	PuntajeTexto.setString(tmp.str());
	
	if(tiempo>3000 && tiempo<5000){
		esperar2+=300;
		esperar3+=75;
	}
	
	if(tiempo>5000 && tiempo<7000){
		esperar2+=600;
		esperar3+=150;
	}
	
	if(tiempo>7000){
		esperar2+=800;
		esperar3+=200;
	}
}
void EscenaJuego::draw(RenderWindow &w){
	EscenaBase::draw(w);
	w.draw(spLimite);
	w.draw(PuntajeTexto);
}

void EscenaJuego::CrearAsteroideGrande(){
	AsteroideGrande *a= new AsteroideGrande();
	AsteroidesGrandes.push_back(a);
	agregar(a);
}

bool EscenaJuego::AsteroideGPasaLimite(AsteroideGrande *AG){
	FloatRect LimiteRect = spLimite.getGlobalBounds();
	FloatRect AstRect = AG->getSprite().getGlobalBounds();
	return LimiteRect.intersects(AstRect);
}

void EscenaJuego::CrearEnemigoGrande(){
	EnemigoGrande *EG = new EnemigoGrande();
	EnemigosGrandes.push_back(EG);
	agregar(EG);
}

void EscenaJuego::CrearEnemigoChico(){
	EnemigoChico *EC = new EnemigoChico();
	EnemigosChicos.push_back(EC);
	agregar(EC);
}


