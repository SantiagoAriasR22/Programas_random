#include <iostream>
using namespace std;

int main(){
	int NumeroEmpleados=0, Sueldo=0, PagoTotal=0, EmpleadosMinimo=0, i=1;
	
	cout<<"Ingrese el numero de empleados: ";
	cin>>NumeroEmpleados;
	
	do{
		cout<<"Ingrese el salario del empleado: ";
		cin>>Sueldo;
		PagoTotal+=Sueldo;
		i++;
		if(Sueldo>1423500){
			EmpleadosMinimo++;
		}
	}
	while(i<=NumeroEmpleados);
	cout<<"El pago total a la nomina sera de: "<<PagoTotal<<endl<<"Empleados que ganan mas de un salario minimo: "<<EmpleadosMinimo<<endl;
}
