#include <iostream>
#include <iomanip>
using namespace std;

void cargar(float alt[], int N);
float alt_media(float alt[], int N);
void max_min(float alt[], int N, float &max, float &min);
void clasi(float alt[], int N, float media, float &mayor, float &menor);
void mostrar(float alt[], int N, float media, float max, float min, float mayor, float menor);
int main(){
	
	setlocale(LC_ALL, "spanish");
	
	int opcion, N;
	bool centi=false;
	float media, max=0, min=99999, mayor=0, menor=0;
	
	cout<<"Ingrese la cantidad de alumnos: ";
	cin>>N;
	
	float alt[N];
	
	system("pause");
	system("cls");
	
	do{
		do{
			cout<<"Menu"<<endl;
			cout<<"1. Registrar las estaturas"<<endl;
			cout<<"2. Estatura media"<<endl;
			cout<<"3. Estatura minima y maxima"<<endl;
			cout<<"4. Cantidad de alumnos con estatura mayor y menor que la media"<<endl;
			cout<<"5. Mostrar resultados"<<endl;
			cout<<"6. Salir"<<endl;
			cin>>opcion;
			system("pause");
			system("cls");
		}while(opcion<1 || opcion>6);
		
		switch(opcion){
			case 1: cargar(alt, N); 
			centi=true; 
			break;
		}
		
		if(opcion>=2 && opcion<=5 && !centi){
			cout<<"Para poder acceder a estas opciones necesitas primero registrar las estaturas"<<endl;
			system("pause");
			system("cls");
			continue;
		}
		
		switch(opcion){
			case 2: media=alt_media(alt, N);
			cout<<"La estatura media de los "<<N<<" estudiantes es: "<<fixed<<setprecision(2)<<media<<endl;
			system("pause");
			system("cls");
			break;
			
			case 3: max_min(alt, N, max, min);
			cout<<"La estatura maxima es: "<<max<<endl;
			cout<<"La estatura minima es: "<<min<<endl;
			system("pause");
			system("cls");
			break;
			
			case 4: clasi(alt, N, media, mayor, menor);
			cout<<"Cantidad de alumnos con estatura menor a la media: "<<menor<<endl;
			cout<<"Cantidad de alumnos con estatura mayor a la media: "<<mayor<<endl;
			system("pause");
			system("cls");
			break;
			
			case 5: mostrar(alt, N, media, max, min, mayor, menor);
		}
	}while(opcion!=6);
}

void cargar(float alt[], int N){
	
	for(int i=0; i<N; i++){
		cout<<"Ingrese la estatura del estudiante "<<i+1<<": ";
		cin>>alt[i];
	}
}

float alt_media(float alt[], int N){
	
	float suma=0;
	
	for(int i=0; i<N; i++){
		suma+=alt[i];
	}
	
	return suma/N;
}

void max_min(float alt[], int N, float &max, float &min){
	
	for(int i=0; i<N; i++){
		
		if(alt[i]>max){
			max=alt[i];
		}
		
		if(alt[i]<min){
			min=alt[i];
		}
	}
}

void clasi(float alt[], int N, float media, float &mayor, float &menor){
	
	for(int i=0; i<N; i++){
		
		if(alt[i]>media){
			mayor++;
		}
		
		if(alt[i]<media){
			menor++;
		}
	}
}

void mostrar(float alt[], int N, float media, float max, float min, float mayor, float menor){
	
	cout<<"Resultados"<<endl<<endl;
	
	cout<<"Estaturas registradas"<<endl;
	for(int i=0; i<N; i++){
		cout<<"["<<alt[i]<<"]";
	}
	cout<<endl;
	
	cout<<"Estatura media: "<<media<<endl;
	cout<<"Estatura maxima: "<<max<<endl;
	cout<<"Estatura minima: "<<min<<endl;
	cout<<"Cantidad de estudiantes por debajo de la media: "<<menor<<endl;
	cout<<"Cantidad de estudiantes por encima de la media: "<<mayor<<endl;
}


