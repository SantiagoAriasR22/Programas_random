#include <iostream>
using namespace std;

int main(){
	int N, aux;
	setlocale(LC_ALL, "spanish");
	
	cout<<"Ingrese el tamaño del vector: ";
	cin>>N;
	
	int numeros[N];
	
	for(int i=0; i<N; i++){
		cout<<"Ingrese el valor que va a ingresar en la posicion ["<<i<<"]: ";
		cin>>numeros[i];
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if((numeros[j] % 2 != 0) && (j % 2 == 0)&&(numeros[j+1] % 2 == 0) && (j+1 % 2 !=0)){
				aux=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=aux;
			}
		}
	}
	
	for(int i=0; i<N; i++){
		cout<<numeros[i]<<"["<<i<<"]"<<endl;
	}
}
