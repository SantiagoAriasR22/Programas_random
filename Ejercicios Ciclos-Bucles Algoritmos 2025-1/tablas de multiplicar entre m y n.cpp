#include<iostream>
using namespace std;

int main(){
	int m, n, i=1; 
	
	cout<<"Ingrese un numero: ";
	cin>>m;
	do{
		cout<<"Ingrese otro numero mayor al anterior: ";
		cin>>n;
	}while(n<m);
	
	do{
		i=1;
		cout<<"Tabla de multiplicar del "<<m<<endl;
		do{
			cout<<m<<" x "<<i<<" = "<<m*i<<endl;
			i++;
		}while(i<=10);
		cout<<endl;
		m++;
	}while(m<=n);
}
