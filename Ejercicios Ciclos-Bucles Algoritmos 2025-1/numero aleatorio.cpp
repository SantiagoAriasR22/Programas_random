#include <iostream>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()

using namespace std;

int main() {
    srand(time(0));  // Semilla aleatoria basada en la hora actual

    int aleatorio = rand() % 85 + 1;  // Número aleatorio entre 1 y 100

    cout << "Numero aleatorio: " << aleatorio << endl;

    return 0;
}
