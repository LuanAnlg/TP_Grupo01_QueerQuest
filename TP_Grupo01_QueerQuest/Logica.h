#pragma once
// LLAMAMOS A LAS CLASES QUE VAMOS A UTILIZAR
#include "Grupo.h"
#include "Enemigo.h"
#include "Trivia.h"

class Logica {

private:
    // DECLARAMOS LOS PUNTEROS DE NUESTRAS CLASES
    Grupo* grupo;
    Trivia* trivia;
    Enemigo* enemigo;
    
    short dx; // DIRECCION EN EL EJE X
    short dy; // DIRECCION EN EL EJE Y
    short musica; // ITERADOR DE LA MUSICA
    char tecla; // TECLA INPUT
    short tr; // tRIVIA RESULTADO
    bool c; // CONTINUAR?

    bool AABBcolision(Personaje* pro, Enemigo* ene) { // FUNCION PRIVADA COLISION

        bool estaDerecha = pro->getX1() > ene->getX2();
        bool estaIzquierda = pro->getX2() < ene->getX1();
        bool estaArriba = pro->getY2() < ene->getY1();
        bool estaAbajo = pro->getY1() > ene->getY2();
        return !(estaDerecha || estaIzquierda || estaArriba || estaAbajo);
    }

    void reproducir(short& m) { // FUNCION PRIVADA REPRODUCTOR DE MUSICA DE FONDO 

        std::vector<std::vector<double>> acordes = { // MATRIZ DE ACORDES
            {261.63, 329.63, 392.00},   // C
            {220.00, 261.63, 329.63},   // AM
            {349.23, 440.00, 523.25},   // F
            {392.00, 493.88, 587.33}    // G
        };

        if (m >= 23) {
            m = 0;
        }
        else { m++; }

        int a = m / 6;
        int n = m % 6;

        Beep(acordes[a][n % 3], 250); // EL TIEMPO DE BEEP TAMBIEN SIRVE COMO UN SLEEP
    }

    void entrada() { // FUNCION PRIVADA INPUT Y CAMBIO DE DIRECCION DE GRUPO

        if (_kbhit()) {
            tecla = std::toupper(_getch());
            switch (tecla) {
            case 'W': dx = 0; dy = -3;   break;
            case 'S': dx = 0; dy = 3;    break;
            case 'A': dx = -5; dy = 0;   break;
            case 'D': dx = 5; dy = 0;    break;
            default:                     break;
            }
        }
    }

    void limpiar() { // FUNCION PRIVADA LIMPIAR PANTALLA

        grupo->borrar();
    }

    void actualizar() { // FUNCION PRIVADA ACTUZALIZAR VALORES Y EVENTOS

        if (trivia->getPreguntas() == 0) { // SI YA NO HAY PREGUNTAS, YA NO SE CONTINUA
            c = false;
        }

        if (AABBcolision(grupo->getProtagonista(), enemigo)) {
            enemigo->borrar();
            tr = trivia->preguntar();
            switch (tr) {
            case 0:
                grupo->agregar(enemigo->getTipo());
                enemigo->reposicionar();
                break;
            case 1:
                if (grupo->getAliados() == 0) {
                    c = false;
                } else {
                    grupo->eliminar();
                    enemigo->reposicionar();
                }
                break;
            case 2:
            case -1:
                c = false;
                break;
            }
        }

        grupo->mover(dx, dy);
    }
    void renderizar() { // FUNCION PRIVADA RENDERIZADO DE LA PANTALLA

        System::Console::SetCursorPosition(1, 1); std::cout << "PUNTAJE: " << grupo->getAliados() * 100;

        grupo->dibujar();

        if (!AABBcolision(grupo->getProtagonista(), enemigo)) {
            enemigo->dibujar();
        }
    }

public:

    Logica(short p) { // CONTRUCTOR CON ARGUMENTO p: CANTIDAD DE pREGUNTAS

        grupo = new Grupo;
        enemigo = new Enemigo;
        dx = 0;
        dy = 0;
        musica = 0;
        trivia = new Trivia(p);
        tr = -2;
        c = true;
    }

    ~Logica() { // DESCTRUCTOR DE TODOS LOS PUNTEROS

        delete enemigo;
        delete trivia;
        delete grupo;
    }

    int juego() { // FUNCION BUCLE DE JUEGO

        while (true) {
            entrada();
            limpiar();
            actualizar();
            if (!c) { system("cls");  break; } // TERMINAMOS EL BUCLE
            renderizar();
            reproducir(musica); // TAMBIEN SIVE COMO SLEEP
        }
        return grupo->getAliados() * 100; // RETORNAMOS LOS PUNTOS
    }
};