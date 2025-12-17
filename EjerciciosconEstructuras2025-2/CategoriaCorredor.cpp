/*1. Hacer una estructura llamada corredor, en la cual se tendrán los siguientes 
campos: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle
una categoría de competición:
- Juvenil <= 18 años
- Señor <= 40 años
- Veterano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoría de 
competición.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct corredor
{
    string nombres;
    int edades;
    string sexos;
    string clubes;
};


int main(){

    int N;
    vector<corredor>Caminantes;

    cout<<"Ingrese la cantidad de corredores: ";
    cin>>N;
    cin.ignore();
    
    for(int i=0; i<N; i++){
        corredor aux;

        cout<<"Datos del corredor #"<<i+1<<endl;
        cout<<"Nombre: ";
        getline(cin, aux.nombres);

        cout<<"Edad: ";
        cin>>aux.edades;
        cin.ignore();

        cout<<"Sexo: ";
        getline(cin, aux.sexos);

        cout<<"Club: ";
        getline(cin, aux.clubes);

        Caminantes.push_back(aux);
        cout<<endl;
    }

    system("cls");

    cout<<"Datos de los corredores"<<endl;
    for(int i=0; i<Caminantes.size(); i++){
        cout<<"Competidor #"<<i+1<<": "<<endl;
        cout<<"Nombre: "<<Caminantes[i].nombres<<endl;
        cout<<"Edad: "<<Caminantes[i].edades<<endl;
        cout<<"Sexo: "<<Caminantes[i].sexos<<endl;
        cout<<"Club: "<<Caminantes[i].clubes<<endl;
        cout<<endl;
    }

    system("pause");
}
