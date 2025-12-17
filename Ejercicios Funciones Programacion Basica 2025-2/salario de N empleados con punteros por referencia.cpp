#include <iostream>
#include <conio.h>
using namespace std;

long salario(int *hrs_ordi, int *hrs_ext, int vlr_hrs);
void ausencias(int *hrs_ordi, int *hrs_ext);
int main(){
	
	int N, *hrs_ordi, *hrs_ext, *hrs_ause;
	int long vlr_hrs;
	
	cout<<"Ingrese la cantidad de empleados: ";
	cin>>N;
	
	int empleados[N][3];
	
	for(int i=0; i<N; i++){
		
		cout<<"Ingrese los datos del empleado #"<<i+1<<endl;
		cout<<"Numero de horas trabajadas: ";
		cin>>empleados[i][0];
		
		if(empleados[i][0] > 48){
			empleados[i][1] = empleados[i][0]-48;
			empleados[i][0]=48;
		}
		else{
			empleados[i][1]=0;
		}
		
		cout<<"Valor de la hora: ";
		cin>>empleados[i][2];
		
		cout<<"El salario a pagar sera de: $"<<salario(&empleados[i][0], &empleados[i][1], empleados[i][2])<<endl;
		getch();
	}
}

long salario(int *hrs_ordi, int *hrs_ext, int vlr_hrs){
	
	ausencias(hrs_ordi, hrs_ext);
	
	return (*hrs_ordi*vlr_hrs) + (*hrs_ext*vlr_hrs*1.75);
}

void ausencias(int *hrs_ordi, int *hrs_ext){
	
	int hrs_ause;
	
	cout<<"Ingrese las horas de ausencia: ";
	cin>>hrs_ause;
	
	if(*hrs_ext==0){
		*hrs_ordi-=hrs_ause;
	}
	else{
		if(*hrs_ext>=hrs_ause){
			*hrs_ext-=hrs_ause;
		}
		else{
			hrs_ause-=*hrs_ext;
			*hrs_ext=0;
			*hrs_ordi-=hrs_ause;
		}
	}
	
}

