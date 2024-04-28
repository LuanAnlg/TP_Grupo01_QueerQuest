#pragma once
// LLAMAMOS A NUESTRO ENCABEZADO
#include "Encabezado.h"
// LLAMAMOS A NUESTRA CLASE PADRE
#include "Personaje.h"
// DECLARAMOS NUESTRA NUEVA CLASE HEREDADANDO DE LA CLASE PERSONAJE
class Enemigo : public Personaje {

private:

	short tipo; // TIPO DE PERSONAJE

	void setEnemigo() { // FUNCION SETEADORA AUTOMATICA PRIVADA PARA NO DUPLICAR CODIGO

		tipo = aleatorio(0, 2); // ASIGNACION ALEATORIA DE TIPO
		//SETEAMOS LOS PUNTOS, USAMOS SOLO SETEADORES PARA APOYAR AL ENCAPSULAMIENTO
		setX1(aleatorio(0, VX - 4));
		setY1(aleatorio(0, VY - 2));
		setX2(getX1() + 4);
		setY2(getY1() + 2);
		// SWITCH PARA SETEAR LOS SPRITES SEGUN EL TIPO DE ENEMIGO
		switch (tipo) {
		case 0:
			setS(GRIS,
				"///\\\\",
				"('-')",
				" \\-/"
			); break;
		case 1:
			setS(GRIS,
				"//\\\\\\",
				"|'-'|",
				"//-\\\\"
			); break;
		case 2:
			setS(GRIS,
				"///#",
				"|/-')",
				" |-|"
			); break;
		default: break;
		}
	}

public:

	Enemigo() { // INICIALIZAMOS EL CONSTRUCTOR CON LA FUNCION SETEADOR AUTOMATICO

		setEnemigo();
	}

	~Enemigo() {} // INICIALIZAMOS NUESTRO DESTRUCTOR

	void reposicionar() { // REPOSICIONAMOS CON LA FUNCION SETEADOR AUTOMATICO

		setEnemigo();
	}

	short getTipo() const { return tipo; } // GET DEL TIPO DE ENEMIGO
};