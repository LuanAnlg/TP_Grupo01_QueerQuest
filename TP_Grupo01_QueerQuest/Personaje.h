#pragma once
// LLAMAMOS A NUESTRO ENCABEZADO
#include "Encabezado.h"
// DECLARAMOS NUESTRA NUEVA CLASE
class Personaje {

private:

	short x1; // PUNTO X MAS CERCANO AL ORIGEN DEL OBJETO
	short y1; // PUNTO Y MAS CERCANO AL ORIGEN DEL OBJETO
	short x2; // PUNTO X MAS LEJANO AL ORIGEN DEL OBJETO
	short y2; // PUNTO Y MAS LEJANO AL ORIGEN DEL OBJETO
	// NOTA: ESTO SERA MUY UTIL PARA LAS COLICIONES

	sprite s; // SPRITE DEL OBJETO

public:

	Personaje() { // INICIALIZAMOS EN VALORES POR DEFECTO
		
		x1 = 0;
		y1 = 0;
		x2 = 4;
		y2 = 2;
	}

	~Personaje() {} // INICIALIZAMOS NUESTRO DESTRUCTOR

	void setX1(short nx1) { x1 = nx1; } // SETEADOR DE X1 
	void setY1(short ny1) { y1 = ny1; } // SETEADOR DE Y1
	void setX2(short nx2) { x2 = nx2; } // SETEADOR DE X2
	void setY2(short ny2) { y2 = ny2; } // SETEADOR DE Y2
	void setS(std::string nc, std::string nl1, std::string nl2, std::string nl3) { // SETEADOR DEL SPRITE
		
		s.c = nc;
		s.l1 = nl1;
		s.l2 = nl2;
		s.l3 = nl3;
	}

	short getX1() const { return x1; } // GET DE X1
	short getY1() const { return y1; } // GET DE Y1
	short getX2() const { return x2; } // GET DE X2
	short getY2() const { return y2; } // GET DE Y2
	sprite getS() const { return s; }  // GET DE S

	void borrar() { // FUNCION GENERICA PARA BORRAR PERSONAJES

		for (int b = 0; b < 3; b++) {
			System::Console::SetCursorPosition(x1, y1 + b); std::cout << "     ";
		}
	}

	void dibujar() { // FUNCION GENERICA PARA DIBUJAR PERSONAJES

		System::Console::SetCursorPosition(x1, y1); std::cout << s.c << s.l1;
		System::Console::SetCursorPosition(x1, y1 + 1); std::cout << s.l2;
		System::Console::SetCursorPosition(x1, y1 + 2); std::cout << s.l3 << s.r;
	}
};