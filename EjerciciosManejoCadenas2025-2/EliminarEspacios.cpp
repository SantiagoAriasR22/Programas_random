#include<iostream>
#include<string.h>
using namespace std;


void espacios(char cad[]){
    char cad2[100];

    int i, j;

    cout<<strlen(cad)<<endl;

    for(i=0, j=0; i<strlen(cad); i++){
        if((isblank(cad[i])==false)){
            cad2[j]=cad[i];
            j++;
        }
    }

    cad2[j]='\0';

    cout<<cad2<<endl;
}

void espacios2(char cad[]){
    char cad2[100];
    int j=0;

    for(int i=0; cad[i]!='\0'; i++){
        if(cad[i]!=' '){
            cad[j]=cad[i];
            j++;
        }
    }

    cad[j]='\0';

    cout<<cad<<endl;
}

int espacios3(char cad[], int i, int j){

    if(cad[i]=='\0'){
        cad[j]='\0';
        cout<<cad<<endl;
        return 0;
    }
    
    if(cad[i]!=' '){
        cad[j]=cad[i];

        return espacios3(cad, i=i+1, j=j+1);
    }
    else{
        return espacios3(cad, i=i+1, j);
    }
}

int main(){

    int opc, N;
    char cad[100];

    do{
        cout<<"1. Con vector auxiliar"<<endl;
        cout<<"2. Sin vector auxiliar"<<endl;
        cout<<"3. Con recursividad"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opc;

        switch(opc){
            case 1:
                cout<<"Ingrese una cadena de texto para eliminar los espacios: ";
                cin. ignore(); gets(cad);


                espacios(cad);
            break;

            case 2:
                cout<<"Ingrese una cadena de texto para eliminar los espacios: ";
                cin. ignore(); gets(cad);


                espacios2(cad);
            break;

            case 3:
                cout<<"Ingrese una cadena de texto para eliminar los espacios: ";
                cin. ignore(); gets(cad);

                int i=0, j=0;

                N=espacios3(cad, i, j);
            break;
        }
    }while(opc!=4);
}