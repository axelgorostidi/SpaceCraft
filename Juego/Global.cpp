#include "Global.h"
#include <fstream>
#include <ios>
using namespace std;
	int Global::MaxPuntaje;
	int Global::UltPuntaje = 0;

Global::Global(){

}

void Global::getPuntajeMaximo(){
	int aux;
	ifstream archiL("highscore/highscore.txt");
	archiL>>aux;
	Global::MaxPuntaje = aux;
	archiL.close();
	

}

void Global::outPuntajeMaximo(){
		int aux = Global::MaxPuntaje;
		ofstream archiE("highscore/highscore.txt", ios::trunc);
		archiE<<aux;
		archiE.close();
}

