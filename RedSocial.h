#ifndef RedSocial_H
#define RedSocial_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class RedSocial {
private:
    // Lista de adyacencia para representar el grafo
    unordered_map<string, vector<string>> graph;
    // Conjunto de usuarios para verificación rápida
    unordered_set<string> users;

    // Método para BFS
    bool bfsSearch(const string& target);

public:
    RedSocial();
    
    // Agregar conexión entre dos usuarios
    void add(const string& u1, const string& u2);
    
    // Buscar si un usuario existe en la red
    bool find(const string& u);
    
    // Método para debug
    void printGraph();
};

#endif