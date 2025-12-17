#include <iostream>
using namespace std;

int main(){
	int N, X, M;
	
	do{
		cout<<"Ingrese un numero positivo: ";
		cin>>N;
		cout<<"Ingrese otro numero positivo menor que el anterior: ";
		cin>>X;
	}
	while((X<=0)||(N<=0) || (X>N));
	
	for(int i=X; i<=N; i++){
		
		M=i%X;
		if(M==0){
			cout<<"Los multiplos entre "<<N<<" y "<<X<<" son: "<<i<<endl;
		}
	}
}
