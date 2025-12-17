#include<iostream>
using namespace std;

int main(){
	
	int N, i=0;
	
	cout<<"Ingrese el tamaño de ambos vectores: ";
	cin>>N;
	
	int vector1[N];
	int vector2[N];
	int vector3[N];
	
	int *p=vector1, *q=vector2, *v=vector3;
	
	cout<<"---Vector 1---"<<endl;
	for(; p<&vector1[N]; p++, i++){
		cout<<"Ingrese el valor a guardar en la posicion "<<i+1<<endl;
		cin>>*p;
	}
	
	i=0;
	p=vector1;
	q=vector2;
	
	cout<<"---Vector 2---"<<endl;
	for(; q<&vector2[N]; q++, i++){
		cout<<"Ingrese el valor a guardar en la posicion "<<i+1<<endl;
		cin>>*q;
	}
	
	p=vector1;
	q=vector2;
	
	cout<<"---Vector 3---"<<endl;
	for(; p<&vector1[N]; p++, q++, v++){
		*v=*p+*q;
	}
	
	p=vector1;
	q=vector2;
	v=vector3;
	
	for(; v<&vector3[N]; v++){
		cout<<"["<<*v<<"]";
	}
}
