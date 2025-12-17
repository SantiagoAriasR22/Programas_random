#include <iostream>
using namespace std; 

int main(){
	int DepositoInicial=0, DepositoFinal=0;
	
	for(int i=1; i<=12; i++){
		cout<<"Mes "<<i<<endl;
		cout<<"Ingrese la cantidad de dinero que va a ingresar este mes: ";
		cin>>DepositoInicial;
		
		DepositoFinal+=DepositoInicial;
		cout<<"Esto es lo que lleva ahorrado en el mes "<<i<<": "<<DepositoFinal<<endl;
	}
	cout<<"Este es el ahorro final: "<<DepositoFinal;
}
