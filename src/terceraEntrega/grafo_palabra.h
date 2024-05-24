#ifndef GRAFO_PALABRA_H
#define GRAFO_PALABRA_H

#include <vector>
#include <string>
#include <list>

extern bool diccionarioInicializado;
extern std::vector<std::string> palabrasValidas;

class GrafoPalabra {
public:
    GrafoPalabra();
    void construirGrafo();
    void mostrarGrafo();
    std::vector<std::string> posiblesPalabras(const std::string& letrasDisponibles);
    bool grafoConstruido;  // Flag para verificar si el grafo ya ha sido construido

private:
    std::vector<std::list<int>> adyacencias;
    bool sonConectadas(const std::string& palabra1, const std::string& palabra2);
};

#endif
