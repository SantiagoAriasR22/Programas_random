#include<iostream>
#include<string.h>
using namespace std;

bool palindromo(char cad1[]){

    char cad2[50];
    int j=0;

    for(int i=strlen(cad1)-1; i>=0; i--, j++){
        cad2[j]=cad1[i];
    }

    cad2[j]='\0';


    if(strcmp(cad2, cad1)==0){
        return true;
    }
    else{
        return false;
    }

}

bool palindromo2(char cad1[]){

    bool centi;
    int j, i;

    for(i=0, j=strlen(cad1)-1; i<strlen(cad1)-1; i++, j--){
        if(cad1[i]==cad1[j]){
            centi=true;
        }
        else{
            centi=false;
            break;
        }
    }

    if(centi==true){
        return true;
    }
    else{
        return false;
    }
}

bool palindromo3(char cad1[], int &i, int &j){


    if(i>=j){
        return true;
    }
    if(cad1[i]!=cad1[j]){
        return false;
    }
    
    return palindromo3(cad1, i=i+1, j=j-1);
}

int main(){

    char cad1[50];
    bool pali;
    int opc;

    cout<<"Escoja como evaluar si una cadena es palindromo o no"<<endl;

    do{
        cout<<"1. Version facil"<<endl;
        cout<<"2. Version un poco mas dificil"<<endl;
        cout<<"3. Version recursiva"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            cout<<"Ingrese una cadena para verificar si es un palindromo: ";
            cin.ignore(); gets(cad1);

            pali=palindromo(cad1);

            if(pali==true) cout<<"Si es palindromo"<<endl;
            else cout<<"No es palindromo"<<endl;

        break;

        case 2:
            cout<<"Ingrese una cadena para verificar si es un palindromo: ";
            cin.ignore(); gets(cad1);

            pali=palindromo2(cad1);

            if(pali==true) cout<<"Si es palindromo"<<endl;
            else cout<<"No es palindromo"<<endl;

        break;

        case 3:

            cout<<"Ingrese una cadena para verificar si es un palindromo: ";
            cin.ignore(); gets(cad1);

            int i=0, j=strlen(cad1)-1;
            bool centi=true;

            pali=palindromo3(cad1, i, j);

            if(pali==true) cout<<"Si es palindromo"<<endl;
            else cout<<"No es palindromo"<<endl;

        break;

    }

    }while(opc!=4);

}