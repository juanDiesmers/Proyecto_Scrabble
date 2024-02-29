#ifndef ASIGNACION_H
#define ASIGNACION_H

#include <iostream>
#include <string>
#include <unordered_set>

const int MAX_JUGADORES = 4;

struct Jugadores
{
    std::string nombre;
    int puntaje;
};


void inicializarJuego(const std::string& nombreArchivo);
extern bool diccionarioInicializado;
void inicializarInverso(const std::string& nombreArchivo);
extern bool diccionarioInversoInicializado;
int calcularPuntajePalabra(const std::string& palabra);

#endif // ASIGNACION_H