#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

struct fecha{
	int dd;
	int mm;
	int aa;
};

struct empleado{
	long id;
	char nombre[50];
	fecha date;
	char sexo[50];
};

struct ventas{
	char nombre[50];
	long id;
	long t1;
	long t2;
	long t3;
	long t4;
	long anual;
	long boni;
};

void archivos();
int menu();
void registro_emple();
bool val_id(long aux, char* name);
void registro_ventas();
int menu_consul();
void consul_vende();
void repor_boni();

int main(){
	
	archivos();
	
	int opc, centi;
	
	do{
		opc=menu();
		
		switch(opc){
			case 1: 
			
				do{
					registro_emple();
					
					cout<<"Desea registrar otro empleado? 1. Si -- 2. No: ";
					cin>>centi;
				}while(centi!=2); break;
				
			case 2: 
			
				do{
					registro_ventas();
					
					cout<<"Desea registrar otro empleado? 1. Si -- 2. No: ";
					cin>>centi;
				}while(centi!=2); break;
				
			case 3: 
			
				int op;
				
				op=menu_consul();
				
				switch (op){
					case 1: consul_vende(); break;
					case 2: repor_boni(); break;
				}
				
			break;
		}
		
	}while(opc!=4);
}

void archivos(){
	
	ofstream archivo ("empleados.txt", ios::app | ios::binary);
	
	if(archivo.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		return;
	}
	
	archivo.close();
	
	ofstream archivo2 ("ventas.txt", ios::app | ios::binary);
	
	if(archivo2.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		return;
	}
	
	archivo2.close();
}

int menu(){
	
	int opc;
	
	do{
		cout<<"Menu"<<endl;
		cout<<"1. Registro de empleados"<<endl;
		cout<<"2. Registro de ventas"<<endl;
		cout<<"3. Generar reportes"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opc;
	}while(opc<1 || opc>4);
	
	return opc;
}

void registro_emple(){
	
	long aux;
	char nombre[50];
	empleado vende;
	
	cout<<endl;
	cout<<"Registro de empleados"<<endl;
	
	cout<<"ID: ";
	cin>>aux;
	
	if(val_id(aux, nombre)){
		cout<<"Este ID ya esta registrado, vuelva al menu e intentelo nuevamente"<<endl;
		system("pause");
		return;
	}
	else{
		
		ofstream archivo("empleados.txt", ios::app | ios::binary);
	
		if(archivo.fail()){
			cout<<"El archivo no se pudo abrir correctamente"<<endl;
			system("pause");
			exit(0);
		}
		
		vende.id=aux;
		
		cout<<"Nombre: ";
		cin.ignore(); cin.getline(vende.nombre, 50);
		
		cout<<"Fecha de nacimiento: "<<endl;
		cout<<"Dia: ";
		cin>>vende.date.dd;
		cout<<"Mes: ";
		cin>>vende.date.mm;
		cout<<"Año: ";
		cin>>vende.date.aa;
		
		cout<<"Sexo: ";
		cin.ignore(); cin.getline(vende.sexo, 50);
		
		archivo.write(reinterpret_cast<char*>(&vende), sizeof(empleado));
	}
	
}

bool val_id(long aux, char* name){
	
	ifstream archivo("empleados.txt", ios::in | ios::binary);
	
	empleado vende;
	
	if(archivo.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		exit(0);
	}
	
	while(archivo.read(reinterpret_cast<char*>(&vende), sizeof(empleado))){
		
		if(aux==vende.id){
			strcpy(name, vende.nombre);
			archivo.close();
			return true;
		}
	}
	
	archivo.close();
	return false;
}

