#include <iostream>
using namespace std;

int main(){
	long numero=0, suma_pote=1, digito=0, k=0, aux, i=1, num_pote=0, sumatoria=0;
	
	cout<<"Ingrese un numero para comprobar si es narcisista: ";
	cin>>numero;
	
	aux=numero;
	
	do{
		digito=numero%10;
		numero/=10;
		k++;
	}while(numero>0);
	
	numero=aux;
	
	do{
		digito=numero%10;
		suma_pote=1;
		i=1;
		do{
			suma_pote*=digito;
			i++;
		}while(i<=k);
			sumatoria+=suma_pote;
			numero/=10;
	}while(numero>0);
	if(sumatoria==aux){
		cout<<aux<<" si es un numero narcisista"<<endl;
	}
	else{
		cout<<aux<<" no es un numero narcisista"<<endl;
	}
}
