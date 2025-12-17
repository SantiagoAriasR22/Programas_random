#include <iostream>
using namespace std;

int main(){
	int numero, potencia, i=1;
	long long  sumatoria=1;
	
	cout<<"Ingrese un numero: ";
	cin>>numero;
	
	cout<<"Ingrese a cuanto quiere elevar ese numero: ";
	cin>>potencia;
	
	do{
		sumatoria*=numero;
		i++;
	}while(i<=potencia);
	cout<<numero<<" elevado a "<<potencia<<" es igual a: "<<sumatoria;
}
