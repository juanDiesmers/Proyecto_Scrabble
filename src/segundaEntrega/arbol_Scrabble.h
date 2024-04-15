#ifndef ARBOL_SCRABBLE_H
#define ARBOL_SCRABBLE_H

#include <string>
#include <vector>

class Nodo {
public:
    Nodo* hijos[26]; // Array para almacenar los hijos del nodo (asumiendo solo letras minúsculas del alfabeto inglés)
    bool esFinal; // Indica si el nodo es el último de una palabra

    Nodo(); // Constructor
};

class Arbol_Scrabble {
private:
    Nodo* raiz; // Puntero a la raíz del árbol

    // Funciones privadas para insertar palabras y auxiliares
    void insertarPalabra(const std::string& palabra);
    void insertarPalabraInversa(const std::string& palabra);
    void insertarPalabraAux(Nodo* nodo, const std::string& palabra, size_t indice);

public:
    Arbol_Scrabble();

    // Funciones pubicas para iniciar el arbol
    void iniciarArbol(const std::string& nombreArchivo);
    void iniciarArbolInv(const std::string& nombreArchivo);

};

#endif // ARBOL_SCRABBLE_H