#include<iostream>
using namespace std;

int acumular_div(int n);
int leer_numero();
int amigos (int n1, int n2, int suma1, int suma2);

int main(){
	setlocale(LC_ALL, "spanish");
	bool centi;
	int n1=0, n2=0, suma1=0, suma2=0;
	
	n1=leer_numero();
	n2=leer_numero();
	
	suma1=acumular_div(n1);
	suma2=acumular_div(n2);
	
	centi=amigos(n1, n2, suma1, suma2);
	
	if(centi==true){
		cout<<"Los números amigos son dos números enteros positivos «a» y «b» tales que la suma de los divisores (aquellos valores que dividen el número en partes exactas) propios de uno es igual al otro número y viceversa."<<endl;
		cout<<"La suma de los divisores de "<<n1<<" es igual a: "<<suma1<<endl;
		cout<<"La suma de los divisores de "<<n2<<" es igual a: "<<suma2<<endl;
		cout<<"Por lo tanto ambos numeros son amigos"<<endl;
	}
	else{
		cout<<"Los números amigos son dos números enteros positivos «a» y «b» tales que la suma de los divisores (aquellos valores que dividen el número en partes exactas) propios de uno es igual al otro número y viceversa."<<endl;
		cout<<"La suma de los divisores de "<<n1<<" es igual a: "<<suma1<<endl;
		cout<<"La suma de los divisores de "<<n2<<" es igual a: "<<suma2<<endl;
		cout<<"Por lo tanto ambos numeros no son amigos"<<endl;

	}
	
}

int leer_numero(){
	
	static int i=0;
	int numero; 
	i++;
	
	cout<<"Ingrese el numero #"<<i<<endl;
	cin>>numero;
	
	if(numero<0){
		cout<<"El numero tiene que ser natural"<<endl;
		cout<<"Ingreselo de nuevo: ";
		cin>>numero;
	}
	
	return numero;
	
}

int acumular_div(int n){
	
	int suma=0;
	
	for(int i=1; i<=n/2; i++){
		
		if(n%i==0){
			suma+=i;
		}
	}	
	
	return suma;
}

int amigos (int n1, int n2, int suma1, int suma2){
	
	if((n1==suma2)&&(n2==suma1)){
		return true;
	}
	else{
		return false;
	}
}

