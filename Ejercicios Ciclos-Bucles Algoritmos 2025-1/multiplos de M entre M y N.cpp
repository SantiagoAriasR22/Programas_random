#include <iostream>
using namespace std;

int main(){
	int m, n, i=1, div=0, suma=0;
	
	cout<<"Ingrese un numero: ";
	cin>>m;
	do{
		cout<<"Ingrese un numero mayor al anterior: ";
		cin>>n;
	}while(n<m);

	do{
		div=i%m;
		if(div==0){
			suma+=i;
		}
		i++;
	}while(i<=n);
	cout<<"La suma de los multiplos entre "<<m<<" y "<<n<<" es igual a: "<<suma<<endl;
}
