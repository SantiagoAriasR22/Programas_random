#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int NumeroEstudiantes=0, EstudiantesAprob=0, EstudiantesReprob=0, i=1;
	float PorcentajeAprob=0, PorcentajeReprob=0, NotaDefinitiva=0, ActividadSeguimiento=0, Proyecto=0, Examen=0, PromedioGrupal=0, NotaAcumulada=0;
	
	cout<<"Ingrese el numero de estudiantes: ";
	cin>>NumeroEstudiantes;
	
	do{
		cout<<"Estudiante numero "<<i<<endl;
		cout<<"Ingrese la nota total de las actividades de seguimiento: ";
		cin>>ActividadSeguimiento;
		cout<<"Ingrese la nota del proyecto: ";
		cin>>Proyecto;
		cout<<"Ingrese la nota del examen: ";
		cin>>Examen;
		NotaDefinitiva=(ActividadSeguimiento*0.20)+(Proyecto*0.25)+(Examen*0.55);
		cout<<"La definitiva del estudiante "<<i<<" es: "<<NotaDefinitiva<<endl;
		
		if(NotaDefinitiva>=3.0){
			EstudiantesAprob++;
		}
		else{
			EstudiantesReprob++;
		}
		NotaAcumulada+=NotaDefinitiva;
		i++;
	}
	while(i<=NumeroEstudiantes);
	PromedioGrupal=NotaAcumulada/NumeroEstudiantes;
	PorcentajeAprob=(EstudiantesAprob*100)/NumeroEstudiantes;
	PorcentajeReprob=(EstudiantesReprob*100)/NumeroEstudiantes;
	
	cout<<"La nota promedio del grupo es de: "<<PromedioGrupal<<endl<<"El porcentaje de estudiantes aprobados es de: "<<PorcentajeAprob<<"%"<<endl<<"Porcentaje de estudiantes reprobados es de: "<<PorcentajeReprob<<"%"<<endl;
}
