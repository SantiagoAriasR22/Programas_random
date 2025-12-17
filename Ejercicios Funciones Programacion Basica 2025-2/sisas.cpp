#include<iostream>
using namespace std;

int cuadrado(int x);
int cubo(int y);
void suma_cuadrado(int &suma2, int z);
void suma_cubo(int &suma3, int q);

int main(){
	
	int N, N2, N3, suma2=0, suma3=0;
	
	cout<<"Ingrese un numero entero: "<<endl;
	cin>>N;
	
	N2=cuadrado(N);
	N3=cubo(N);
	
	suma_cuadrado(suma2, N2);
	suma_cubo(suma3, N3);
	
	if(suma2==suma3){
		cout<<"La suma de los digitos de "<<N2<<" es igual a la suma de los digitos de "<<N3<<" lo que es igual a: "<<suma2<<endl;
	}
	else{
		cout<<"No se cumple"<<endl;
	}
	
}

int cuadrado(int x){
	
	int m=1;
	
	for(int i=1; i<3; i++){
		m*=x;
	}
	
	return m;
}

int cubo(int y){
	int J=1;
	
	for(int i=0; i<3; i++){
		J*=y;
	}
	
	return J;
}

void suma_cuadrado(int &suma2, int z){
	
	int dig;
	
	do{
		dig=z%10;
		z/=10;
		suma2+=dig;
	}while(z!=0);
}

void suma_cubo(int &suma3, int q){
	
	int dig;
	
	do{
		dig=q%10;
		q/=10;
		suma3+=dig;
	}while(q!=0);
}


