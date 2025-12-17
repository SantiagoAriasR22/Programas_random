#include<iostream>
#include<conio.h>
using namespace std;

bool digitos_par(int N, int &suma);
void guardar_dig(int vector[], int &suma, int N);

int main(){
	int N, suma=0, i=0;
	bool centi;
	
	do{
		if(i>=1){
			cout<<"El numero ingresado no fue par, por favor ingrese otro nuevamente"<<endl;
			suma=0;
		}
		cout<<"Ingrese un numero para verificar si es vampiro o no: ";
		cin>>N;
		
		centi=digitos_par(N, suma);
		i++;
	}while(centi!=false);
	
	int vector[suma];
	
	guardar_dig(vector, suma, N);
}

bool digitos_par(int N, int &suma){
	
	int dig=0;
	do{
		dig=N%10;
		N/=10;
		suma++;
	}while(N>0);
	
	if((suma-1)%2==0){
		return true;
	}
	else{
		return false;
	}
}



