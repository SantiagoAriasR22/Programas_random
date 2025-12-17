#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "¿Cuántos números primos quieres? ";
    cin >> n;
    
    int contador = 0;  // Cuántos primos hemos encontrado
    int numero = 2;    // Empezamos desde el 2
    
    cout << "Los primeros " << n << " números primos son: ";
    
    while (contador < n) {
        bool esPrimo = true;
        
        // Verificar si 'numero' es primo
        for (int i = 2; i < numero; i++) {
            if (numero % i == 0) {
                esPrimo = false;
                break;  // No es primo, salir del bucle
            }
        }
        
        // Si es primo, lo mostramos
        if (esPrimo) {
            cout << numero << " ";
            contador++;
        }
        
        numero++;  // Probar el siguiente número
    }
    
    cout << endl;
    return 0;
}
