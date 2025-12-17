#include<iostream>
#include<fstream>
using namespace std;

struct estd{
	long id;
	char nombre[50];
	float n1;
	float n2;
	float n3;
};

void txt();
void registro();
bool valid(long aux);
void mostrar();

int main(){
	
	txt();
	
	int centi, opc;
	
	do{
		cout<<"Menu"<<endl;
		cout<<"1. Registro"<<endl;
		cout<<"2. Mostrar reporte"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>opc;
		
		switch(opc){
			case 1:
				do{
					registro();
		
					cout<<"Desea registrar otro estudiante? 1. Si -- 2. No: ";
					cin>>centi;
		
				}while(centi!=2);
				break;
				
				case 2: mostrar();
		}
		
	}while(opc!=3);
	
	
}

void txt(){
	
	ofstream archivo1 ("estudiantes.txt", ios::app | ios::binary);
	
	if(archivo1.fail()){
		system("pause");
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		exit(0);
	}
	
	archivo1.close();
}

void registro(){
	
	static int i=0;
	long aux;
	estd estudiante;
	
	ofstream archivo1 ("estudiantes.txt", ios::app | ios::binary);
	
	if(archivo1.fail()){
		system("pause");
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		exit(0);
	}
	cout<<"REGISTRO"<<endl;
	cout<<"Estudiante #"<<++i<<endl;
	cout<<"Ingrese la ID del estudiante: ";
	cin>>aux;
	
	if(valid(aux)){
		cout<<"Este ID ya se encuentre registrado, por favor vuelva al menu y vuelva a intentarlo"<<endl;
		system("pause");
		return;
	}
	else{
		
		estudiante.id=aux;
		
		cout<<"Nombre: ";
		cin.ignore(); cin.getline(estudiante.nombre, 50);
		
		cout<<"Primer corte: ";
		cin>>estudiante.n1;
		
		cout<<"Segundo corte: ";
		cin>>estudiante.n2;
		
		cout<<"Segundo corte: ";
		cin>>estudiante.n3;
		
		archivo1.write(reinterpret_cast<char*>(&estudiante), sizeof(estd));
		archivo1.close();
	}
	
	archivo1.close();
}

bool valid(long aux){
	
	estd estudiante;
	
	ifstream archivo1 ("estudiantes.txt", ios::in | ios::binary);
	
	if(archivo1.fail()){
		system("pause");
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		exit(0);
	}
	
	while(archivo1.read(reinterpret_cast<char*>(&estudiante), sizeof(estd))){
		
		if(aux==estudiante.id){
			archivo1.close();
			return true;
		}
	}
	
	archivo1.close();
	
	return false;
}

void mostrar(){
	
	cout<<"REPORTE DE NOTAS"<<endl;
	ifstream archivo1 ("estudiantes.txt", ios::in | ios::binary);
	
	int i=0, x=0, j=0;
	estd estudiante;
	float def, acum=0, max=0;
	
	while(archivo1.read(reinterpret_cast<char*>(&estudiante), sizeof(estd))){
		
		cout<<"Estudiante #"<<++i<<endl;
		cout<<"ID: "<<estudiante.id<<endl;
		cout<<"Nombre: "<<estudiante.nombre<<endl;
		cout<<"Notas del semestre: "<<endl;
		cout<<"Primer corte: "<<estudiante.n1<<endl;
		cout<<"Segundo corte: "<<estudiante.n2<<endl;
		cout<<"Tercer corte: "<<estudiante.n3<<endl;
		def=(estudiante.n1*0.3)+(estudiante.n2*0.3)+(estudiante.n3*0.4);
		acum+=def;
		cout<<"Definitiva: "<<def<<endl;
		
		if(def<3.0){
			j++;
		}
		
		if(max<def){
			max=def;
		}
		
		x++;
	}
	
	cout<<"Promedio del grupo: "<<acum/x<<endl;
	cout<<"Mejor nota: "<<max<<endl;
	cout<<"Cantidad de estudiantes que reprobaron: "<<j<<endl;
}
