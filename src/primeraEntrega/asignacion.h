#ifndef ASIGNACION_H
#define ASIGNACION_H

#include <iostream>
#include <string>

const int MAX_JUGADORES = 4;

void inicializarJuego(const std::string& nombreArchivo);
extern bool diccionarioInicializado;
void inicializarInverso(const std::string& nombreArchivo);
extern bool diccionarioInversoInicializado;
void  puntajePalabra(const std::string& palabra);
int calcularPuntajePalabra(const std::string& palabra);

#endif // ASIGNACION_H