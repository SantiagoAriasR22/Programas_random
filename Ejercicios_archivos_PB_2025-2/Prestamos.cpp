#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<time.h>
using namespace std;

time_t tiempo = time(0); // recibirá como parámetro un puntero nulo (es decir, NULL o 0) y devolverá el tiempo actual en una variable de tipo "time_t".
struct tm *tlocal = localtime(&tiempo);

struct persona{
	long id;
	char nombre[50];
	char dir[70];
	long long tele;
};

struct prestamo{
	
	long id;
	int num_prest;
	char nombre[50];
	char fecha_hora[128];
	long vlr;
	long interes;
	int num_cout;
	long vlr_cout;
	long total;
};

int menu();
void archivos();
void registro_client();
bool val_id(long aux, char* name);
void registro_prest();
int ultimo_prest();
int menu_consul();
void consul_cliente();
void report_prest();

int main(){
	
	int opc, centi, op;
	
	archivos();
	
	do{
		opc=menu();
		
		switch(opc){
			case 1: 
			
				do{
					
					registro_client();
					
					cout<<"Desea registrar otro cliente? 1. Si -- 2. No: ";
					cin>>centi;
				}while(centi!=2); break;
				
			case 2:
				
				do{
					
					registro_prest();
					
					cout<<"Desea registrar otro prestamo? 1. Si -- 2. No: ";
					cin>>centi;
				}while(centi!=2); break;
				
			case 3:
				
					
				op=menu_consul();
					
				switch(op){
					case 1: consul_cliente(); break;
					case 2: report_prest(); break;
				}
					
		}
		
	}while(opc!=4);
	
}

int menu(){
	
	int opc;
	
	cout<<endl;
	cout<<"Prestamos la solucion"<<endl;
	do{
		cout<<"1. Registro de clientes"<<endl;
		cout<<"2. Registro de prestamos"<<endl;
		cout<<"3. Consultas"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opc;
	}while(opc<1 || opc>4);
	
	return opc;
}

void archivos(){
	
	ofstream archivo("clientes.txt", ios::app | ios::binary);
	
	if(archivo.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		exit(0);
	}
	
	archivo.close();
	
	ofstream archivo2("prestamos.txt", ios::app | ios::binary);
	
	prestamo prest;
	
	if(archivo2.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		exit(0);
	}
	
	archivo2.close();
}

void registro_client(){
	
	long aux;
	char nombre[50];
	persona cliente;
	
	cout<<endl;
	cout<<"Registro de clientes"<<endl;
	
	cout<<"ID: ";
	cin>>aux;
	
	if(val_id(aux, nombre)){
		cout<<"Este ID ya esta registrada, vuelva al menu e intentelo nuevamente"<<endl;
		system("pause");
		return;
	}
	else{
		
		ofstream archivo("clientes.txt", ios::app | ios::binary);
		
		if(archivo.fail()){
			cout<<"El archivo no se pudo abrir correctamente"<<endl;
			system("pause");
			exit(0);
		}
		
		cliente.id=aux;
		
		cout<<"Nombre: ";
		cin.ignore(); cin.getline(cliente.nombre, 50);
		
		cout<<"Direccion: ";
		cin.getline(cliente.dir, 70);
		
		cout<<"Telefono: ";
		cin>>cliente.tele;
		
		archivo.write(reinterpret_cast<char*>(&cliente), sizeof(persona));
		archivo.close();
	}
	
	system("pause");
}

bool val_id(long aux, char* name){
	
	ifstream archivo("clientes.txt", ios::in | ios::binary);
	
	persona cliente;
	
	if(archivo.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		exit(0);
	}
	
	while(archivo.read(reinterpret_cast<char*>(&cliente), sizeof(persona))){
		
		if(aux==cliente.id){
			
			strcpy(name, cliente.nombre);
			archivo.close();
			return true;
		}
	}
	
	archivo.close();
	return false;
}

