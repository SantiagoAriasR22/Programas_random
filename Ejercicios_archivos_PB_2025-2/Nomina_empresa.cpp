#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct empleado{
	
	char nombre[50];
	long id;
	long sal_hrs;
	int hrs_ordi;
	int hrs_ext_diur;
	int hrs_ext_noct;
	int hrs_ext_domi;
	
};

int menu();
void registro();
bool valid_id(long id);
	
int main(){
	
	int opc;
	
	do{
		opc=menu();
	
	switch(opc){
		case 1:
			registro(); break;
	}
	}while(opc!=5);
	
}


int menu(){
	int opc;
	
	cout<<"Menu"<<endl;
	cout<<"1. Cargar datos nomina"<<endl;
	cout<<"2. Generar nomina"<<endl;
	cout<<"3. Consultar empleado"<<endl;
	cout<<"4. Reporte nomina"<<endl;
	cout<<"5. Salir"<<endl;
	cin>>opc;
	
	return opc;
}

void registro(){
	
	static int i=1;
	int centi;
	empleado emp;
	
	do{
		cout<<"Empleado #"<<i++<<endl;
		cout<<"ID: ";
		cin>>emp.id;
		if(valid_id(emp.id)){
			cout<<"Esta id ya esta registrada"<<endl;
		}
		else{
			cout<<"Nombre: ";
			cin.ignore(); cin.getline(emp.nombre, 50);
			
			cout<<"Salario base por hora: ";
			cin>>emp.sal_hrs;
			
			cout<<"Horas ordinarias reportadas: ";
			cin>>emp.hrs_ordi;
			
			cout<<"Horas extras diurnas reportadas: ";
			cin>>emp.hrs_ext_diur;
			
			cout<<"Horas extras nocturnas reportadas: ";
			cin>>emp.hrs_ext_noct;
			
			cout<<"Horas extras dominicales reportadas: ";
			cin>>emp.hrs_ext_domi;
			
			ofstream archivo("Nomina.txt", ios::app | ios::binary);
			
			if(archivo.fail()){
				cout<<"No se pudo abrir el archivo correctamente"<<endl;
				return;
			}
			
			archivo.write(reinterpret_cast<char*>(&emp), sizeof(empleado));
			archivo.close();
			
			cout<<"Desea ingresar otro empleado 1. Si -- 2. No: ";
			cin>>centi;
		}
		
	}while(centi!=2);
	
}

bool valid_id(long id){
	
	ifstream archivo("Nomina.txt", ios::in | ios::binary);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo correctamente"<<endl;
		exit(0);
	}
	
	empleado emp;
	
	archivo.read(reinterpret_cast<char*>(&emp), sizeof(empleado));
	
	while(!archivo.eof()){
		
		if(emp.id==id){
			return true;
	}
		
	archivo.read(reinterpret_cast<char*>(&emp), sizeof(empleado));
		
	}
	return false;
	archivo.close();
	
}
