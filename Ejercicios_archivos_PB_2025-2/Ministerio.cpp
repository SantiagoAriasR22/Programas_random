#include<iostream>
#include <fstream>
#include<string>
using namespace std;

struct estudiante{
	
	long id;
	char nombre[50];
	char programa[50];
	int semestre;
	int cant_asig;
	int asig_reprob=0;
	float promedio=0;
	int estrato;
};

void registro(struct estudiante vec[], int N, int &porc_reprob3, int &prom_sup, int &est4_prom35, int &est1_prom4);
void generar_txt(struct estudiante vec[], int N, int &porc_reprob3, int &prom_sup, int &est4_prom35, int &est1_prom4);
void imprimir_txt(struct estudiante vec[], int N, int &porc_reprob3, int &prom_sup, int &est4_prom35, int &est1_prom4);

int main(){
	
	int N=0, porc_reprob3=0, prom_sup=0, est4_prom35=0, est1_prom4=0, opc;
	
	cout<<"Ingrese la cantidad de estudiantes: ";
	cin>>N;
	
	estudiante vec[N];
	
	do{
		cout<<"1. Registrar datos"<<endl;
		cout<<"2. Crear archivo"<<endl;
		cout<<"3. Leer archivo"<<endl;
		cin>>opc;

		switch(opc){
			case 1:
				registro(vec, N, porc_reprob3, prom_sup, est4_prom35, est1_prom4); break;

			case 2:
				generar_txt(vec, N, porc_reprob3, prom_sup, est4_prom35, est1_prom4); break;

			case 3:
				imprimir_txt(vec, N, porc_reprob3, prom_sup, est4_prom35, est1_prom4); break;
		}
	}while(opc!=4);


	
}

void registro(struct estudiante vec[], int N, int &porc_reprob3, int &prom_sup, int &est4_prom35, int &est1_prom4){

	float n1, n2, n3, def, acum=0;
	int cont=0;
	porc_reprob3=0;
	prom_sup=0;
	est4_prom35=0;
	est1_prom4=0;
	
	cout<<"Registro de estudiantes"<<endl;
	for(int i=0; i<N; i++){

		cout<<"Estudiante #"<<i+1<<endl;
		
		cout<<"Identificacion: ";
		cin>>vec[i].id;
		
		cin.ignore();
		cout<<"Nombre: ";
		cin.getline(vec[i].nombre, 50);

		cout<<"Programa: ";
		cin.getline(vec[i].programa, 50);

		cout<<"Semestre: ";
		cin>>vec[i].semestre;

		cout<<"Estrato: ";
		cin>>vec[i].estrato;

		cout<<"Asignaturas matriculadas: ";
		cin>>vec[i].cant_asig;

		acum=0;
		cont=0;
		def=0;

		for(int j=0; j<vec[i].cant_asig; j++){

			cout<<"Asignatura #"<<j+1<<endl;

			cout<<"Nota primer corte (30%): ";
			cin>>n1;

			cout<<"Nota segundo corte (30%): ";
			cin>>n2;

			cout<<"Nota tercer corte (40%): ";
			cin>>n3;

			def=(n1*0.3)+(n2*0.3)+(n3*0.4);
			acum+=def;

			if(def<3.0){
				vec[i].asig_reprob++;
			}
		}

		if(vec[i].cant_asig>0){
			vec[i].promedio=acum/vec[i].cant_asig;
		}
		else{
			vec[i].promedio=0;
		}

		if(vec[i].asig_reprob>=3){
			porc_reprob3++;
		}

		if(vec[i].promedio>=4.5){
			prom_sup++;
		}

		if(vec[i].estrato==4 && vec[i].promedio<3.5){
			est4_prom35++;
		}

		if(vec[i].estrato==1 && vec[i].promedio>4){
			est1_prom4++;
		}
	}
}

void generar_txt(struct estudiante vec[], int N, int &porc_reprob3, int &prom_sup, int &est4_prom35, int &est1_prom4){

	ofstream minister("Informacion_matriculados.txt");

	if(minister.fail()){
		cout<<"El archivo no se abrio correctamente"<<endl;
		return;
	}

	for(int i=0; i<N; i++){
		minister<<vec[i].id<<";"<<vec[i].nombre<<";"<<vec[i].programa<<";"<<vec[i].semestre<<";"<<vec[i].cant_asig<<";"<<vec[i].asig_reprob<<";"<<vec[i].promedio<<";"<<vec[i].estrato<<endl;
	}

	minister<<"Total_estudiantes_matriculados:"<<N<<endl;
	minister<<"Porcentaje_estudiantes_reprobados_min_3_asignaturas:"<<((float)porc_reprob3*100/N)<<"%"<<endl;
	minister<<"Cantidad_estudiantes_prom_mayor_4,5:"<<prom_sup<<endl;
	minister<<"Cantidad_estudiantes_estrato_4_y_promedio_menor_3,5:"<<est4_prom35<<endl;
	minister<<"Cantidad_estudiantes_estrato_1_y_promedio_mayor_4,0:"<<est1_prom4<<endl;

	minister.close();
	cout<<"Se creo el archivo satisfactoriamente"<<endl;
	system("pause");

}

void imprimir_txt(struct estudiante vec[], int N, int &porc_reprob3, int &prom_sup, int &est4_prom35, int &est1_prom4){

	ifstream minister("Informacion_matriculados.txt");
	string linea;

	if(minister.fail()){
		cout<<"El archivo no se pudo abrir correctamente"<<endl;
		return;
	}

	while(getline(minister, linea)){
		cout<<linea<<endl;
	}

	minister.close();
	system("pause");
}
