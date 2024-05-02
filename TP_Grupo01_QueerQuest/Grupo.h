#pragma once
// LLAMAMOS A NUESTRO ENCABEZADO
#include "Encabezado.h"
// LLAMAMOS A LAS CLASES QUE VA A CONTENER NUESTRA NUEVA CLASE GRUPO
#include "Personaje.h"
#include "Protagonista.h"
#include "Aliado.h"
// DECLARAMOS NUESTRA NUEVA CLASE
class Grupo {

private:
	// DECLARAMOS UN VECTOR DE PUNTEROS TIPO PERSONAJE
	std::vector<Personaje*>* vecGrupo;
	// DECLARAMOS UN CONTADOR DE ALIADOS
	short aliados;

public:

	Grupo() { // INICIALIZAMOS EL VECTOR Y LO RELLENAMOS CON UN PROTAGONISTA
		
		vecGrupo = new std::vector<Personaje*>;
		vecGrupo->push_back(new Protagonista);
		aliados = 0;
	}

	~Grupo() { // DESTRUCTOR CON ITERACION

		for (int i = 0; i < vecGrupo->size(); ++i) {
			delete vecGrupo->at(i);
		}
		vecGrupo->clear();
		delete vecGrupo;
	}

	void agregar(short t) { // AGREGAMOS A UN ALIADO Y LO COLOCAMOS EN LA ULTIMA POSICION DEL ANTERIOR ALIADO

		if (aliados > -1) {
			vecGrupo->push_back(new Aliado(t, aliados % 6));
			vecGrupo->at(aliados + 1)->setX1(vecGrupo->at(aliados)->getX1());
			vecGrupo->at(aliados + 1)->setY1(vecGrupo->at(aliados)->getY1());
			aliados++;
		}
	}

	void eliminar() { // BORRAMOS, ELIMINAR Y REDUCIMOS LA CANTIDAD DE ALIADOS

		if (vecGrupo->size() > 1) {
			vecGrupo->at(aliados)->borrar();
			vecGrupo->erase(vecGrupo->end() - 1);
			aliados--;
		}
	}

	void borrar() { // FUNCION PARA BORRAR A TODOS LOS PERSONAJES DEL VECTOR

		for (int i = 0; i < vecGrupo->size(); i++) {
			vecGrupo->at(i)->borrar();
		}
	}

	void mover(short dx, short dy) { // FUNCION PARA MOVER A TODOS LOS PERSONAJES DEL VECTOR
		// MOVEMOS AL LOS ALIADOS
		for (int i = vecGrupo->size() - 1; i >= 1; i--) {
			vecGrupo->at(i)->setX1(vecGrupo->at(i - 1)->getX1());
			vecGrupo->at(i)->setY1(vecGrupo->at(i - 1)->getY1());
		}
		// MOVEMOS AL PROTAGONISTA
		vecGrupo->at(0)->setX1(vecGrupo->at(0)->getX1() + dx);
		vecGrupo->at(0)->setY1(vecGrupo->at(0)->getY1() + dy);
		vecGrupo->at(0)->setX2(vecGrupo->at(0)->getX1() + 4);
		vecGrupo->at(0)->setY2(vecGrupo->at(0)->getY1() + 2);
		// TELETRANSPORTAMOS AL GRUPO SI LLEGA A UN LIMITE
		if (vecGrupo->at(0)->getY1() < 0) {
			vecGrupo->at(0)->setY1(VY - 2);
			vecGrupo->at(0)->setY2(vecGrupo->at(0)->getY1() + 2);
		}
		if (vecGrupo->at(0)->getY2() > VY) {
			vecGrupo->at(0)->setY1(0);
			vecGrupo->at(0)->setY2(vecGrupo->at(0)->getY1() + 2);
		}
		if (vecGrupo->at(0)->getX1() < 0) {
			vecGrupo->at(0)->setX1(VX - 4);
			vecGrupo->at(0)->setX2(vecGrupo->at(0)->getX1() + 4);
		}
		if (vecGrupo->at(0)->getX2() > VX) {
			vecGrupo->at(0)->setX1(0);
			vecGrupo->at(0)->setX2(vecGrupo->at(0)->getX1() + 4);
		}
	}

	void dibujar() { // FUNCION PARA DIBUJAR TODOS LOS PERSONAJES DEL VECTOR

		for (int i = 0; i < vecGrupo->size(); i++) {
			vecGrupo->at(i)->dibujar();
		}
	}

	Personaje* getProtagonista() const { return vecGrupo->at(0); } // GET PARA ACCEDER AL PROTAGONISTA

	short getAliados() const { return aliados; } // GET PARA ACCEDER A LA CANTIDAD DE ALIADOS
};
