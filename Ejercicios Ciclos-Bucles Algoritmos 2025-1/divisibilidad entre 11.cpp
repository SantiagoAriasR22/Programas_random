#include <iostream>
using namespace std;

int main(){
	int n, digito, i=1, sumatoriap=0, sumatoriai=0, mod=0, aux=0;
	
	cout<<"Ingrese un numero: ";
	cin>>n;
	
	aux=n;
	
	do{
		digito=n%10;
		n/=10;
		mod=i%2;
		if(mod==0){
			sumatoriap+=digito;
		}
		else{
			sumatoriai+=digito;
		}
		i++;
	}while(0<n);
	if(sumatoriai==sumatoriap){
		cout<<aux<<" es exactamente divisible entre 11 y su resultado es: "<<aux/11<<endl;
	}
	else{
		cout<<aux<<" no es exactamente divisble entre 11 :("<<endl;
	}
}
