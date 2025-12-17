#include<iostream>
using namespace std;

int main(){
	int n, m, i=1, mod=0, sumatorian=0, sumatoriam=0;
	char salida;
	
	do{
		i=1; sumatorian=0; sumatoriam=0; m=0; n=0; mod=0;
		cout<<"Ingrese un numero: ";
		cin>>n;
		do{
			cout<<"El numero ingresado tiene que ser distinto de "<<n<<endl;
			cout<<"Ingrese otro numero para verificar si es un par amigable del numero anterior: ";
			cin>>m;
		}while(m==n);
		do{
			mod=n%i;
			if(mod==0){
				sumatorian+=i;
			}
			i++;
		}while(i<n);

		i=1;
		mod=0;
		
		do{
			mod=m%i;
			if(mod==0){
				sumatoriam+=i;
			}
			i++;
		}while(i<m);
		
		if((sumatorian==m) && (sumatoriam==n)){
			cout<<n<<" y "<<m<<" son un par amigable"<<endl;
		}
		else{
			cout<<n<<" y "<<m<<" no son un par amigable"<<endl;
		}
	
		cout<<"Quiere ingresar otro dos numeros para comprobar que sean pares amigables? [S]i - [N]o ";
		cin>>salida;
	}while(toupper(salida)=='S');
}
