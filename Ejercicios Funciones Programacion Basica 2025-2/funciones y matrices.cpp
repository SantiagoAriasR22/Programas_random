#include<iostream>
using namespace std;

void cargar(int matriz[][3], int N);
void imprimir(int matriz[][3], int N);
void estadisticas(int matriz[][3], int N); 

int main(){
	int N;
	char opcion;
	
	cout<<"Ingrese el numero de filas que quiere que tenga el arreglo: ";
	cin>>N;
	
	int matriz[N][3];
	
	system("cls");
	
	do{
		cout<<"1. Cargar datos en la matriz"<<endl;
		cout<<"2. Imprimir datos de la matriz"<<endl;
		cout<<"3. Estadisticas"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			case '1': cargar(matriz, N); break;
			case '2': imprimir(matriz, N); break;
			case '3': estadisticas(matriz, N); break;
		}
	}while(opcion!='4');
		
}

void cargar(int matriz[][3], int N){
	
	for(int i=0; i<N; i++){
		for(int x=0; x<3; x++){
			cout<<"Ingrese el valor que quiere guardar en la posicion ["<<i+1<<"]["<<x+1<<"]"<<endl;
			cin>>matriz[i][x];
		}
	}
}

void imprimir(int matriz[][3], int N){
	
	for(int i=0; i<N; i++){
		for(int x=0; x<3; x++){
			cout<<"["<<matriz[i][x]<<"]";
		}
		cout<<endl;
	}
}

void estadisticas(int matriz[][3], int N){
	float suma=0, cero=0, par=0, impar=0, maximo=0, minimo=9999999;
	
	for(int i=0; i<N; i++){
		for(int x=0; x<3; x++){
			
			suma+=matriz[i][x];
			
			if(matriz[i][x]==0){
				cero++;
			}
			
			if(matriz[i][x]%2==0){
				par++;
			}
			else{
				impar++;
			}
			
			if(matriz[i][x]>maximo){
				maximo=matriz[i][x];
			}
			
			if(matriz[i][x]<minimo){
				minimo=matriz[i][x];
			}
		}
	}
	
	cout<<"Promedio: "<<(float)suma/(N*3)<<endl;
	cout<<"Porcentaje de numeros ceros: "<<(float)(cero/(N*3))*100<<"%"<<endl;
	cout<<"Porcentaje de numeros pares: "<<(float)(par/(N*3))*100<<"%"<<endl;
	cout<<"Porcentaje de numeros impares: "<<(float)(impar/(N*3))*100<<"%"<<endl;
	cout<<"Valor maximo: "<<maximo<<endl;
	cout<<"Valor minimo: "<<minimo<<endl;	
}
