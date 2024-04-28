#pragma once
// BIBLIOTECAS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <string>
#include <conio.h>

// DEFINICION DE LOS LIMITES DE LA PANTALLA POR DEFECTO
#define VX 119
#define VY 29

// DEFINICION DE LOS COLORES EN CONSOLA
#define REINICIO     "\033[0m"
#define BLANCO       "\033[0m"
#define ROJO         "\033[31m"
#define NARANJA      "\033[38;5;208m"
#define AMARILLO     "\033[33m"
#define VERDE        "\033[32m"
#define AZUL         "\033[34m"
#define VIOLETA      "\033[35m" 
#define GRIS         "\033[90m"

// FUNCION PARA GENERAR NUMERO ALEATORIOS
short aleatorio(short min, short max) {

	return min + std::rand() % (max - min + 1);
}

// ESTRUCTURA PARA DECLARAR SPRITES CON STRINGS
struct sprite {

	std::string c = BLANCO;
	std::string l1 = "     ";
	std::string l2 = "     ";
	std::string l3 = "     ";
	std::string r = REINICIO;
};

// FUNCION SWITCH PARA SELECCIONAR LOS COLORES
std::string color(short c) {

	switch (c) {
	case 0: return ROJO;     break;
	case 1: return NARANJA;  break;
	case 2: return AMARILLO; break;
	case 3: return VERDE;    break;
	case 4: return AZUL;     break;
	case 5: return VIOLETA;  break;
	default:return BLANCO;   break;
	}
	return BLANCO;
}