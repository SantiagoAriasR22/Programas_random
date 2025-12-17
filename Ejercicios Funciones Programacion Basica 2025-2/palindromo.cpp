#include <iostream>
using namespace std;

int main(){
	long N, resul=0, aux;
	int dig;
	
	cout<<"Digite un numero para comprobar si es palindromo: ";
	cin>>N;
	
	aux=N;
	
	do{
		dig=aux%10;
		resul=resul*10+dig;
		aux/=10;
	}while(aux!=0);
	
	if(resul==N){
		cout<<"Es palindromo"<<endl;
	}
	else{
		cout<<"No es palindromo"<<endl;
	}
}
