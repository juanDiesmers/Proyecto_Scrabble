#include "scrable.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "primeraEntrega/asignacion.h"
#include "segundaEntrega/trie.h"


/* Comando de compilacion
    g++ -std=c++11 main.cpp scrable.cxx primeraEntrega/asignacion.cxx segundaEntrega/tree.cxx -o scrable
*/
/*
    englishWords-1.txt
*/

using namespace std;

int main()
{
    bool juego_terminado = false;
    int turno_actual = 0;

    string comando;
    string nombreArchivo;
    string palabra;

    Trie trie;
    ReverseTrie reverseTrie;

    pantallaPrincipal();

    while (!juego_terminado) {

        
        cout << "$ ";
        cin >> comando;
        
        switch (comando[0]) {
            case 'i':
                if (comando == "inicializarJuego" || comando == "i") {
                    limpiarPantalla();
                    cout << "este es el comando inicializarJuego " << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "Ingrese el nombre del archivo: ";
                    cin >> nombreArchivo;
                    inicializarJuego(nombreArchivo);
                    cout << "saliendo del comando inicializarJuego" << endl;
                } else if (comando == "inicializarInverso" || comando == "ii") {
                    limpiarPantalla();
                    cout << "este es el comando inicializarInverso" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "Ingrese el nombre del archivo: ";
                    cin >> nombreArchivo;
                    inicializarInverso(nombreArchivo);
                    cout << "saliendo del comando inicializarInverso" << endl;

                } else if (comando == "iniciarArbol" || comando == "ia") {
                    limpiarPantalla();
                    cout << "este es el comando iniciarArbol" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "Ingrese el nombre del archivo: ";
                    cin >> nombreArchivo;

                    // Llamar a la funcion de inicializar arbol normal
                    trie.initializeFromDictionaryFile(nombreArchivo);

                    cout << "saliendo del comando iniciarArbol" << endl;

                } else if (comando == "iniciarArbolInv" || comando == "iai") {
                    limpiarPantalla();
                    cout << "este es el comando iniciarArbolInv" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "Ingrese el nombre del archivo: ";
                    cin >> nombreArchivo;
                    
                    // Llama a la función de inicialización del Trie inverso
                    reverseTrie.initializeFromDictionaryFile(nombreArchivo);

                    cout << "saliendo del comando iniciarArbolInv" << endl;
                }
            break;
            case 'p':
                if (comando == "puntajePalabra" || comando == "pp") {
                    limpiarPantalla();
                    cout << "este es el comando puntajePalabra" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "Ingrese la palabra para calcular su puntaje: ";
                    cin >> palabra;
                    // verificar si la palabra es valida y obtener su puntaje
                    puntajePalabra(palabra);
                    cout << "saliendo del comando puntajePalabra" << endl;

                } else if (comando == "palabraPrefijo" || comando == "ppr") {
                    limpiarPantalla();
                    cout << "Este es el comando palabraPrefijo" << endl;

                    if (!trie.isInitialized()) {
                        cout << "Error: El árbol del diccionario no está inicializado." << endl;
                    } else {
                        cout << "Comando en progreso..." << endl;
                        cout << "Ingrese el prefijo a buscar: ";
                        string prefijo;
                        cin >> prefijo;

                        vector<string> palabrasConPrefijo;
                        if (trie.wordsWithPrefix(prefijo, palabrasConPrefijo) && !palabrasConPrefijo.empty()) {
                            cout << "Resultado exitoso: Las palabras que comienzan con '" << prefijo << "' son:" << endl;
                            for (const auto& palabra : palabrasConPrefijo) {
                                cout << palabra << endl;
                            }
                        } else {
                            cout << "Fallido: No existen palabras con el prefijo '" << prefijo << "'." << endl;
                        }
                    }
                    cout << "Saliendo del comando palabraPrefijo" << endl;
                }  else if (comando == "palabraSufijo" || comando == "psu") {
                    limpiarPantalla();
                    cout << "Este es el comando palabraSufijo" << endl;

                    if (!reverseTrie.isInitialized()) {
                        cout << "Error: El árbol del diccionario inverso no está inicializado." << endl;
                    } else {
                        cout << "Comando en progreso..." << endl;
                        cout << "Ingrese el sufijo a buscar: ";
                        string sufijo;
                        cin >> sufijo;
                        std::reverse(sufijo.begin(), sufijo.end());

                        vector<string> palabrasConSufijo;
                        if (reverseTrie.wordsWithPrefix(sufijo, palabrasConSufijo) && !palabrasConSufijo.empty()) {
                            cout << "Resultado exitoso: Las palabras que terminan con '" << sufijo << "' son:" << endl;
                            for (auto& palabraInvertida : palabrasConSufijo) {
                                std::reverse(palabraInvertida.begin(), palabraInvertida.end());
                                cout << palabraInvertida << endl;
                            }
                        } else {
                            cout << "Fallido: No existen palabras con el sufijo '" << sufijo << "'." << endl;
                        }
                    }
                    cout << "Saliendo del comando palabraSufijo" << endl;
                } else if (comando == "posiblePalabra" || comando == "ppa") {
                    limpiarPantalla();
                    cout << "este es el comando posiblepalabra" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando posiblepalabra" << endl;
                }  
            break;
            case 'g':
                if (comando == "grafoPalabra" || comando == "gp") {
                    limpiarPantalla();
                    cout << "este es el comando grafoPalabra" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "salir del comando grafoPalabra" << endl;
                } 
            break;
            case 'a':
                if (comando == "ayuda" || comando == "a") {
                    limpiarPantalla();
                    mostrarAyuda();
                    cout << "saliendo del comando ayuda" << endl;
                }
                break;
            case 's':
                if (comando == "salir" || comando == "s") {
                    limpiarPantalla();
                    cout << "este es el comando salir" << endl;
                    cout << "saliendo del juego" << endl;
                    juego_terminado = true;
                    pausarPantalla();
                }
                break;
            default:
            
                limpiarPantalla();
                cout << "Comando invalido. Para ver la lista de comandos disponibles, "
                        "ingrese 'a' o ''ayuda'." << endl;
                break;
        }
    }
    limpiarPantalla();
    return 0;
}
