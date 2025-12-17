#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	long long N;
	long long i=0, j=0, debajo=0, encima=0;
	long suma=0, suma_empre=0, aux, aux3, maximo=0;
	string aux2, venmax; 
	long long prom=0;
	
	cout<<"Ingrese la cantidad de empleados: ";
	cin>>N;
	
	long long ventas[N][4];
	string nombres[N];
	long long boni[N];
	long long anual[N];
	
	for(i=0; i<=N-1; i++){
		cout<<"Ingrese el nombre del trabajador #"<<i+1<<": ";
		fflush(stdin); getline(cin, nombres[i]);
		suma=0;
		for(j=0; j<=4-1; j++){
			switch(j){
				case 0: 
					cout<<"Ventas del primer trimestre: "; break;
				
				case 1:
					cout<<"Ventas del segundo trimestre: "; break;
					
				case 2:
					cout<<"Ventas del tercer trimestre: "; break;
					
				case 3:
					cout<<"Ventas del cuarto trimestre: "; break;
					
			}
			cin>>ventas[i][j];
			suma+=ventas[i][j];
		}
		anual[i]=suma;
		suma_empre+=suma;
			if(anual[i]>maximo){
				maximo=anual[i];
				venmax=nombres[i];
			}
			if(anual[i]<5000000){
				debajo++;
				boni[i]=anual[i]*0.05;
			}
			if(anual[i]>10000000){
				encima++;
				boni[i]=anual[i]*0.10;
			}
			if(anual[i]>=5000000 && anual[i]<=10000000){
				boni[i]=anual[i]*0.08;
			}
	}
	
	suma=0;
	for(i=0; i<=N-1; i++){
		suma+=boni[i];
	}
	prom=suma/N;
	
	cout<<endl;
	cout<<setw(30)<<"REPORTE DE PAGO BONIFICACION"<<endl<<endl;
	cout<<left<<setw(15)<<"Vendedor"<<setw(15)<<"T1"<<setw(15)<<"T2"<<setw(15)<<"T3"<<setw(15)<<"T4"<<setw(15)<<"Anual"<<setw(15)<<"Bonificacion"<<endl;
	for(i=0; i<=N-1; i++){
		cout<<left<<setw(15)<<nombres[i];
		for(j=0; j<=4-1; j++){
			switch(j){
				case 0: 
					//cout<<fixed<<setprecision(0);
					cout<<setw(15)<<ventas[i][j];
					break;
				
				case 1:
					//cout<<fixed<<setprecision(0);
					cout<<setw(15)<<ventas[i][j];
					break;
					
				case 2:
					//cout<<fixed<<setprecision(0);
					cout<<setw(15)<<ventas[i][j];
					break;
					
				case 3:
					//cout<<fixed<<setprecision(0);
					cout<<setw(15)<<ventas[i][j];
					break;
			}
		}
		cout<<setw(15)<<anual[i];
		cout<<setw(15)<<boni[i]<<endl;
	}
	cout<<endl;
	cout<<fixed<<setprecision(0);
	cout<<"Venta total de la empresa: "<<suma_empre<<endl;
	cout<<"Bonificacion promedio: "<<prom<<endl;
	cout<<"Porcentaje de vendedores con ventas anuales por debajo de 5000000: "<<(debajo*100)/N<<"%"<<endl;
	cout<<"Porcentaje de vendedores con ventas anuales por encima de 10000000: "<<(encima*100)/N<<"%"<<endl;
	cout<<"Vendedor con mayor volumen de ventas: "<<venmax<<"     Valor: "<<maximo<<endl;
	
}
