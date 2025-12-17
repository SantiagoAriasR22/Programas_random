#include <iostream>
using namespace std;

int main(){
	int grupos=0, estudiantes=0, reprobado=0, aprobado=0, i=1, e=1;
	float nota_acumulada=0, promedio=0, actividades=0, proyecto=0, parcial=0, mejor_nota=0, nota_final=0;
	
	cout<<"Ingrese la cantidad de grupos asignados al docente: ";
	cin>>grupos;
	
	do{
		cout<<"Ingrese la cantidad de estudiantes del grupo #"<<i<<": ";
		cin>>estudiantes;
		nota_acumulada=0;
		e=0;
		do{
			cout<<"Conteo de notas del grupo #"<<i<<": "<<endl;
			cout<<"Estudiante #"<<e<<endl;
			cout<<"Ingrese la nota de las actividades de seguimiento: ";
			cin>>actividades;
			cout<<"Ingrese la nota del proyecto: ";
			cin>>proyecto;
			cout<<"Ingrese la nota del parcial: ";
			cin>>parcial;
			
			nota_final=(actividades*0.20)+(proyecto*0.25)+(parcial*0.55);
			cout<<"La nota final es: "<<nota_final<<endl;
			
			if(nota_final<3.0){
				reprobado++;
			}
			else{
				aprobado++;
			}
			
			if(mejor_nota<nota_final){
				mejor_nota=nota_final;
			}
			
			nota_acumulada+=nota_final;
			e++;
		}while(e<=estudiantes);
		promedio=nota_acumulada/estudiantes;
		
		cout<<"Nota promedio del grupo #"<<i<<": "<<promedio<<endl;
		cout<<"Porcentaje de aprobados: "<<aprobado*100/estudiantes<<endl;
		cout<<"Porcentaje de reprobados: "<<reprobado*100/estudiantes<<endl;
		
		i++;
	}while(i<=grupos);
}
