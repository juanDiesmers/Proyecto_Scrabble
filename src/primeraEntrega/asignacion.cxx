#include "asignacion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <utility>



bool diccionarioInicializado = false;
std::vector<std::string> palabrasValidas;

bool diccionarioInversoInicializado = false;
std::vector<std::string> palabrasValidasInverso;

const std::vector<std::string>& obtenerDiccionario() {
    return palabrasValidas;
}

const std::vector<std::string>& obtenerDiccionarioInverso() {
    return palabrasValidasInverso;
}

void imprimirDiccionario(const std::vector<std::string>& diccionario) {
    std::cout << "Diccionario:" << std::endl;
    for (const std::string& palabra : diccionario) {
        std::cout << palabra << std::endl;
    }
}

void inicializarJuego(const std::string& nombreArchivo) {
    if ( !palabrasValidas.empty()) {
        std::cout << "(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << std::endl;
        return;
    }
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "(Archivo no existe) EL archivo " << nombreArchivo << " no Existe o no puede ser leido" << std::endl;
        return;
    }
    std::string palabra;
    while (archivo >> palabra) {
        // Verificar si la palabra es válida
        bool palabraValida = std::all_of(palabra.begin(), palabra.end(), [](char c) { return std::isalpha(c); });

        // Convertir la palabra a minúsculas
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

        // Almacenar la palabra si es válida
        if (palabraValida) {
            palabrasValidas.push_back(palabra);
        }
    }

    if (palabrasValidas.empty()) {
        std::cout << "(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << std::endl;
    } else {
        std::cout << "(Resultado exitoso) El diccionario se ha inicializado correctamente." << std::endl;
    }
    diccionarioInicializado = true;
}

void inicializarInverso(const std::string& nombreArchivo) {
    if (diccionarioInversoInicializado) {
        std::cout << "(Diccionario inverso ya inicializado) El diccionario inverso ya ha sido inicializado." << std::endl;
        return;
    }
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "(Archivo no existe) EL archivo " << nombreArchivo << " no Existe o no puede ser leido" << std::endl;
        return;
    }
    std::string palabra;
    while (archivo >> palabra) {
        // Verificar si la palabra es válida
        bool palabraValida = true;
        for (char c : palabra) {
            if (!std::isalpha(c)) {
                palabraValida = false;
                break;
            }
        }
        // Almacenar la palabra y su inversa si es válida
        if (palabraValida) {
            std::string palabraInversa(palabra.rbegin(), palabra.rend()); // invertir la palabra
            palabrasValidasInverso.push_back(palabraInversa);
        }
    }
    if (palabrasValidasInverso.empty()) {
        std::cout << "(Diccionario inverso ya inicializado) El diccionario inverso ya ha sido inicializado." << std::endl;
    } else {
        std::cout << "(Resultado exitoso) El diccionario inverso se ha inicializado correctamente." << std::endl;
    }
    diccionarioInversoInicializado = true;
}
    
int calcularPuntajePalabra(const std::string& palabra) {
    //Tabla de puntajes por letra
    std::vector<std::pair<char, int>> puntajes = {
        {'E', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'N', 1}, {'R', 1}, {'T', 1}, {'L', 1}, {'S', 1}, {'U', 1},
        {'D', 2}, {'G', 2},
        {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
        {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
        {'K', 5},
        {'J', 8}, {'X', 8},
        {'Q', 10}, {'Z', 10}
    };
    int puntaje = 0;
    for (char c : palabra) {
        // convertir a mayusculas para buscar en la tabla de puntajes
        char letra = std::toupper(c);
        // Buscar la letra en la tabla de puntajes
        auto it = std::find_if(puntajes.begin(), puntajes.end(), [&](const std::pair<char, int>& p) {
            return p.first == letra;
        });
        if (it != puntajes.end()) {
            puntaje += it->second;
        } else {
            return -1; // Letra inválida
        }
    }
    return puntaje;
}

void puntajePalabra(const std::string& palabra) {
    const std::vector<std::string>& diccionario = obtenerDiccionario();
    const std::vector<std::string>& diccionarioInverso = obtenerDiccionarioInverso();

    // Convertir la palabra a minúsculas
    std::string palabraMin = palabra;
    std::transform(palabraMin.begin(), palabraMin.end(), palabraMin.begin(), ::tolower);

    // Verificar si la palabra existe en el diccionario
    auto enDiccionario = [&](const std::vector<std::string>& dic) {
        return std::find_if(dic.begin(), dic.end(), [&](const std::string& dicPalabra) {
            // Convertir la palabra del diccionario a minúsculas antes de comparar
            std::string dicPalabraMin = dicPalabra;
            std::transform(dicPalabraMin.begin(), dicPalabraMin.end(), dicPalabraMin.begin(), ::tolower);
            return dicPalabraMin == palabraMin;
        }) != dic.end();
    };

    if (enDiccionario(diccionario) || enDiccionario(diccionarioInverso)) {
        // Verificar si la palabra contiene solo letras válidas
        bool palabraValida = std::all_of(palabra.begin(), palabra.end(), [](char c) {
            return std::isalpha(c);
        });

        if (palabraValida) {
            int puntaje = calcularPuntajePalabra(palabra);
            if (puntaje != -1) {
                std::cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << std::endl;
            } else {
                std::cerr << "(Error) La palabra contiene letras inválidas." << std::endl;
            }
        } else {
            std::cerr << "(Error) La palabra contiene letras inválidas." << std::endl;
        }
    } else {
        std::cerr << "(Palabra no existe) La palabra no existe en el diccionario." << std::endl;
    }
}
