#include <iostream>
#include <iomanip>
using namespace std;

void cargar(string nombres[], long codigos[], int N);
void registro(string nombres[], long codigos[], long ventas[], int N);
void reporte(string nombres[], long codigos[], long ventas[], int N);
void buscar(string nombres[], long codigos[], long ventas[], int N);

int main(){
	int N, opcion;
	
	cout<<"Registre el numero de trabajadores: ";
	cin>>N;
	
	system("cls");
	
	string nombres[N];
	long codigos[N];
	long ventas[N];
	
	do{
		cout<<"==GESTION DE STOCK DEL ALMACEN=="<<endl<<endl;
		cout<<"1. Cargar datos del vendedor"<<endl;
		cout<<"2. Registrar ventas"<<endl;
		cout<<"3. Reporte pago comision (Ordenado ascendentemente por la venta)"<<endl;
		cout<<"4. Consultar vendedor"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1: cargar(nombres, codigos, N); break;
			case 2: registro(nombres, codigos, ventas, N); break;
			case 3: reporte(nombres, codigos, ventas, N); break;
			case 4: buscar(nombres, codigos, ventas, N); break;
		}
	}while(opcion!=5);
}

void cargar(string nombres[], long codigos[], int N){
	
	int i=1;
	string *q=nombres;
	long *s=codigos;
	
	for(; s<&codigos[N]; q++, s++, i++){
		cout<<"Datos del vendedor #"<<i<<endl;
		cout<<"Ingrese el nombre: "<<endl;
		cin>>*q;
		
		cout<<"Ingrese el codigo: "<<endl;
		cin>>*s;
		
		cout<<endl;
	}
	
	system("pause");
	system("cls");
}

void registro(string nombres[], long codigos[], long ventas[], int N){
	
	int i=1, x;
	string *q=nombres;
	long *s=codigos, *l=ventas, aux=0;
	
	for(int k = 0; k < N; k++) {
        ventas[k] = 0;
    }
	
	for(; l<&ventas[N]; q++, s++, l++, i++){
		cout<<"Datos del vendedor #"<<i<<endl;
		cout<<"Codigo: "<<*s<<endl;
		
		cout<<"Ingrese el numero de ventas: ";
		cin>>x;
		
		aux=0;
		
		for(int j=0; j<x; j++){
			cout<<"Valor de la venta #"<<j+1<<endl;
			cin>>aux;
			*l+=aux;
		}
		
		cout<<"==REPORTE PROVISIONAL=="<<endl;
		cout<<"Nombre del vendedor: "<<*q<<endl;
		cout<<"Codigo: "<<*s<<endl;
		cout<<"Valor de las ventas: $"<<*l<<endl;
		cout<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void reporte(string nombres[], long codigos[], long ventas[], int N){
	string *q=nombres, aux;
	long *s=codigos, *l=ventas, *i=ventas, aux2, aux3;
	
	for(int j=0; j<N; j++){
		for(i=ventas, s=codigos, q=nombres; i<&ventas[N-1]; i++, s++, q++){
			if(*i>*(i+1)){
				aux2=*i;
				*i=*(i+1);
				*(i+1)=aux2;
				
				aux3=*s;
				*s=*(s+1);
				*(s+1)=aux3;
				
				aux=*q;
				*q=*(q+1);
				*(q+1)=aux;
			}
		}
	}
	
	l=ventas;
	q=nombres;
	s=codigos;
	
	for(; l<&ventas[N]; l++, q++, s++){
		cout<<setw(15)<<"Codigo"<<setw(15)<<"Vendedor"<<setw(20)<<"Valor por ventas"<<setw(20)<<"Comision"<<endl;
		cout<<setw(15)<<*s<<setw(15)<<*q<<setw(20)<<*l<<setw(20)<<*l*0.05<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void buscar(string nombres[], long codigos[], long ventas[], int N){
	
	string *q=nombres;
	long *s=codigos, *l=ventas, num=0;
	bool centi=false;
	
	cout<<"Ingrese el codigo del empleado a consultar: ";
	cin>>num;
	
	for(; s<&codigos[N]; s++, l++, q++){
		if(num==*s){
			cout<<setw(15)<<"Codigo"<<setw(15)<<"Vendedor"<<setw(20)<<"Valor por ventas"<<setw(20)<<"Comision"<<endl;
			cout<<setw(15)<<*s<<setw(15)<<*q<<setw(20)<<*l<<setw(20)<<*l*0.05<<endl<<endl;
			
			centi=true;
		}
	}
	
	if(centi==false){
		cout<<"No se encontro al empleado con el codigo digitado"<<endl;
	}
	
	system("pause");
	system("cls");
}


