#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int i=1, k=1;
	float peso_inicial=0, peso=0, sumatoria_peso=0, diferencia=0, peso_promedio=0;
	
	do{
		peso_inicial=0;
		cout<<"Persona #"<<i<<endl;
		cout<<"Ingrese cual fue su peso la ultima vez: ";
		cin>>peso_inicial;
		peso=0;
		sumatoria_peso=0;
		k=1;
		do{
			cout<<"Ingrese su peso actual: ";
			cin>>peso;
			sumatoria_peso+=peso;
			k++;
		}while(k<=10);
		peso_promedio=sumatoria_peso/10.0;
		diferencia=peso_promedio-peso_inicial;
		
		if(diferencia<0){
			cout<<"BAJO "<< abs(diferencia)<<endl;
		}
		else if(diferencia>0){
			cout<<"SUBIO "<<diferencia<<endl;
		}
		else{
			cout<<"NO HUBO CAMBIO"<<endl;
		}
		system("pause");
		system("cls");
		i++;
	}while(i<=5);
}
