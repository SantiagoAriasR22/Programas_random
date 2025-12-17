#include <iostream>
using namespace std;

int main(){
	int base;
	string asterisco;
	setlocale(LC_ALL, "spanish");
	cout<<"Ingrese el tamaño de la base del triangulo: ";
	cin>>base;
	
	for(int i=1; i<=base; i++){
		asterisco+="*";
		cout<<asterisco<<endl;
	}
}
