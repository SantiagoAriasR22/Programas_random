#include<iostream>
#include<string.h>
using namespace std;

int main(){

    char cadena[50];
    char cadena_aux[50];
    int longitud=0;

    cout<<"Ingrese una frase para invertirla: ";
    gets(cadena);

    longitud=strlen(cadena);

    for(int i=0; i<longitud; i++){
        cadena_aux[i]=cadena[longitud-i-1];
    }

    cadena_aux[longitud]='\0';

    cout<<"La frase "<<cadena<<" invertida es: "<<cadena_aux<<endl;
}