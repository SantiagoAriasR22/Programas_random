#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	
	int N;
	
	do{
		cout<<"Ingrese la cantidad de numeros naturales que quiere que sean impresos: ";
		cin>>N;
		
		if(N<0){
			cout<<"Por favor ingrese un numero positivo"; exit(0);
		}
	}
	while(N<0);
	
	cout<<"Los primeros "<<N<<" numeros naturales son: "<<endl;
	
	for(int NN=1; NN<=N; NN++)	{
		cout<<NN<<endl;
	}
	system("pause");
}
