#include <iostream>
using namespace std;

int main(){
	int n, contador=0, numero=2, i=1, div=0, p=0;
	
	cout<<"Ingrese un numero cualquiera: ";
	cin>>n;
	
	do{
		i=1;
		p=0;
		do{
			div=numero%i;
			if(div==0){
				p++;
			}
			i++;
		}while(i<=numero);
		if(p==2){
			cout<<numero<<endl;
			contador++;
		}
		numero++;
	}while(contador<n);
}
