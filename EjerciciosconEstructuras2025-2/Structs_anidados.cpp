#include<iostream>
#define p 1
using namespace std;

struct date{
	int dd;
	int mm;
	int aa;
};

struct pac{
	long id;
	char nombre[50];
	char motivo[150];
	date fecha;
};

struct medico{
	long reg;
	char nombre[50];
	char especialidad[50];
	int consultorio;
	pac paciente[p];	
};

int menu();
void registro(struct medico doc[], int N);
void listado(struct medico doc[], int N);
void consulta(struct medico doc[], int N);

int main(){
	int opc, N;
	setlocale(LC_ALL, "spanish");
	
	cout<<"Bienvenido al registro medico"<<endl;
	cout<<"Ingrese el numero de medicos: ";
	cin>>N;
	
	medico doc[N];
	
	do{
		opc=menu();
		switch(opc){
			case 1: registro(doc, N); break;
			case 2: listado(doc, N); break;
			case 3: consulta(doc, N); break;
		}
	}while(opc!=4);
}

int menu(){
	
	int op;
	
	do{
		cout<<"Menu"<<endl;
		cout<<"1. Ingresar datos"<<endl;
		cout<<"2. Listado de medicos"<<endl;
		cout<<"3. Consultar medico"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>op;
	}while(op<1 || op>4);
	
	return op;
}

void registro(struct medico doc[], int N){
	
	cout<<"Registro"<<endl;
	for(int i=0; i<N; i++){
		cout<<"Asignacion de pacientes"<<endl;
		cout<<"Medico #"<<i+1<<endl;
		
		cout<<"Registro medico: ";
		cin>>doc[i].reg;
		
		cin.ignore();
		cout<<"Nombre del medico: ";
		gets(doc[i].nombre);
		
		cout<<"Especialidad: ";
		gets(doc[i].especialidad);
		
		cout<<"Consultorio"<<endl;
		cin>>doc[i].consultorio;
		
		for(int j=0; j<p; j++){
			cout<<"Datos del paciente #"<<j+1<<endl;
			
			cout<<"Identificacion: ";
			cin>>doc[i].paciente[j].id;
			
			cout<<"Nombre: ";
			fflush(stdin); gets(doc[i].paciente[j].nombre);
			
			cout<<"Motivo de consulta: ";
			fflush(stdin); gets(doc[i].paciente[j].motivo);
			
			cout<<"Fecha de consulta"<<endl;
			cout<<"Dia: ";
			cin>>doc[i].paciente[j].fecha.dd;
			cout<<"Mes: ";
			cin>>doc[i].paciente[j].fecha.mm;
			cout<<"Año: ";
			cin>>doc[i].paciente[j].fecha.aa;
		}
	}
}

void listado(struct medico doc[], int N){
	
	cout<<endl;
	cout<<"Listado"<<endl;
	
	for(int i=0; i<N; i++){
		cout<<"Medico #"<<i+1<<endl;
		
		cout<<"Nombre: "<<doc[i].nombre<<endl;
		cout<<"Registro medico: "<<doc[i].reg<<endl;
		cout<<"Especialidad: "<<doc[i].especialidad<<endl;
		cout<<"Consultorio: "<<doc[i].consultorio<<endl;
		
		cout<<"Pacientes: "<<endl;
		for(int j=0; j<p; j++){
			cout<<"Paciente #"<<j+1<<endl;
			
			cout<<"Nombre: "<<doc[i].paciente[j].nombre<<endl;
			cout<<"Identificacion: "<<doc[i].paciente[j].id<<endl;
			cout<<"Motivo de consulta: "<<doc[i].paciente[j].motivo<<endl;
			cout<<"Fecha: "<<doc[i].paciente[j].fecha.aa<<endl;
		}
	}
}

void consulta(struct medico doc[], int N){
	
	long aux=0;
	bool centi=false;
	cout<<"Consulta"<<endl;
	
	cout<<"Ingrese el registro medico a consultar: ";
	cin>>aux;
	
	for(int i=0; i<N; i++){
		if(aux==doc[i].reg){
			centi=true;
			
			for(int j=0; j<N; j++){
				cout<<"Paciente #"<<j+1<<endl;	
				cout<<"Nombre: "<<doc[i].paciente[j].nombre<<endl;
				cout<<"Identificacion: "<<doc[i].paciente[j].id<<endl;
				cout<<"Motivo de consulta: "<<doc[i].paciente[j].motivo<<endl;
				cout<<"Fecha: "<<doc[i].paciente[j].fecha.aa<<endl;
			}
		}
	}
	
	if(!centi) cout<<"No se encontro el registro digitado"<<endl;
}


