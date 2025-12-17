#include <iostream>
using namespace std;

int main(){
	int aux, pos;
	
	int numeros[]={4, 5, 1, 7, 3, 2};
	
	for(int i=0; i<6; i++){
		pos=i;
		aux=numeros[i];
		
		while((pos > 0) && (numeros[pos-1] > aux)){
			numeros[pos] = numeros[pos-1];
			pos--;
		}
		numeros[pos] = aux;
	}
	
	cout<<"Orden ascendente"<<endl;
	for(int i=0; i<6; i++){
		cout<<numeros[i]<<"  ";
	}
}
