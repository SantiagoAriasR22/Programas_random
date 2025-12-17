#include <iostream>
using namespace std;

int cal_factorial(int numero);
int suma_factorial(int multi);
int main(){
	int numero, factorial, suma;
	cout<<"Ingrese un numero: ";
	cin>>numero;
	
	factorial=cal_factorial(numero);
	suma=suma_factorial(factorial);
	
	cout<<"Numero ingresado: "<<numero<<endl;
	cout<<"Factorial del numero: "<<factorial<<endl;
	cout<<"Suma de los digitos del factorial: "<<suma<<endl;
	
}

int cal_factorial(int numero){
	
	long long multi=1;
	
	do{
		multi*=numero;
		numero--;
	}while(numero>1);
	
	return multi;
}

int suma_factorial(int factorial){
	int suma=0, dig=0;
	
	do{
		dig=factorial%10;
		suma+=dig;
		factorial/=10;
	}while(factorial!=0);
	
	return suma;
}



