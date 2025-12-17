#include <iostream>
using namespace std;

int main(){
	int CantidadEmpleados=0, Sueldo=0, CantidadHrsTrabajadas, VlrHora=0, TotalNomina=0, CantidadEmpleadosHrs=0, i=1;
	float SalarioPromedio=0;
	
	cout<<"Ingrese el numero de empleados: ";
	cin>>CantidadEmpleados;
	cout<<"Ingrese el valor de la hora: ";
	cin>>VlrHora;
	
	do{
		cout<<"Ingrese la cantidad de horas trabajadas por el empleado numero "<<i<<": ";
		cin>>CantidadHrsTrabajadas;
		
		Sueldo=VlrHora*CantidadHrsTrabajadas;
		
		if(CantidadHrsTrabajadas<240){
			CantidadEmpleadosHrs++;
		}
		
		cout<<"El salario a pagar al empleado numero "<<i<<" es de: "<<Sueldo<<endl;
		
		TotalNomina+=Sueldo;
		
		i++;
	}
	while(i<=CantidadEmpleados);
	
	SalarioPromedio=TotalNomina/CantidadEmpleados;
	
	cout<<"El valor a cancelar por la nomina es de: "<<TotalNomina<<endl<<"El salario promedio es de: "<<SalarioPromedio<<endl<<"La cantidad de empleados que trabajaron menos de 240 horas es de: "<<CantidadEmpleadosHrs<<endl;
}
