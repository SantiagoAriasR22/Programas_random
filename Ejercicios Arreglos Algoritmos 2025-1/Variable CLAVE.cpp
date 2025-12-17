#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N, clave, orde, aux;
	bool pos=true;
	vector<int> numeros;
	setlocale(LC_ALL, "spanish");
	
	cout<<"De que tamaño quiere que sea el arreglo?: ";
	cin>>N;
	
	int A[N];
	
	for(int i=0; i<=N-1; i++){
		cout<<"Ingrese un valor para la posicion ["<<i<<"]: ";
		cin>>A[i];
	}
	
	cout<<"Ingrese un valor CLAVE: ";
	cin>>clave;
	
	for(int i=0; i<=N-1; i++){
		if(A[i]==clave){
			numeros.push_back(i);
		}
		if(A[i] == clave){
			pos=false;
		}
	}
	
	if(pos==true){
		cout<<clave<<" no esta dentro del arreglo"<<endl;
	}
	else if(pos==false){
		cout<<clave<<" aparece "<<numeros.size()<<" veces en el arreglo"<<endl;
		cout<<clave<<" esta en las posiciones: ";
			for(int i=0; i<numeros.size(); i++){
				cout<<"["<<numeros[i]<<"]";
		}
	}
	cout<<endl;
	
	for(int i=0; i<=N-1; i++){
			for(int j=0; j<=N-1; j++){
				if(A[j]>A[j+1]){
					aux=A[j];
					A[j]=A[j+1];
					A[j+1]=aux;
				}
			}
		}
	
	cout<<"Como desea ordenar el arreglo?:"<<endl;
	cout<<"1. Ascendente"<<endl<<"2. Descendente"<<endl;
	cin>>orde;
	switch(orde){
		case 1: 
		for(int i=0; i<=N-1; i++){
			cout<<"["<<A[i]<<"]";
		} break;
		
		case 2: 
		for(int i=N-1; i>=0; i--){
			cout<<"["<<A[i]<<"]";
		} break;
	}	
}
