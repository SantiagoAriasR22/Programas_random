#include <iostream>
using namespace std;

void almacenar(int numero, int categoria[], int *ind, int *suma);
int clasificar(int n1);
void cargar(int vec[], int N);
int main(){
	
	setlocale(LC_ALL, "spanish");
	
	int opcion, N, n1, suma, abun=0, perf=0, defi=0, suma1=0, suma2=0, suma3=0;
	
	cout<<"Ingrese el tamaño del vector: ";
	cin>>N;
	
	system("cls");
	
	int vec[N];
	int abundantes[N];
	int perfectos[N];
	int deficientes[N];
	
	do{
		system("cls");
		do{
			cout<<"MENU"<<endl;
			cout<<"1. Llenar el vector"<<endl;
			cout<<"2. Clasificar los elementos del vector"<<endl;
			cout<<"3. Imprimir los vectores"<<endl;
			cout<<"4. Salir"<<endl;
			cin>>opcion;
		}while(opcion<1 || opcion>4);
		
		switch(opcion){
			case 1: cargar (vec, N); break;
			case 2:
				
				for(int i=0; i<N; i++){
					n1=vec[i];
					suma=clasificar(n1);
					
					if(suma<n1){
						cout<<n1<<" es un numero deficiente"<<endl;
						almacenar(n1, deficientes, &defi, &suma1);
						system("pause");
					}
					else if(suma==n1){
						cout<<n1<<" es un numero perfecto"<<endl;
						almacenar(n1, perfectos, &perf, &suma2);

						system("pause");
					}
					else{
						cout<<n1<<" es un numero abundante"<<endl;
						almacenar(n1, abundantes, &abun, &suma3);
						system("pause");
					}
				}	
				system("cls");
			break;
			
			case 3:
				
				cout<<"Vector inicial"<<endl;
				for(int i=0; i<N; i++){
					cout<<"["<<vec[i]<<"]";
				}
				cout<<endl;
				
				cout<<"Vector de abundantes"<<endl;
				for(int i=0; i<abun; i++){
					cout<<"["<<abundantes[i]<<"]";
				}
				cout<<endl;
				
				cout<<"Vector de perfectos"<<endl;
				for(int i=0; i<perf; i++){
					cout<<"["<<perfectos[i]<<"]";
				}
				cout<<endl;
				
				cout<<"Vector de deficientes"<<endl;
				for(int i=0; i<defi; i++){
					cout<<"["<<deficientes[i]<<"]";
				}
				cout<<endl;
				system("pause");
				
			break;
		}
	}while(opcion!=4);
}

void cargar(int vec[], int N){
	
	for(int i=0; i<N; i++){
		cout<<"Ingrese el dato a guardar en la posicion ["<<i+1<<"]: ";
		cin>>vec[i];
	}
}

int clasificar(int n1){
	
	int suma=0, dig;
	
	for(int i=1; i<n1-1; i++){
		if(n1%i==0){
			suma+=i;
		}
	}
	
	return suma;
}

void almacenar(int numero, int categoria[], int *ind, int *suma){
	
	categoria[*ind]=numero;
	(*ind)++;
	*suma+=numero;
}

