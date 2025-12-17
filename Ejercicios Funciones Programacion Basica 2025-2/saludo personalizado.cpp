#include <iostream>
using namespace std;

void saludo();
int main(){
	string nombre;
	cout<<"Ingrese su nombre: ";
	fflush(stdin); getline(cin, nombre);
	
	saludo();
	cout<<nombre<<endl;
}
void saludo(){
	cout<<"Hello, welcome"<<endl;
	cout<<"How are you ";
}

