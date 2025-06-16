#include "RedSocial.h"
#include <iostream>
#include <algorithm>

using namespace std;

RedSocial::RedSocial() {
    // Constructor vacío, las estructuras se inicializan automáticamente
}

void RedSocial::add(const string& u1, const string& u2) {
    // Agregar usuarios al conjunto
    users.insert(u1);
    users.insert(u2);
    
    // Agregar conexión bidireccional
    // Verificar si ya existe la conexión para evitar duplicados
    vector<string>& neighbors1 = graph[u1];
    bool found1 = false;
    for (const string& neighbor : neighbors1) {
        if (neighbor == u2) {
            found1 = true;
            break;
        }
    }
    if (!found1) {
        neighbors1.push_back(u2);
    }
    
    vector<string>& neighbors2 = graph[u2];
    bool found2 = false;
    for (const string& neighbor : neighbors2) {
        if (neighbor == u1) {
            found2 = true;
            break;
        }
    }
    if (!found2) {
        neighbors2.push_back(u1);
    }
}

bool RedSocial::find(const string& u) {
    // Se usa BFS para encontrar al usuario u
    return bfsSearch(u);
}

bool RedSocial::bfsSearch(const string& target) {
    // Si no hay usuarios en la red, no se puede encontrar nada
    if (users.empty()) {
        return false;
    }
    
    // BFS desde cualquier usuario para recorrer todo el grafo
    unordered_set<string> visited;
    queue<string> q;
    
    // Comenzar desde cualquier usuario en la red
    // users.begin() da un iterador al primer elemento
    // *users.begin() obtiene el valor del primer elemento
    string start = *users.begin();
    q.push(start);
    visited.insert(start);
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        // Si se encuentra el usuario objetivo
        if (current == target) {
            return true;
        }
        
        // Explorar todos los vecinos no visitados
        for (const string& neighbor : graph[current]) {
            // Verificar si ya se visitó a ese vecino
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    
    // Si BFS termina sin encontrar el usuario, no existe
    return false;
}

void RedSocial::printGraph() {
    cout << "Estado actual del grafo:" << endl;
    for (const string& user : users) {
        cout << user << ": ";
        for (const string& neighbor : graph[user]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << endl;
}