void registro_ventas(){
	
	long aux;
	char nombre[50];
	
	cout<<endl;
	cout<<"Registro de ventas"<<endl;
	
	cout<<"ID del vendedor: ";
	cin>>aux;
	
	if(val_id(aux, nombre)){
		
		ofstream archivo2 ("ventas.txt", ios::app | ios::binary);
		
		if(archivo2.fail()){
			cout<<"El archivo no se pudo abrir correctamente"<<endl;
			system("pause");
			exit(0);
		}
		
		ventas venta;
		
		venta.id=aux;
		strcpy(venta.nombre, nombre);
		
		cout<<"Nombre del vendedor: "<<nombre<<endl;
		cout<<"Ventas primer trimestre: ";
		cin>>venta.t1;
		
		cout<<"Ventas segundo trimestre: ";
		cin>>venta.t2;
		
		cout<<"Ventas tercer trimestre: ";
		cin>>venta.t3;
		
		cout<<"Ventas cuarto trimestre: ";
		cin>>venta.t4;
		
		venta.anual=venta.t1+venta.t2+venta.t3+venta.t4;
		
		if(venta.anual<5000000){
			venta.boni=venta.anual*0.05;
		}
		else if(venta.anual<10000000){
			venta.boni=venta.anual*0.08;
		}
		else{
			venta.boni=venta.anual*0.1;
		}
		
		archivo2.write(reinterpret_cast<char*>(&venta), sizeof(ventas));
		
		archivo2.close();
		
	}
	else{
		
		cout<<"El ID digitado no se encuentra registrado"<<endl;
		system("pause");
		return;
	}
}

int menu_consul(){
	
	int opc;
	
	do{
		cout<<"Menu de reportes"<<endl;
		cout<<"1. Consulta de vendedor"<<endl;
		cout<<"2. Reporte pago bonificacion"<<endl;
		cin>>opc;
	}while(opc<1 || opc>2);
	
	return opc;
}

void consul_vende(){
	
	long aux;
	char nombre[50];
	
	cout<<"ID del vendedor: ";
	cin>>aux;
	
	if(val_id(aux, nombre)){
		
		ifstream archivo2("ventas.txt", ios::in | ios::binary);
		
		if(archivo2.fail()){
			cout<<"El archivo no se pudo abrir correctamente"<<endl;
			system("pause");
			exit(0);
		}
		
		ventas venta;
		
		while(archivo2.read(reinterpret_cast<char*>(&venta), sizeof(ventas))){
			
			if(venta.id==aux){
				
				cout<<"Nombre: "<<venta.nombre<<endl;
				cout<<"Ventas primer trimestre: "<<venta.t1<<endl;
				cout<<"Ventas segundo trimestre: "<<venta.t2<<endl;
				cout<<"Ventas tercer trimestre: "<<venta.t3<<endl;
				cout<<"Ventas cuarto trimestre: "<<venta.t4<<endl;
				cout<<"Venta anual: "<<venta.anual<<endl;
				cout<<"Bonificacion: "<<venta.boni<<endl;
				
				system("pause");
				archivo2.close();
				
				return;
			}
		}
		cout<<"El vendedor no registra ventas"<<endl;
	}
}

void repor_boni(){
	
	long long vent_tot=0, max=0;
	long boni_tot=0;
	int i=0, j=0, x=0;
	
	cout<<setw(30)<<"REPORTE PAGO BONIFICACION"<<endl;
	cout<<setw(15)<<"Vendedor"<<setw(25)<<"T1"<<setw(25)<<"T2"<<setw(25)<<"T3"<<setw(25)<<"T4"<<setw(25)<<"Anual"<<setw(25)<<"Bonificacion"<<endl;
	
	ifstream archivo2("ventas.txt", ios::in | ios::binary);
	ventas venta;
	
	while(archivo2.read(reinterpret_cast<char*>(&venta), sizeof(ventas))){
		
		cout<<setw(15)<<venta.nombre<<setw(25)<<venta.t1<<setw(25)<<venta.t2<<setw(25)<<venta.t3<<setw(25)<<venta.t4<<setw(25)<<venta.anual<<setw(25)<<venta.boni<<endl;
		
		vent_tot+=venta.anual;
		boni_tot+=venta.boni;
		
		if(venta.anual<5000000){
			i++;
		}
		
		if(venta.anual>10000000){
			j++;
		}
		
		if(max<venta.anual){
			max=venta.anual;
		}
		
		x++;
	}
	
	archivo2.close();
	
	cout<<endl;
	cout<<"Venta total de la empresa: "<<vent_tot<<endl;
	cout<<"Bonificacion promedio: "<<boni_tot/x<<endl;
	cout<<"Porcentaje de vendedores con ventas anuales por debajo de 5000000: "<<(100*i)/x<<"%"<<endl;
	cout<<"Porcentaje de vendedores con ventas anual por encima de 10000000: "<<(100*j)/x<<"%"<<endl;
	cout<<"Vendedor con mayor volumen de venta: "<<max<<endl;
	
}
