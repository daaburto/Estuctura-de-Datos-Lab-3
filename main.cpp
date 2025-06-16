#include <iostream>
#include <string>
#include <sstream>
#include "RedSocial.h"

using namespace std;

int main() {
    RedSocial network;
    string line;
    
    cout << "=== Red Social - Laboratorio 3 ===" << endl;
    cout << "Comandos disponibles:" << endl;
    cout << "- add u1 u2: Agregar conexión entre u1 y u2" << endl;
    cout << "- find u: Buscar usuario u" << endl;
    cout << "- exit: Salir del programa" << endl;
    cout << "=================================" << endl;
    
    while (true) {
        cout << "> ";
        getline(cin, line);
        
        // Salir del programa
        if (line == "exit") {
            break;
        }
        
        // Procesar comando
        stringstream ss(line);
        string command;
        ss >> command;
        
        if (command == "add") {
            string u1, u2;
            ss >> u1 >> u2;
            
            if (u1.empty() || u2.empty()) {
                cout << "Error: Formato incorrecto. Uso: Add u1 u2" << endl;
                continue;
            }

            // Se añade la relación entre u1 y u2
            network.add(u1, u2);

            
        } else if (command == "find") {
            string u;
            ss >> u;
            
            if (u.empty()) {
                cout << "Error: Formato incorrecto. Uso: Find u" << endl;
                continue;
            }
            
            bool found = network.find(u);
            cout << (found ? "Yes" : "No") << endl;
            
        } else if (command == "debug") {
            // Comando extra para debugging
            network.printGraph();
            
        } else if (command.empty()) {
            // No hay comando
            continue;
            
        } else {
            cout << "Comando no reconocido: " << command << endl;
            cout << "Comandos disponibles: add, find, exit" << endl;
        }
    }
    
    return 0;
}