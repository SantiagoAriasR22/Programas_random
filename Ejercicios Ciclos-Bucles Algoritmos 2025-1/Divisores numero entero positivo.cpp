#include <iostream>
using namespace std;

int main(){
	int N, D;
	
	do{
		cout<<"Ingrese un numero positivo cualquiera: ";
		cin>>N;
	}
	while(N<=0);
	
	for(int i=1; i<=N; i++){
		
		D=N%i;
		if(D==0){
			cout<<"Los divisores de "<<N<<" son: "<<i<<endl;
		}
	}
}
