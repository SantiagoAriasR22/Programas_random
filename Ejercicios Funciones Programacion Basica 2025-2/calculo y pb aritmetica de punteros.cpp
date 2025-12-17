#include<iostream>
#include <iomanip>
using namespace std;

void integral (long calculo[], int M);
void pb(long programacion[], int N);
void ambos(long calculo[], long programacion[], int M, int N);

int main(){
	
	int M, N;
	
	cout<<"Ingrese cuantos estudiantes perdieron calculo integral: ";
	cin>>M;
	
	system("pause");
	system("cls");
	
	long calculo[M];
	
	integral(calculo, M);
	
	cout<<"Ingrese cuantos estudiantes perdieron programacion basica: ";
	cin>>N;
	
	long programacion[N];
	
	pb(programacion, N);
	
	ambos(calculo, programacion, M, N);
}

void integral (long calculo[], int M){
	
	long *p=calculo;
	int i=0;
	
	cout<<"==REGISTRO DE ESTUDIANTES=="<<endl;
	cout<<"Ingrese el codigo de cada uno de los estudiantes que perdieron la asignatura: "<<endl;
	for(; p<&calculo[M]; p++, i++){
		cout<<"Estudiante #"<<i+1<<": "<<endl;
		cin>>*p;
	}
	
	cout<<"El registro se hizo exitosamente"<<endl;
	system("pause");
	system("cls");
}

void pb(long programacion[], int N){
	
	long *q=programacion;
	int i=0;
	
	cout<<"==REGISTRO DE ESTUDIANTES=="<<endl;
	cout<<"Ingrese el codigo de cada uno de los estudiantes que perdieron la asignatura: "<<endl;
	for(; q<&programacion[N]; q++, i++){
		cout<<"Estudiante #"<<i+1<<": "<<endl;
		cin>>*q;
	}
	
	cout<<"El registro se hizo exitosamente"<<endl;
	system("pause");
	system("cls");
}

void ambos(long calculo[], long programacion[], int M, int N){
	
	int C=0, i=0;
	long *p=calculo, *q=programacion;
	
	for(; p<&calculo[M]; p++){
		for(q=programacion; q<&programacion[N]; q++){
			if(*p==*q){
				C++;
			}
		}
	}
	
	long vector[C];
	long *r=vector;
	p=calculo;
	q=programacion;
	
	for(; p<&calculo[M]; p++){
		for(q=programacion; q<&programacion[N]; q++){
			if(*p==*q){
				*r=*p;
				r++;
			}
		}
	}
	
	r=vector;
	
	cout<<"Codigo de estudiantes que perdieron tanto programacion basica como calculo integral: "<<endl;
	cout<<setw(15)<<"Estudiante"<<setw(15)<<"Codigo"<<endl;
	for(; r<&vector[C]; r++, i++){
		cout<<setw(15)<<i+1<<setw(15)<<*r<<endl;
	}
	system("pause");
}

