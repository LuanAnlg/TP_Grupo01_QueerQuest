#pragma once
// LLAMAMOS A NUESTRO ENCABEZADO
#include "Encabezado.h"
// LLAMAMOS A NUESTRA CLASE PADRE
#include "Personaje.h"
// DECLARAMOS NUESTRA NUEVA CLASE HEREDADANDO DE LA CLASE PERSONAJE
class Aliado : public Personaje {

private:
	// TODOS SUS VALORES YA SE ENCUENTRAN EN PERSONAJE
public:

	Aliado(short nt, short nc) {
		//SETEAMOS LOS SPRITES, USAMOS SOLO SETEADORES PARA APOYAR AL ENCAPSULAMIENTO
		switch (nt) {
		case 0:
			setS(color(nc),
				"///\\\\",
				"(^v^)",
				" \\-/"
			); break;
		case 1:
			setS(color(nc),
				"//\\\\\\",
				"|^v^|",
				"//-\\\\"
			); break;
		case 2:
			setS(color(nc),
				"///#",
				"|/v^)",
				" |-|"
			); break;
		default: break;
		}
	}

	~Aliado() {} // INICIALIZAMOS NUESTRO DESTRUCTOR
};
