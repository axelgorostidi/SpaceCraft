#ifndef GLOBAL_HPP
#define GLOBAL_HPP

/***
* Clase para depositar variables globales que necesitan
* accederse a trav�s de las distintas escenas
*/
class Global {
public:
	static int MaxPuntaje;
	static int UltPuntaje;
	Global();
	void getPuntajeMaximo();
	void outPuntajeMaximo();
};

#endif
