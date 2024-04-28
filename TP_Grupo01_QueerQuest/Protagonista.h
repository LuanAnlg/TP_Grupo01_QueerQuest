#pragma once
// LLAMAMOS A NUESTRO ENCABEZADO
#include "Encabezado.h"
// LLAMAMOS A NUESTRA CLASE PADRE
#include "Personaje.h"
// DECLARAMOS NUESTRA NUEVA CLASE HEREDADANDO DE LA CLASE PERSONAJE
class Protagonista : public Personaje {

private:
	// TODOS SUS VALORES YA SE ENCUENTRAN EN PERSONAJE
public:

	Protagonista() {
		//SETEAMOS LOS PUNTOS Y SPRITES, USAMOS SOLO SETEADORES PARA APOYAR AL ENCAPSULAMIENTO
		setX1((VX - 5) / 2);
		setY1((VY - 3) / 2);
		setX2(getX1() + 4);
		setY2(getY1() + 2);
		setS(BLANCO,
			"!___!",
			"|* *|",
			" \\+/"
		);
	}

	~Protagonista() {} // INICIALIZAMOS NUESTRO DESTRUCTOR
};