#include <iostream>
using namespace std;

int main(){
	int i=1, k=1, d=0, aux=0, digito=0, v=0, divisor=1, numero=0; 
	long long potencia=1;
	
	do{
		potencia=1;
		k=1;
		do{
			potencia*=i;
			k++;
		}while(k<=2);
		//cout<<potencia<<" p"<<endl;
		aux=i;
		
		d=0;

		do{
			aux/=10;
			d++;
		}while(aux>0);
		//cout<<d<<" d"<<endl;
		
		v=0;
		divisor=1;
		do{
			divisor*=10;
			v++;
		}while(v<d);
		//cout<<divisor<<" di"<<endl;
		numero=0;
		numero=potencia%divisor;
		//cout<<numero<<" n"<<endl;
		if(numero==i){
			cout<<i<<" Es automorfico"<<endl;
		}
		i++;
	}while(i<=1000);
	
	cout<<endl;
	//trimorficos
	i=1;
	do{
		potencia=1;
		k=1;
		do{
			potencia*=i;
			k++;
		}while(k<=3);
		//cout<<potencia<<" p"<<endl;
		aux=i;
		
		d=0;

		do{
			aux/=10;
			d++;
		}while(aux>0);
		//cout<<d<<" d"<<endl;
		
		v=0;
		divisor=1;
		do{
			divisor*=10;
			v++;
		}while(v<d);
		//cout<<divisor<<" di"<<endl;
		numero=0;
		numero=potencia%divisor;
		//cout<<numero<<" n"<<endl;
		if(numero==i){
			cout<<i<<" Es trimorfico"<<endl;
		}
		i++;
	}while(i<=1000);
}
