#include <iostream>
using namespace std;

int main(){
	int A, B, C, area, perimetro; 
	char salida;
	
	do{
		cout<<"Ingrese la base A del triangulo: ";
		cin>>A;
		cout<<"Ingrese la altura B del triangulo: ";
		cin>>B;
		cout<<"Ingrese el lado C del triangulo: ";
		cin>>C;
		
		perimetro=A+B+C;
		
		if(perimetro>15){
			area=(A*B)/2;
			cout<<"Area del triangulo: "<<area<<endl;
		}
		cout<<"Quiere ingresar la informacion de otro articulo? [S]i - [N]o: ";
		cin>>salida;
	}while(toupper(salida)=='S');
}
