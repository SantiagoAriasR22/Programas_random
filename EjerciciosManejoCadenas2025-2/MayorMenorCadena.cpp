//Dada dos cadenas de caracteres cad1, cad2, realizar los siguientes procesos. Mostrar la cadena en mayúscula si son iguales, si son diferentes indicar cual es la mayor y mostrarla invertida
#include <iostream>
#include <string.h>
using namespace std;

int main(){

    char cad1[50];
    char cad2[50];
    int l1=0, l2=0;

    cout<<"Ingrese la cadena 1: ";
    gets(cad1);

    cin.ignore();

    cout<<"Ingrese la cadena 2: ";
    gets(cad2);

    l1=strlen(cad1);
    l2=strlen(cad2);

    if(l1>l2){
        
    }
}