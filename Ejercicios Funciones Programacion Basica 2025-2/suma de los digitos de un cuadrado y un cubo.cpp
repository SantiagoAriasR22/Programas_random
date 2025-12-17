/*Elabore un programa que lea un número entero y averigüe si la suma de los dígitos
del número es igual a la suma de los dígitos de su cuadrado e igual a la suma de
los dígitos de su cubo. Utilice una función que calcule la suma de los dígitos de un
número entero.*/
#include <iostream>
using namespace std;

int suma_cubo(int x);
int suma_cuadrado(int y);
int cubo(int z);
int cuadrado(int w);
int main(){
	int numero, resul_cubo, resul_cuadrado, div3=0, dig=0;
	
	cout<<"Ingrese un numero entero: ";
	cin>>numero;
	
	int ux=numero;
	do{
		div3=ux%10;
		dig+=div3;
		ux/=10;
	}while(ux!=0);

	resul_cubo = suma_cubo(numero);
	resul_cuadrado = suma_cuadrado(numero);
		
	if(dig==resul_cubo && dig==resul_cuadrado){
		cout<<"La suma de los digitos del numero "<<numero<<" es igual a la suma de los digitos de su cuadrado y cubo, que es igual a "<<dig<<endl;
	}
	else{
		cout<<"La suma de los digitos del numero "<<numero<<" no es igual a la suma de los digitos de su cuadrado y cubo, porque sus sumas son: "<<endl;
		cout<<"Numero ingresado : "<<numero<<"     "<<"Suma de sus digitos: "<<dig<<endl;
		cout<<"Potencia: "<<cuadrado(numero)<<"     Suma de sus digitos: "<<resul_cuadrado<<endl;
		cout<<"Cubo : "<<cubo(numero)<<"     Suma de sus digitos: "<<resul_cubo<<endl;
	}
	
}

int cuadrado(int w){
	int potencia_cuadrado=1;
	for(int i=0; i<2; i++){
		potencia_cuadrado*=w;
	}
	
	return potencia_cuadrado;
}

int suma_cuadrado(int y){
	int suma=0, div2=0, aux2=0;
	
	aux2=cuadrado(y);
	
	do{
		div2=aux2%10;
		suma+=div2;
		
		aux2/=10;
	}while(aux2!=0);
	
	return suma;
}

int cubo(int z){
	int potencia_cubo=1;
	
	for(int i=0; i<3; i++){
		potencia_cubo*=z;
	}
	
	return potencia_cubo;
}

int suma_cubo(int x){
	int resultado=0, div=0, aux=0;
	
	aux=cubo(x);
	
	do{
		div=aux%10;
		resultado+=div;
		
		aux/=10;
	}while(aux!=0);
	
	return resultado;
}
