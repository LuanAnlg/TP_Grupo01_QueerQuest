#pragma once
// LLAMAMOS A NUESTRO ENCABEZADO
#include "Encabezado.h"
// LLAMAMOS A LA CLASE QUE VA A CONTENER NUESTRA NUEVA CLASE TRIVIA
#include "Pregunta.h"
// DECLARAMOS NUESTRA NUEVA CLASE
class Trivia {

private:

    short pt; // CANTIDAD DE pREGUNTAS DE LA tRIVIA
    char tecla; // TECLA DE INPUT
    // DECLARAMOS UN VECTOR DE PUNTEROS TIPO PREGUNTA
    std::vector<Pregunta*>* vecPreguntas;
    std::vector<bool>* noRepetir;

public:

    Trivia(short cantidad) { // INICIALIZAMOS EL VECTOR Y RELLENAMOS EL VECTOR CON PREGUNTAS
                             //(LE DAMOS VALOR A pt CON EL ARGUMENTO cantidad)
        vecPreguntas = new std::vector<Pregunta*>;
        noRepetir = new std::vector<bool>;
        for (int p = 0; p < 30; p++) {
            vecPreguntas->push_back(new Pregunta(p));
        }
        for (int n = 0; n < 30; n++) {
            noRepetir->push_back(0);
        }

        pt = cantidad;
    }

    ~Trivia() { // DESTRUCTOR CON ITERACION

        for (int i = 0; i < vecPreguntas->size(); ++i) {
            delete vecPreguntas->at(i);
        }
        vecPreguntas->clear();
        delete vecPreguntas;

        noRepetir->clear();
        delete noRepetir;
    }

    short preguntar() { // FUNCION PREGUNTAR
        
        short r = -1;

        if (pt > 0) {

            short ip;

            do {
                ip = aleatorio(0, 29);
            } while (noRepetir->at(ip));

            for (int t = 60; t > 0; t--) {
                vecPreguntas->at(ip)->imprimirPregunta();
                Beep(1000, 100);

                if (_kbhit()) {
                    tecla = std::toupper(_getch());
                    if (tecla == vecPreguntas->at(ip)->getRespuesta()) {
                        r = 0;
                        break;
                    }
                    else if (tecla == 'R') {
                        r = 1;
                        break;
                    }
                    else { break; }
                }

                Sleep(900);
            }

            if (r == -1) {
                r = 2;
            }
            // r = 0: RESPUSTA CORRECTA
            // r = 1: SACRIFICIO DE ALIADO
            // r = 2: NO RESPONDER DENTREO DE 60 SEGUNDOS

            system("cls");
            vecPreguntas->at(ip)->imprimirRespuesta();
            system("pause>0");
            system("cls");
            vecPreguntas->erase(vecPreguntas->begin() + ip);
            noRepetir->at(ip) = 1;
            pt--;
        }
        return r;
    }

    short getPreguntas() const { return pt; } // GET DE LA CANTIDAD DE PREGUNTAS RESTANTES
};