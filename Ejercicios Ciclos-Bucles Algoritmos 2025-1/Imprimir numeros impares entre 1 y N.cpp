#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int N;
	
		do{
		cout<<"Ingrese un numero cualquiera :";
		cin>>N;
		if(N<=0){
			cout<<"Ingrese un numero de 1 en adelante"<<endl;
		}
	}
		while(N<=0);
		
		for(int NI=1; NI<=N; NI+=2){
			cout<<NI<<endl;
		}
		return 0;
}
