#include <iostream>
using namespace std;

void par_impar(int numero);
int main(){
	int N=0, numero=0;
	
	cout<<"Cuantos numeros quiere ingresar?: ";
	cin>>N;
	
	for(int i=0; i<N; i++){
		cout<<"Ingrese el numero #"<<i+1<<": ";
		cin>>numero;
		
		cout<<numero;
		par_impar(numero);
	}
}

void par_impar(int numero){
	
	if(numero % 2 == 0){
		cout<<" es par"<<endl;
	}
	else{
		cout<<" es impar"<<endl;
	}
}

