#include <iostream>
using namespace std;

void comprobar(int *q);
int main(){
	
	setlocale(LC_ALL, "spanish");
	
	int N;
	
	cout<<"Ingrese la cantidad de datos que quiere cargar en el vector: ";
	cin>>N; 
	
	int vec[N];
	
	for(int i=0; i<N; i++){
		cout<<"Ingrese el dato que va a guardar en la posicion "<<i+1<<": "<<endl;
		cin>>vec[i];
		comprobar(&vec[i]);
	}	
	
	system("pause");
}

void comprobar(int *q){
	
	int N=5;
	bool centi=false;
	
	for(int i=1; i<=*q && centi!=true; i++){
		
		if(*q==N){
			centi=true;
		}
		
		if(i%2==0){
			N+=2;
		}
		else{
			N+=3;
		}
		
		//cout<<"["<<N<<"]";
	}
	
	if(centi==true){
		cout<<*q<<" si pertenece a la secuencia"<<endl;
	}
	else{
		cout<<*q<<" no pertenece a la secuencia"<<endl;
	}
	
}

