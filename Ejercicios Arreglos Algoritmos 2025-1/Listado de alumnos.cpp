#include <iostream>
using namespace std;

int main(){
	int N, mayor=0;
	float promedio=0, sumatoria=0, aux;
	string aux2;
	
	do{
		cout<<"Ingrese el numero de estudiantes: ";
		cin>>N;
	}while(N<=0);
	
	float notas[N];
	string nombres[N];
	
	for(int i=0; i<=N-1; i++){
		cout<<"Ingrese el nombre del estudiante: ";
		cin>>nombres[i];
		cout<<"Ingrese las notas del estudiante "<<nombres[i]<<": ";
		cin>>notas[i];
		sumatoria+=notas[i];
	}
	
	promedio=sumatoria/N;
	
	for(int i=0; i<=N-1; i++){
		for(int j=0; j<=N-1; j++){
			if(nombres[j] > nombres[j+1]){
				aux=notas[j];
				notas[j]=notas[j+1];
				notas[j+1]=aux;
				aux2=nombres[j];
				nombres[j]=nombres[j+1];
				nombres[j+1]=aux2;
			}
		}
	}
	
	for(int i=0; i<=N-1; i++){
		cout<<notas[i]<<endl;
		if(notas[i] > promedio){
				mayor++;
			}
	}
	cout<<"Porcentajes de alumnos con una nota mayor al promedio: "<<(mayor*100)/N<<"%";
}
