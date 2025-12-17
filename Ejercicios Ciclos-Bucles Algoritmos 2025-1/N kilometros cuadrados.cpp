#include <iostream>
using namespace std;

int main(){
	float cant_person, person_max=0, a=0;
	float km;
	setlocale(LC_ALL, "spanish");
	
	cout<<"Ingrese la cantidad de kilometros cuadrados que tiene la zona: ";
	cin>>km;
	cout<<"Ingrese la cantidad de personas que tiene la zona: ";
	cin>>cant_person;
	person_max=km*15;
	
	if(cant_person>person_max){
		cout<<"Ya excedieron la capacidad de la region";
		exit(0);
	}
	
	do{
		cant_person+=5;
		cant_person*=1.10;
		cant_person*=0.95;
		cout<<cant_person<<endl;
		a++;
	}while(cant_person<=person_max);
	cout<<"La poblacion excedio por primera vez la capacidad de la region en "<<a<<" años"<<endl;
}
