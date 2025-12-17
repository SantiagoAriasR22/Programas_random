#include <iostream>
using namespace std;
#define N 3

struct trabajador{
	long id;
	char nombre[50];
	char cargo[50];
	long salario;
};

struct empresa{
	long nit;
	char nombre[50];
	char dir[50];
	trabajador empleados[N];
};

void registro(empresa &empre){
	
	cout<<"Registro de la empresa"<<endl;
	
	cout<<"Nit: ";
	cin>>empre.nit;
	cout<<"Direccion: ";
	fflush(stdin); gets(empre.dir);
	cout<<"Nombre del gerente: ";
	fflush(stdin); gets(empre.nombre);
	
	cout<<"Informacion de los empleados"<<endl;
	for(int j=0; j<N; j++){
		cout<<"Empleado #"<<j+1<<endl;
		cout<<"Identificacion: ";
		cin>>empre.empleados[j].id;
		
		cout<<"Nombre: ";
		fflush(stdin); gets(empre.empleados[j].nombre);
		
		cout<<"Cargo: ";
		fflush(stdin); gets(empre.empleados[j].cargo);
		
		cout<<"Salario: ";
		cin>>empre.empleados[j].salario;
	}
}

void datos(struct empresa empre){
	
	long acum=0;
	
	cout<<"Datos de la empresa"<<endl<<endl;
	cout<<"Nit: "<<empre.nit<<endl;
	cout<<"Direccion: "<<empre.dir<<endl;
	cout<<"Nombre del gerente: "<<empre.nombre<<endl<<endl;
	
	cout<<"Datos de los empleados"<<endl;
	for(int i=0; i<N; i++){
		cout<<"Empleado #"<<i+1<<endl;
		cout<<"Nombre: "<<empre.empleados[i].nombre<<endl;
		cout<<"Identificacion: "<<empre.empleados[i].id<<endl;
		cout<<"Cargo: "<<empre.empleados[i].cargo<<endl;
		cout<<"Salario: "<<empre.empleados[i].salario<<endl;
		acum+=empre.empleados[i].salario;
	}
	
	cout<<"Valor de la nomina: "<<acum<<endl;
	cout<<"Salario promedio: "<<acum/N<<endl;
}

int main(){
	
	empresa empre;
	
	cout<<"Presione enter para entrar al registro"<<endl;
	cin.get();
	registro(empre);
	
	cout<<"Presione enter para visualizar los datos de la empresa: "<<endl;
	cin.get();
	datos(empre);
	
	
}
