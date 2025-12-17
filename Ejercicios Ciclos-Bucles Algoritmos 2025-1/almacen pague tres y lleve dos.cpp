#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int codigo, cost, exist, exist_min, exist_max, cant_ord, cost_ord, cost_merc=0;
	string nombre;
	char salida;
	
	do{
		cout<<"Ingrese el codigo del articulo: ";
		cin>>codigo;
		cout<<"Ingrese el nombre del articulo: ";
		fflush(stdin); getline(cin, nombre);
		cout<<"Ingrese el costo unitario del articulo: ";
		cin>>cost;
		cout<<"Ingrese la cantidad de unidades existentes: ";
		cin>>exist;
		cout<<"Ingrese la cantidad unidades minimas requeridas: ";
		cin>>exist_min;
		cout<<"Ingrese la cantidad de unidades maximas requeridas: ";
		cin>>exist_max;
		
		cant_ord=exist_max-exist;
		
		if(exist>exist_min){
			cant_ord=0;
		}
		
		cost_ord=cant_ord*cost;
		cost_merc+=cost_ord;
		
		cout<<endl;
		cout<<"Codigo del articulo: "<<codigo<<endl;
		cout<<"Cantidad de articulos a ordenar: "<<cant_ord<<endl;
		cout<<"Costo unitario por articulo: "<<cost<<endl;
		cout<<"Costo total de la cantidad de articulos a ordenar: "<<cost_ord<<endl;
		
		
		cout<<"Quiere ingresar la informacion de otro articulo? [S]i - [N]o: ";
		cin>>salida;
	}while(toupper(salida)=='S');
	
	cout<<"Costo total de la mercancia a ordenar: "<<cost_merc<<endl;
}
