#include "scrable.h"
#include <iostream>

using namespace std;

int main()
{
    bool juego_terminado = false;
    int turno_actual = 0;

    string comando;

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
                    cout << "saliendo del comando inicializarJuego" << endl;

                } else if (comando == "inicializarInverso" || comando == "ii") {
                    limpiarPantalla();
                    cout << "este es el comando inicializarInverso" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando inicializarInverso" << endl;

                } else if (comando == "inicirArbol" || comando == "ia") {
                    limpiarPantalla();
                    cout << "este es el comando iniciarArbol" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando iniciarArbol" << endl;

                } else if (comando == "iniciarArbolInv" || comando == "iai") {
                    limpiarPantalla();
                    cout << "este es el comando iniciarArbolInv" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando iniciarArbolInv" << endl;
                }
            break;
            case 'p':
                if (comando == "puntajePalabra" || comando == "pp") {
                    limpiarPantalla();
                    cout << "este es el comando puntajePalabra" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando puntajePalabra" << endl;

                } else if (comando == "pasarTurno" || comando == "pt") {
                    limpiarPantalla();
                    cout << "este es el comando pasarturno" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando pasarturno" << endl;

                } else if (comando == "palabraPrefijo" || comando == "ppr") {
                    limpiarPantalla();
                    cout << "este es el comando palabraprefijo" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando palabraprefijo" << endl;

                } else if (comando == "palabrasufijo" || comando == "psu") {
                    limpiarPantalla();
                    cout << "este es el comando palabrasufijo" << endl;
                    cout << "Comando en progreso..." << endl;
                    cout << "saliendo del comando palabrasufijo" << endl;

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
                    cout << "este es el comando ayuda" << endl;
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
                cout << "Comando invlaido. Para ver la lista de comandos disponibles, "
                        "ingrese 'a' o ''ayuda'." << endl;
                break;
        }
    }
    limpiarPantalla();
    return 0;
}
