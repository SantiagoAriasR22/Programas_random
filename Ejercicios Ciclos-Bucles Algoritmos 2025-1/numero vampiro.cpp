#include <iostream>
using namespace std;

int main(){
	
	int n=0, div=0, k=1, d=0, aux=0, i=1, sumadig=0, sumadig2=0, dig=0, div2=0, n1=0, aux2=0, aux3=0, dig3=0, dig2=0;
	char verificar;
	
	do{
		cout<<"El numero tiene que ser compuesto OBLIGATORIAMENTE"<<endl;
		cout<<"Ingrese un numero para verificar si es vampiro o no: ";
		cin>>n;
		aux=n;
		do{
			sumadig=0;
			div=aux%k;
			if(div==0){
				d++;
			}
			k++;
		}while(k<=aux);
		if(d==2){
			verificar='S';
		}
		else{
			verificar='N';
		}
	}while(verificar=='S');
	
	//suma de los digitos de n
	do{
		dig=aux%10;
		sumadig+=dig;
		aux/=10;
	}while(aux>0);
	//cout<<sumadig<<endl;
	
	dig=0;
	div=0;
	do{
		div=n%k;
		do{
			div2=n%i;
			//cout<<div<<" Divisor 1"<<endl;
			//cout<<div2<<" Divisor 2"<<endl;
			if((div==0) && (div2==0)){
				n1=k*i;
				cout<<n1<<endl;
				if(n1==n){
					aux2=k; aux3=i;
					do{
						dig2=aux2%10;
						sumadig2+=dig2;
						aux2/=10;
					}while(aux2>0);
					do{
						dig3=aux3%10;
						sumadig2+=dig3;
						aux3/=10;
					}while(aux3>0);
					
					if(sumadig==sumadig2){
						cout<<n<<" es un numero vampiro :)";
					}
				}
			}
			i++;
		}while(i<=n);
		k++;
	}while(k<=n);
	cout<<n<<" no es un numero vampiro :(";
}
