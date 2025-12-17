#include <iostream>
using namespace std;

int main(){
	int N, suma=0, par=0, impar=0, maximo=0, minimo=9999999, nro;
	char salida;
	bool pert=false;
	setlocale (LC_ALL, "spanish");
	
	do{
	cout<<"El tamaño del vector tiene que ser mayor a 0"<<endl;
	cout<<"Ingrese de que tamaño quiere que sea el vector: ";
	cin>>N;
	}while(N<0);
	
	int numeros[N];
	
	for(int i=0; i<N; i++){
		cout<<"Ingrese el valor de la posicion ["<<i<<"]: ";
		cin>>numeros[i];
		suma+=numeros[i];
		
		if(numeros[i] % 2 == 0){
			par++;
		}
		else{
			impar++;
		}	
		
		if(numeros[i] < minimo){
			minimo=numeros[i];
		}
		if(numeros[i] > maximo){
			maximo=numeros[i];
		}
	}
	
	cout<<"Sumatoria de los valores del vector: "<<suma<<endl;
	cout<<"Promedio: "<<suma/N<<endl;
	cout<<"Porcentaje de valores pares: "<<(par*100)/N<<"%"<<"     "<<"Porcentaje de valores impares: "<<(impar*100)/N<<endl;
	cout<<"Valor maximo: "<<maximo<<endl;
	cout<<"Valor minimo: "<<minimo<<endl;
	
	do{
		cout<<"Ingrese el numero que quiere buscar en el arreglo: ";
		cin>>nro;
		
		pert=false;
		
		for(int i=0; i<N; i++){
			if(nro==numeros[i]){
				pert=true;
				cout<<"El numero "<<nro<<" se encuentra en la posicion: "<<"["<<i<<"]"<<endl;
			}
		}
		
		if(pert==false){
			cout<<"El numero no esta dentro del vector"<<endl;
		}
		
		cout<<"Quiere buscar la posicion de otro valor dentro del arreglo?   [S]i -- [N]o: ";
		cin>>salida;
	}while(toupper(salida)=='S');
}
