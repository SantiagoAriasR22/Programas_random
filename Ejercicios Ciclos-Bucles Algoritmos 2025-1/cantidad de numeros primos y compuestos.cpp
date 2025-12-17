#include <iostream>
using namespace std;

int main(){
	int numero=0, divisores=0, k=0, i=1, primos=0, compuestos=0;
	char salida;
	setlocale(LC_ALL, "spanish");
	do{
		cout<<"Ingrese un numero: ";
		cin>>numero;
		
		k=0;
		i=1;
		do{
			divisores=numero%i;
			if(divisores==0){
				k++;
			}
			i++;
		}while(i<=numero);
		
		if(k==2){
			primos++;
		}
		else{
			compuestos++;
		}
		
		cout<<"¿Desea ingresar otro numero?: [S]i - [N]o"<<endl;
		cin>>salida;
	}while(toupper(salida)=='S');
	
	cout<<"Cantidad de numeros primos: "<<primos<<endl;
	cout<<"Cantidad de numeros compuestos: "<<compuestos<<endl;
}
