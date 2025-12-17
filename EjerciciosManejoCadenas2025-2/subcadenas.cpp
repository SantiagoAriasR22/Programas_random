#include<iostream>
#include<string.h>
using namespace std;

int sub(char cad[], char cad2[]){

    int x=0;
    int z=0, suma=0, p=0;

    for(int i=0; cad[i]!='\0'; i++){
        if(cad[i]==cad2[0]){
            x=0;
            z=0;
            suma=0;
            for(x=i; cad2[z]!='\0' && cad[x]!='\0'; x++, z++){
                if(cad[x]==cad2[z]){
                    suma++;
                }
                else{
                    break;
                }
            }

            if(suma==strlen(cad2)){
                p++;
            }
        }
        
    }

    return p;
}

int main(){

    int opc, N;
    char cad[100];
    char cad2[80];

    do{
        cout<<"1. Sin recursividad"<<endl;
        cout<<"2. Con recursividad"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;

        switch(opc){
            case 1:
                cout<<"Ingrese una cadena: ";
                cin.ignore(); gets(cad);

                cout<<"Ingrese una subcadena: ";
                gets(cad2);

                N=sub(cad, cad2);

                cout<<"Las veces que esta la subcadena en la cadena son: "<<N<<endl;

            break;
        }
    }while(opc!=3);
}