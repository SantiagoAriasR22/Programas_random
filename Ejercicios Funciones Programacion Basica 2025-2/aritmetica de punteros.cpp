#include<iostream>
using namespace std;

void cargar(int vector[], int N);
void imprimir(int vector[], int N);
void imprimir_inverso(int vector[], int N);
void imprimir_par(int vector[], int N);
void ordenar(int vector[], int N);
void buscar(int vector[], int N);
void estadisticas(int vector[], int N);

int main(){
	setlocale(LC_ALL, "spanish");
	int N, opcion;
	
	cout<<"Escriba el tamaño del vector: ";
	cin>>N;
	
	int vector[N];
	
	do{
		cout<<"Menu"<<endl;
		cout<<"1. Cargar el arreglo"<<endl;
		cout<<"2. Imprimir el arreglo"<<endl;
		cout<<"3. Imprimri el arreglo de forma inversa"<<endl;
		cout<<"4. Imprimir los elementos ubicados en las posiciones pares"<<endl;
		cout<<"5. ordenar de manera ascendente el arreglo"<<endl;
		cout<<"6. Buscar un elemento del vector"<<endl;
		cout<<"7. Estadisticas"<<endl;
		cout<<"8. Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1: cargar(vector, N); break;
			case 2: imprimir(vector, N); break;
			case 3: imprimir_inverso(vector, N); break;
			case 4: imprimir_par(vector, N); break;
			case 5: ordenar(vector, N); break;
			case 6: buscar(vector, N); break;
			case 7: estadisticas(vector, N); break;
		}
	}while(opcion!=8);
}

void cargar(int vector[], int N){
	
	int i=0, *p=vector;
	
	for(; p<&vector[N]; i++){
		cout<<"Ingrese el dato que va a guardar en la posicion"<<"["<<i+1<<"]"<<endl;
		cin>>*p;
		p++;
	}
}

void imprimir(int vector[], int N){
	
	int i=0, *p=vector;
	
	for(; p<&vector[N]; p++, i++){
		cout<<"["<<*p<<"]";
	}
	cout<<endl;
}

void imprimir_inverso(int vector[], int N){
	int i=0, *p=&vector[N-1];
	
	for(; p>=&vector[0]; p--){
		cout<<"["<<*p<<"]";
	}
	cout<<endl;
}

void imprimir_par(int vector[], int N){
	int i=0, *p=&vector[1];
	
	for(; p<&vector[N]; p+=2){
			cout<<"["<<*p<<"]";
		cout<<endl;
	}
}

void ordenar(int vector[], int N){
	int *p=vector, *q=vector, aux=0;
	
	for(p=vector; p<&vector[N-1]; p++){
		for(q=vector; q<&vector[N-1]; q++){
			if(*q>*(q+1)){
				aux=*q;
				*q=*(q+1);
				*(q+1)=aux;
			}
		}
	}
	p=vector;
	
	for(; p<&vector[N]; p++){
		cout<<"["<<*p<<"]";
	}
	cout<<endl;
}

void buscar(int vector[], int N){
	
	int *p=vector, num, i=0; 
	bool centi=false;
	
	cout<<"Ingrese el numero que va a buscar dentro del arreglo: ";
	cin>>num;
	
	for(; p<&vector[N]; p++, i++){
		
		if(*p==num){
			cout<<"El numero "<<num<<" se encuentra en la posicion ["<<i+1<<"]"<<endl;
			centi=true;
		}
	}
	
	if(centi==false){
		cout<<"El numero "<<num<<" no se encuentra dentro del arreglo"<<endl;
	}
}

void estadisticas(int vector[], int N){
	
	int *p=vector, pares=0, impares=0, ceros=0;
	float suma=0;
	
	for(; p<&vector[N]; p++){
		suma+=*p;
		
		if(*p==0){
			ceros++;
		}
		
		if(*p%2==0 && *p!=0){
			pares++;
		}
		else{
			impares++;
		}
	}
	
	cout<<"Estadisticas"<<endl;
	cout<<"Promedio: "<<suma/N<<endl;
	cout<<"Porcentaje de pares: "<<(pares*100)/N<<"%"<<endl;
	cout<<"Porcentaje de impares: "<<(impares*100)/N<<"%"<<endl;
	cout<<"Porcentaje de ceros: "<<(ceros*100)/N<<"%"<<endl;
}

