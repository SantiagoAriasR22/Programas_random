#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int N;
	
	do{
		cout<<"Ingrese un numero cualquiera: ";
		cin>>N;
		if(N<=0){
			cout<<"Ingrese un numero de 1 en adelante"; exit(0);
		}
	}
	while(N<0);
	
	for(int NP=0; NP<=N; NP+=2){
		cout<<NP<<endl;
	}
	system("pause");
}
