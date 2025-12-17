#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Definir los nodos del conjunto A
    vector<int> nodos = {0, 1, 2, 3};

    // 2. Definir la relación como pares ordenados
    vector<pair<int,int>> relacion = {
        {0,0}, {0,1}, {0,3},
        {1,1}, {1,0},
        {2,3},
        {3,3}
    };

    // 3. Mostrar nodos
    cout << "Nodos del conjunto A:" << endl;
    for (int nodo : nodos) {
        cout << nodo << " ";
    }
    cout << endl << endl;

    // 4. Mostrar la relación
    cout << "Relacion (pares ordenados):" << endl;
    for (auto par : relacion) {
        cout << "(" << par.first << ", " << par.second << ")" << endl;
    }
    cout << endl;

    // 5. Mostrar los arcos como flechas
    cout << "Visualizacion de arcos:" << endl;
    for (auto par : relacion) {
        cout << par.first << " -> " << par.second << endl;
    }

    return 0;
}

