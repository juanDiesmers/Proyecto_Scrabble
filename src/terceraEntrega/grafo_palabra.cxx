#include "grafo_palabra.h"
#include <iostream>
#include <algorithm>
#include <cctype>

GrafoPalabra::GrafoPalabra() : grafoConstruido(false) {}

void GrafoPalabra::construirGrafo() {
    if (!diccionarioInicializado) {
        std::cout << "Error: El diccionario debe inicializarse primero." << std::endl;
        return;
    }

    if (grafoConstruido) {
        std::cout << "Grafo ya construido, no se requiere reconstrucción." << std::endl;
        return;
    }

    int n = palabrasValidas.size();
    adyacencias.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sonConectadas(palabrasValidas[i], palabrasValidas[j])) {
                adyacencias[i].push_back(j);
                adyacencias[j].push_back(i);
            }
        }
    }

    grafoConstruido = true;
    std::cout << "(Resultado exitoso) Grafo construido correctamente." << std::endl;
}

bool GrafoPalabra::sonConectadas(const std::string& palabra1, const std::string& palabra2) {
    if (palabra1.size() != palabra2.size()) return false;

    int diferencias = 0;
    for (size_t i = 0; i < palabra1.size(); i++) {
        if (palabra1[i] != palabra2[i]) {
            diferencias++;
            if (diferencias > 1) return false;
        }
    }
    return diferencias == 1;
}

std::vector<std::string> GrafoPalabra::posiblesPalabras(const std::string& letrasDisponibles) {
    if (!grafoConstruido) {
        std::cout << "Error: El grafo debe ser construido antes de buscar palabras posibles." << std::endl;
        return {};
    }

    std::vector<std::string> resultado;
    std::vector<int> letrasContadas(26, 0); // Contador para cada letra del alfabeto
    int wildcards = 0;

    // Contar las letras disponibles y los comodines
    for (char c : letrasDisponibles) {
        if (c == '?') {
            wildcards++;
        } else if (isalpha(c)) {
            letrasContadas[tolower(c) - 'a']++;
        }
    }

    // Iterar sobre cada palabra válida en el diccionario
    for (const auto& palabra : palabrasValidas) {
        std::vector<int> letrasNecesarias = letrasContadas; // Copia del contador de letras
        bool esPosible = true;
        int comodinesUsados = 0;

        // Verificar si la palabra se puede formar con las letras disponibles
        for (char letra : palabra) {
            int& cuenta = letrasNecesarias[tolower(letra) - 'a'];
            if (cuenta > 0) {
                cuenta--;
            } else if (wildcards > comodinesUsados) {
                comodinesUsados++;
            } else {
                esPosible = false;
                break;
            }
        }

        if (esPosible) {
            resultado.push_back(palabra);
        }
    }

    if (resultado.empty()) {
        std::cout << "No se encontraron palabras que se puedan formar con las letras dadas." << std::endl;
    } else {
        std::cout << "Palabras encontradas:" << std::endl;
        for (const auto& palabra : resultado) {
            std::cout << palabra << std::endl;
        }
    }

    return resultado;
}

void GrafoPalabra::mostrarGrafo() {
    if (!grafoConstruido) {
        std::cout << "Error: El grafo debe ser construido antes de mostrarlo." << std::endl;
        return;
    }

    for (size_t i = 0; i < palabrasValidas.size(); i++) {
        std::cout << palabrasValidas[i] << " conecta con: ";
        for (int adj : adyacencias[i]) {
            std::cout << palabrasValidas[adj] << " ";
        }
        std::cout << std::endl;
    }
}
