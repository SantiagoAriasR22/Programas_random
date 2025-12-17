#include<iostream>
using namespace std;

int main(){
	long long n, aux, sumadig=0, potencia=1, sumap, k=1, dig2=0, i=1, dig, aux2, aux3, d=0, aux4, p=0;
	
	cout<<"Ingrese un numero: ";
	cin>>n;
	
	aux3=n;
	do{
		aux3/=10;
		d++;
	}while(aux3>0);
	
	do{
		sumap=0;
		aux=i;
		do{
			dig=aux%10;
			aux/=10;
			potencia=1;
			k=1;
			do{
				potencia*=dig;
				k++;
			}while(k<=3);
			//cout<<potencia<<endl;
			sumap+=potencia;
			//cout<<sumap<<endl;
		}while(aux>0);
		p=0;
		aux4=i;
			do{
				aux4/=10;
				p++;
			}while(aux4>0);
		if((sumap==n)&&(d==p)){
			aux2=i;
			do{
				dig2=aux2%10;
				aux2/=10;
				cout<<dig2<<endl;
				//cout<<"Bueno"<<endl;
			}while(aux2>0);
			//cout<<i<<endl;
			//cout<<sumap<<endl;
			exit(0);
		}
		i++;
	}while(i<n);
	cout<<"Malo"<<endl;
	//cout<<sumap<<endl;
}
