#include <iostream>
using namespace std;

void contador_focos(int &verdes, int &rojos, int &blancos, int color);
int main(){
	int N=0, verdes=0, blancos=0, rojos=0, color=0;
	setlocale(LC_ALL, "spanish");
	
	cout<<"Ingrese el tamaño del lote de focos: ";
	cin>>N;
	
	for(int i=0; i<N; i++){
		cout<<"Escriba el color del bombillo "<<i+1<<endl;
		cout<<"1. verde -- 2. Blanco -- 3. Rojo: "<<endl;
		cin>>color;
		contador_focos(verdes, rojos, blancos, color);
	}
	cout<<"El numero de focos del lote es de: "<<N<<endl;
	cout<<"Numero de focos verdes: "<<verdes<<endl;
	cout<<"Numero de focos blancos: "<<blancos<<endl;
	cout<<"Numero de focos rojos: "<<rojos<<endl;
}

void contador_focos(int &verdes, int &rojos, int &blancos, int color){
	
	switch(color){
		case 1: verdes++; break;
		case 2: blancos++; break;
		case 3: rojos++; break;
	}
}

