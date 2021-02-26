 #ifndef ESCENAJUEGO_H
#define ESCENAJUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "EscenaJuego.h"
#include "AsteroideGrande.h"
#include "Nave.h"
#include "EscenaBase.h"
#include "EnemigoGrande.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "EnemigoChico.h"
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
using namespace sf;
using namespace std;
class EscenaJuego : public EscenaBase {
public:
	EscenaJuego();
	void update();
	void draw(RenderWindow &w);
	bool AsteroideGPasaLimite(AsteroideGrande *AG);
	
private:
	Nave *n = new Nave();
	vector<AsteroideGrande *> AsteroidesGrandes;
	vector<EnemigoGrande *> EnemigosGrandes;
	vector<EnemigoChico *> EnemigosChicos;
	void CrearAsteroideGrande();
	void CrearEnemigoGrande();
	void CrearEnemigoChico();
	
	
	Texture texLimite;
	Sprite spLimite;
	
	Text PuntajeTexto;				
	Font FuentePuntajeTexto;	
	float Puntaje;
	
};

#endif

