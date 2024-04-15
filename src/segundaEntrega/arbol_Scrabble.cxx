#include "arbol_Scrabble.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

// Contrucotr de la clase Nodo
Nodo::Nodo() {
    for (int i = 0; i < 26; i++) {
        hijos[i] = nullptr;
    }
    esFinal = false;
}

// Constructor de la clase Arbol_Scrabble
Arbol_Scrabble::Arbol_Scrabble() {
    raiz = new Nodo();
}

// Funcion privada para insertar palabras en el arbol
void Arbol_Scrabble::insertarPalabra(const std::string& palabra) {
    insertarPalabraAux(raiz, palabra, 0);
}

// Función privada para insertar una palabra invertida en el árbol
void Arbol_Scrabble::insertarPalabraInversa(const std::string& palabra) {
    std::string palabraInversa(palabra.rbegin(), palabra.rend());
    insertarPalabraAux(raiz, palabraInversa, 0);
}

// Función privada auxiliar para insertar una palabra en el árbol
void Arbol_Scrabble::insertarPalabraAux(Nodo* nodo, const std::string& palabra, size_t indice) {
    if (indice == palabra.length()) {
        nodo->esFinal = true;
        return;
    }

    char letra = palabra[indice];
    int indiceHijo = letra - 'a';

    if (!nodo->hijos[indiceHijo]) {
        nodo->hijos[indiceHijo] = new Nodo();
    }

    insertarPalabraAux(nodo->hijos[indiceHijo], palabra, indice + 1);
}

// Función pública para inicializar el árbol con palabras del archivo
void Arbol_Scrabble::iniciarArbol(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "(Archivo no existe) El archivo " << nombreArchivo << " no existe o no puede ser leído" << std::endl;
        return;
    }

    std::string palabra;
    while (archivo >> palabra) {
        // Transformar la palabra a minúsculas
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        
        // Verificar si la palabra contiene solo letras válidas
        bool palabraValida = true;
        for (char c : palabra) {
            if (!std::isalpha(c)) {
                palabraValida = false;
                break;
            }
        }

        // Insertar la palabra en el árbol si es válida
        if (palabraValida) {
            insertarPalabra(palabra);
        }
    }

    std::cout << "(Resultado exitoso) El árbol del diccionario se ha inicializado correctamente." << std::endl;
}

// Función pública para inicializar el árbol inverso con palabras del archivo
void Arbol_Scrabble::iniciarArbolInv(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "(Archivo no existe) El archivo " << nombreArchivo << " no existe o no puede ser leído" << std::endl;
        return;
    }

    std::string palabra;
    while (archivo >> palabra) {
        // Transformar la palabra a minúsculas
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        
        // Verificar si la palabra contiene solo letras válidas
        bool palabraValida = true;
        for (char c : palabra) {
            if (!std::isalpha(c)) {
                palabraValida = false;
                break;
            }
        }

        // Insertar la palabra invertida en el árbol si es válida
        if (palabraValida) {
            insertarPalabraInversa(palabra);
        }
    }

    std::cout << "(Resultado exitoso) El árbol del diccionario inverso se ha inicializado correctamente." << std::endl;
}