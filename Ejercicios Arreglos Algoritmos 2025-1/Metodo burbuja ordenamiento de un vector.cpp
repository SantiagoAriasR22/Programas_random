#include <iostream>
using namespace std;

int main(){
	//ordenar el siguiente vector utilizando el metodo burbuja
	int aux;
	int numeros[]={10,3,8,32,1,5,9};
	
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			if(numeros[j]>numeros[j+1]){
				aux=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=aux;
			}
		}
	}
	
	cout<<"Ascendente"<<endl;
	for(int i=0; i<7; i++){
		cout<<"["<<numeros[i]<<"]";
	}
	cout<<endl;
	
	cout<<"Descendente"<<endl;
	for(int j=6; j>=0; j--){
		cout<<"["<<numeros[j]<<"]";
	}
}
