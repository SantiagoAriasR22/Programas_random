#include <iostream>
#include <string.h>
using namespace std;

struct libro{
	long numed;
	int publi;
};

struct revista{
	char nombre[50];
};

struct tipo{
	libro li;
	revista rev;
};

struct biblio{
	long num_ref;
	char tit[50];
	char nombreau[50];
	char edit[50];
	int clas;
	tipo clase;
};

int menu(){
	
	int op;
	
	do{
		cout<<"1. Registrar texto"<<endl;
		cout<<"2. Consultar"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>op;
		
	}while(op<1 || op>3);	
	
	return op;
}

void registro(struct biblio vector[], int N);
void consulta(struct biblio vector[], int N);
void aut(struct biblio vector[], int N);

int main(){
	
	int opc, N;
	setlocale(LC_ALL, "spanish");
	
	cout<<"Ingrese la cantidad de libros y revistas: ";
	cin>>N;
	
	biblio vector[N];
	
	do{
		opc=menu();
		
		switch(opc){
			case 1: registro(vector, N); break;
			case 2:	consulta(vector, N); break;
		}
		
	}while(opc!=3);
}

void registro(struct biblio vector[], int N){
	
	int aux;
	
	cout<<"Registro"<<endl;
	for(int i=0; i<N; i++){
		cout<<endl;
		cout<<"Libro #"<<i+1<<endl;
		
		cout<<"Numero de referencia: ";
		cin>>vector[i].num_ref;
		
		cout<<"Titulo: ";
		fflush(stdin); gets(vector[i].tit);
		
		cout<<"Nombre del autor: ";
		fflush(stdin); gets(vector[i].nombreau);
		
		cout<<"Editorial: ";
		fflush(stdin); gets(vector[i].edit);
		
		cout<<"Clase de publicacion 1. Libro -- 2. Revista: ";
		cin>>aux;
		vector[i].clas=aux;
		
		switch(aux){
			case 1:
				cout<<"Numero de edicion: ";
				cin>>vector[i].clase.li.numed;
				
				cout<<"Año de publicacion: ";
				cin>>vector[i].clase.li.publi;
				
			break;
			
			case 2:
				cout<<"Nombre de la revista: ";
				fflush(stdin); gets(vector[i].clase.rev.nombre);
				
			break;
		}
	}
}

void consulta(struct biblio vector[], int N){
	
	int opc;
	
	do{
		cout<<"1. Clase de publicacion"<<endl;
		cout<<"2. Nombre del autor"<<endl;
		cout<<"3. Nombre de la revista"<<endl;
		cin>>opc;
	}while(opc<1 || opc>3);
	
	switch(opc){
		case 1: break;
		case 2: aut(vector, N);
	}
}

void aut(struct biblio vector[], int N){
	
	char aux[50];
	
	cout<<"Ingrese el nombre del autor que quiere buscar: ";
	fflush(stdin); gets(aux);
	
	for(int i=0; i<N; i++){
		if(strcmp(aux, vector[i].nombreau)==0){
			cout<<"Nombre del autor: "<<vector[i].nombreau<<endl;
			switch(vector[i].clas){
				case 1:
					cout<<"Clase de publicacion: Libro"<<endl;
					cout<<"Titulo: "<<vector[i].tit<<endl;
					cout<<"Numero de edicion: "<<vector[i].clase.li.numed<<endl;
					cout<<"Año de publicacion: "<<vector[i].clase.li.publi<<endl;
					cout<<"Editorial: "<<vector[i].edit<<endl;
					cout<<"Numero de referencia: "<<vector[i].num_ref<<endl;
					
				break;
				
				case 2:
					cout<<"Clase de publicacion: Revista"<<endl;
					cout<<"Titulo: "<<vector[i].tit<<endl;
					cout<<"Nombre de la revista: "<<vector[i].clase.rev.nombre<<endl;
					cout<<"Editorial: "<<vector[i].edit<<endl;
					cout<<"Numero de referencia: "<<vector[i].num_ref<<endl;
			
					
				break;
			}
		}
	}
}


