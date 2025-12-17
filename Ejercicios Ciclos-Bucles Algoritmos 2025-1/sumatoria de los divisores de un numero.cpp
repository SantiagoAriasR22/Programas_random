#include<iostream>
using namespace std;

int main(){
	int numero, cant_divisores=0, sumatoria=0, i=1, divisor=0, k=0;
	
	cout<<"Ingrese un numero: ";
	cin>>numero;
	cout<<"Divisores de: "<<numero<<endl;
	do{
		divisor=numero%i;
		
		if(divisor==0){
			cout<<i<<endl;
			sumatoria+=i;
			k++;
		}
		i++;
	}while(i<=numero);
	cout<<"Numero de divisores: "<<k<<endl;
	cout<<"La sumatoria de los divisores de "<<numero<<" es igual a: "<<sumatoria;
}