void registro_prest(){
	
	long aux;
	char nombre[50];
	prestamo prest;
	int ult;
	
	cout<<endl;
	cout<<"Registro de prestamos"<<endl;
	
	cout<<"ID del cliente: ";
	cin>>aux;
	
	if(val_id(aux, nombre)){
		
		ofstream archivo2 ("prestamos.txt", ios::app | ios::binary);
		
		if(archivo2.fail()){
			cout<<"El archivo no se pudo abrir correctamente"<<endl;
			system("pause");
			exit(0);
		}
		
		prest.id=aux;
		
		strcpy(prest.nombre, nombre);
		
		cout<<"Nombre: "<<nombre<<endl;
		
		ult=ultimo_prest();
		prest.num_prest=ult+1;
		cout<<"Numero del prestamo: "<<prest.num_prest<<endl;
		
		strftime(prest.fecha_hora,128,"%d/%m/%y %H:%M:%S", tlocal);
		cout<<"Fecha: "<<prest.fecha_hora <<endl;
		
		cout<<"Valor del prestamo: ";
		cin>>prest.vlr;
		
		if(prest.vlr<=2000000){
			prest.num_cout=1;
		}
		else if(prest.vlr<=5000000){
			prest.num_cout=3;
		}
		else{
			prest.num_cout=5;
		}
		
		if(prest.vlr<5000000){
			prest.interes=prest.vlr*0.12;
		}
		else{
			prest.interes=prest.vlr*0.10;
		}
		
		cout<<"Interes: "<<prest.interes<<endl;
		cout<<"Numero de cuotas: "<<prest.num_cout<<endl;
		cout<<"Valor de la cuota: "<<(prest.interes+prest.vlr)/prest.num_cout<<endl;
		
		prest.total=prest.interes+prest.vlr;
		cout<<"Total a pagar: "<<prest.total<<endl;
		
		archivo2.write(reinterpret_cast<char*>(&prest), sizeof(prestamo));
		archivo2.close();
		
	}
	else{
		cout<<"El ID digitado ya esta registrado, regrese al menu e intentelo nuevamente"<<endl;
		system("pause");
		return;
	}
	
}

int ultimo_prest(){
	
	ifstream archivo2("prestamos.txt", ios::in | ios::binary);
	
	prestamo prest;
	int max=0;
	
	if(archivo2.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		exit(0);
	}
	
	while(archivo2.read(reinterpret_cast<char*>(&prest), sizeof(prestamo))){
		
		if(prest.num_prest>max){
			max=prest.num_prest;
		}
	}
	
	archivo2.close();
	
	return max;
}

int menu_consul(){
	
	int opc;
	
	do{
		cout<<"1. Consulta un cliente"<<endl;
		cout<<"2. Reporte de prestamos"<<endl;
		cin>>opc;
	}while(opc<1 || opc>2);
	
	return opc;
	
}

void consul_cliente(){
	
	long aux;
	char nombre[50];
	prestamo prest;
	long deuda=0;
	
	cout<<endl;
	cout<<"Consulta de clientes"<<endl;
	cin>>aux;
	
	if(val_id(aux, nombre)){
		
		ifstream archivo2("prestamos.txt", ios::in | ios::binary);
		
		if(archivo2.fail()){
			cout<<"El archivo no se pudo abrir correctamente"<<endl;
			system("pause");
			exit(0);
		}
		
		while(archivo2.read(reinterpret_cast<char*>(&prest), sizeof(prestamo))){
			
			if(prest.id==aux){
				cout<<"Nombre: "<<prest.nombre<<endl;
				cout<<"Numero de prestamo: "<<prest.num_prest<<endl;
				cout<<"Fecha: "<<prest.fecha_hora<<endl;
				cout<<"Valor del prestamo: "<<prest.vlr<<endl;
				cout<<"Intereses: "<<prest.interes<<endl;
				cout<<"Total a cancelar: "<<prest.total<<endl;
				cout<<"Numero de cuotas: "<<prest.num_cout<<endl;
				
				deuda+=prest.total;
			}
		}
		
		cout<<"Deuda total del cliente: "<<deuda<<endl;
	}
	else{
		cout<<"El ID digitado ya esta registrado o no se encuentra en la base de datos, por favor vuelva al menu e intentelo nuevamente"<<endl;
		system("pause");
		return;
	}
}

void report_prest(){
	
	cout<<endl;
	cout<<"Reporte de prestamos"<<endl;
	
	ifstream archivo2("prestamos.txt", ios::in | ios::binary);
	
	prestamo prest;
	int x=0, i=0;
	long long prestado=0, intereses=0;
	
	if(archivo2.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		system("pause");
		exit(0);
	}
	
	while(archivo2.read(reinterpret_cast<char*>(&prest), sizeof(prestamo))){
		
		cout<<endl;
		cout<<"ID: "<<prest.id<<endl;
		cout<<"Nombre: "<<prest.nombre<<endl;
		cout<<"Numero del prestamo: "<<prest.num_prest<<endl;
		cout<<"Fecha: "<<prest.fecha_hora<<endl;
		cout<<"Valor del prestamo: "<<prest.vlr<<endl;
		cout<<"Intereses: "<<prest.interes<<endl;
		cout<<"Numero de cuotas: "<<prest.num_cout<<endl;
		
		if(prest.vlr>5000000){
			x++;
		}
		
		prestado+=prest.vlr;
		intereses+=prest.interes;
		i++;
	}
	
	archivo2.close();
	
	cout<<endl;
	cout<<"Porcentaje de clientes que solicitaron prestamos por encima de 5000000: "<<(100*x)/i<<"%"<<endl;
	cout<<"Total prestado por la empresa: "<<prestado<<endl;
	cout<<"Cuanto recibe la empresa por intereses: "<<intereses<<endl;
	
}
