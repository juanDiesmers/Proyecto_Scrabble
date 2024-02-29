#include "asignacion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cctype>
#include "../scrable.h"
#include <unordered_map>

/*
    englishWords-1.txt
*/

bool diccionarioInicializado = false;
std::unordered_set<std::string> palabrasValidas;

bool diccionarioInversoInicializado = false;
std::unordered_set<std::string> palabrasValidasInverso;

const std::unordered_set<std::string>& obtenerDiccionario() {
    return palabrasValidas;
}

const std::unordered_set<std::string>& obtenerDiccionarioInverso() {
    return palabrasValidasInverso;
}

void imprimirDiccionario(const std::unordered_set<std::string>& diccionario) {
    std::cout << "Diccionario:" << std::endl;
    for (const std::string& palabra : diccionario) {
        std::cout << palabra << std::endl;
    }
}

void inicializarJuego(const std::string& nombreArchivo) {
    if (diccionarioInicializado) {
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
        bool palabraValida = true;
        for (char c : palabra) {
            if (!std::isalpha(c)) {
                palabraValida = false;
                break;
            }
        }
        // Almacenar la palabra si es válida
        if (palabraValida) {
            palabrasValidas.insert(palabra);
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
            // Almacenar la palabra si es válida
            if (palabraValida) {
                std::string palabraInversa(palabra.rbegin(), palabra.rend()); // invertir la palabra
                palabrasValidasInverso.insert(palabra);
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
    std::unordered_map<char, int> puntajes = {
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
        if (puntajes.find(letra) != puntajes.end()) {
            puntaje += puntajes[letra];
        } else  {
            // La letra no esta en la tabla de puntajes
            return -1;
        }
    }
    return puntaje;
}

void puntajePalabra(const std::string& palabra) {
    const std::unordered_set<std::string>& diccionario = obtenerDiccionario();
    const std::unordered_set<std::string>& diccionarioInverso = obtenerDiccionarioInverso();

    // verificar si la palabra existe en el diccionario
    if (diccionario.find(palabra) != diccionario.end() || diccionarioInverso.find(palabra) != diccionarioInverso.end()) {
        // Verificar si la palabra contiene solo letras válidas
        bool palabraValida = true;
        for (char c : palabra) {
            if (!std::isalpha(c)) {
                palabraValida = false;
                break;
            }
        }

        std::cout<<"Diccionario Normal"<<std::endl;
        imprimirDiccionario(diccionario);
        std::cout<<"Diccionario Inverso"<<std::endl;
        imprimirDiccionario(diccionarioInverso);

        if (palabraValida) {
            int puntaje = calcularPuntajePalabra(palabra);
            if (puntaje != -1) {
                std::cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << std::endl;
                return;
            } else {
                std::cerr << "(Error) La palabra contiene letras inválidas." << std::endl;
                return;
            }
        } else {
            std::cerr << "(Error) La palabra contiene letras inválidas." << std::endl;
            return;
        }
    } else {
        std::cerr << "(Palabra no existe) La palabra no existe en el diccionario." << std::endl;
        return;
    }
}

