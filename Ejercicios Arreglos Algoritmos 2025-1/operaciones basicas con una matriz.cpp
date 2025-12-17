#include <iostream>
using namespace std;

int main(){
	int N, M, suma=0, par=0, impar=0, maximo=0, minimo=9999999, nro;
	char salida;
	bool pert;
	setlocale(LC_ALL, "spanish");
	
	cout<<"Ingrese el tamaño de las filas de la matriz: ";
	cin>>N;
	cout<<"Ingrese el tamaño de las columnas de la matriz: ";
	cin>>M;
	
	int numeros[N][M];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<"Ingrese el valor que quiere guardar en la posicion ["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
			suma+=numeros[i][j];
			
			if(numeros[i][j] % 2 == 0){
				par++;
			}
			else{
				impar++;
			}
			
			if(numeros[i][j] < minimo){
				minimo=numeros[i][j];
			}
			if(numeros[i][j] > maximo){
				maximo=numeros[i][j];
			}
		}
	}
	
	cout<<"Sumatoria de los datos de la matriz: "<<suma<<endl;
	cout<<"Promedio de los valores: "<<suma/(N*M)<<endl;
	cout<<"Porcentaje de numeros pares: "<<(par*100)/(N*M)<<"%"<<endl;
	cout<<"Porcentaje de numeros impares: "<<(impar*100)/(N*M)<<"%"<<endl;
	cout<<"Valor maximo: "<<maximo<<endl;
	cout<<"Valor minimo: "<<minimo<<endl;
	do{
		cout<<"Ingrese el numero que quiere buscar en la matriz: ";
		cin>>nro;
		
		pert=false;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(nro==numeros[i][j]){
					pert=true;
					cout<<"El numero "<<nro<<" se encuentra en la posicion: ["<<i<<"]["<<j<<"]"<<endl;
				}
			}
		}
		
		if(pert==false){
			cout<<"El numero no pertence a la matriz"<<endl;
		}
		
		cout<<"Quiere buscar la posicion de otro dato dentro del arreglo?: [S]i -- [N]o: ";
		cin>>salida;
		
	}while(toupper(salida)=='S');
}
