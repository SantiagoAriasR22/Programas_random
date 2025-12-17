#include<iostream>
#include<string.h>
using namespace std;

int main(){

    char cadena[50];
    char centi;
    int dig=0, c=0;

    do{

        dig=0;

        cout<<"Ingrese una frase cualquiera: ";
        if(c>0){
            cin.ignore();
        }
        gets(cadena);

        for(int i=0; cadena[i] != '\0'; i++){
            if(isdigit(cadena[i])) dig++;
        }

        cout<<endl;
        cout<<"La frase "<<cadena<<" tiene "<<dig<<" digitos"<<endl;

        cout<<"Quieres ingresar otra frase?: 1. Si -- 2. No"<<endl;
        cin>>centi;

        c++;

    }while(centi!='2');


}