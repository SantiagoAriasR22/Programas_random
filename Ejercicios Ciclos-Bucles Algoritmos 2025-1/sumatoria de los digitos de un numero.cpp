#include <iostream>
using namespace std;

int main(){
	int numero=0, digito=0, sumatoria=0, aux;
	cout<<"Ingrese un numero cualquiera: ";
	cin>>numero;
	aux=numero;
	
	do{
		digito=numero%10;
		sumatoria+=digito;
		numero/=10;
		cout<<digito<<endl;
	}while(numero>0);
	cout<<"La sumatoria de los digitos de "<<aux<<" es igual a: "<<sumatoria;
}
