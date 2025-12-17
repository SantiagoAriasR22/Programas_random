#include <iostream>

using namespace std;

int main() {
    int numero;

    // Leer el número entero positivo del usuario
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;

    // Validar que el número sea positivo
    while (numero <= 0) {
        cout << "Error: Por favor, ingrese un numero entero positivo: ";
        cin >> numero;
    }

    cout << "Los divisores de " << numero << " son: ";

    // Iterar desde 1 hasta el número para encontrar los divisores
    for (int divisor = 1; divisor <= numero; ++divisor) {
        // Verificar si 'divisor' divide a 'numero' sin dejar resto
        if (numero % divisor == 0) {
            // Si el resto es 0, 'divisor' es un divisor
            cout << divisor << " ";
        }
    }

    cout << endl; // Salto de línea al final

    return 0;
}
