/*2. Hacer una estructura llamada alumno, en la cual se tendrán los siguientes
Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, comprobar cuál
de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno.*/

#include<iostream>
#include<vector>
using namespace std;

struct Alumno
{
    string nombre;
    int edad;
    float promedio;
};

int main()
{
    int N;
    vector<Alumno> alumnos;

    cout<<"Ingrese la cantidad de alumnos: ";
    cin>>N;

    for (int i=0; i<N; i++)
    {
        cout<<"Ingrese el nombre: ";

    }
}