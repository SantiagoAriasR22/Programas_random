#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int NumeroEstudiantes=0, Estudiantes=0, i=1;
	float Parcial1=0, Parcial2=0, Parcial3=0;
	
	cout<<"Ingrese la cantidad de estudiantes: ";
	cin>>NumeroEstudiantes;
	while(NumeroEstudiantes<0){
		cout<<"Valor Invalido"<<endl<<"Ingrese otra vez el numero de estudiantes: "; cin>>NumeroEstudiantes;
	}
	
	do{
		cout<<"Estudiante numero "<<i<<endl;
		cout<<"Ingrese la nota del primer parcial: ";
		cin>>Parcial1;
		cout<<"Ingrese la nota del segundo parcial: ";
		cin>>Parcial2;
		Parcial3=(3.0-(Parcial1*0.30)-(Parcial2*0.30))/0.4;
		cout<<"El estudiante "<<i<<" necesita sacar en el tercer parcial por lo menos "<<Parcial3<<" si quiere ganar la asignatura"<<endl;
		
		if(3<Parcial3 && 4>Parcial3){
			Estudiantes++;
		}
		i++;
	}
	while(i<=NumeroEstudiantes);
	
	cout<<"La cantidad de estudiantes que necesita sacar 3 para ganar la asignatura es de: "<<Estudiantes<<" estudiantes"<<endl;
}
