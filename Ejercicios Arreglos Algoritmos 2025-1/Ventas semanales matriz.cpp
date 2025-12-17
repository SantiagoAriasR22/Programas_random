#include <iostream>
using namespace std;

int main(){
	int N, sumatoria_s=0, sumatoria_e=0, total_p, M=5, j=0, i=0, mayor=0;
	float promedio_s=0, promedio_e=0;
	setlocale(LC_ALL, "spanish");
	
	do{
		cout<<"Ingrese la cantidad de empleados: ";
		cin>>N;
	}while(N<0);
	
	int ventas[N][M];
	string dias[]= {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
	
	for(i=0; i<=M-1; i++){
		cout<<"Dia: "<<dias[i]<<endl;
		for(j=0; j<=N-1; j++){
			cout<<"Cuantas ventas realizo el vendedor #"<<j<<": ";
			cin>>ventas[i][j];
			sumatoria_e+=ventas[i][j];
		}
	}
	promedio_e=sumatoria_e/M;
	
	cout<<"REPORTE DE PRODUCTOS VENDIDOS"<<endl;
	for(i=0; i<=M-1; i++){
		cout<<"Dia: "<<dias[i]<<endl;
		for(j=0; j<=N-1; j++){
			cout<<"Vendedor #"<<j<<"        Productos vendidos: "<<ventas[i][j]<<endl;
		}
	}
	cout<<endl;
	cout<<"TOTAL Y PROMEDIO SEMANAL POR VENDEDOR"<<endl;
	for(i=0; i<=N-1; i++){
		sumatoria_s=0;
		promedio_s=0;
		
		for(j=0; j<=M-1; j++){
			sumatoria_s+=ventas[j][i];
		}
		promedio_s=sumatoria_s/M;
		cout<<"Vendedor #"<<i<<": ";
		cout<<"Ventas totales: "<<sumatoria_s<<endl;
		cout<<"Venta promedio semanalmente: "<<promedio_s<<endl;
		cout<<"Desempeño del vendedor:";
		if(promedio_s>=50){
			cout<<" Excelente"<<endl;
		}
		else if(promedio_s>=30 && promedio_s<50){
			cout<<" Bueno"<<endl;
		}
		else if(promedio_s>=10 && promedio_s<30){
			cout<<" Regular"<<endl;
		}
		else{
			cout<<" Deficiente"<<endl;
		}
		if(sumatoria_s > promedio_e){
			mayor++;
		}
	}
	cout<<endl;
	cout<<"REPORTE EMPRESARIAL"<<endl;
	cout<<"Total vendido: "<<sumatoria_e<<endl;
	cout<<"Promedio de ventas: "<<promedio_e<<endl;
	cout<<"Porcentaje de vendedores que vendieron por encima del promedio: "<<(mayor*100)/N;
	
}
