#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int CantidadVendedores=0, Comision=0, Venta=0, VentaAcumulada=0, ComisionNomina=0, Comision5=0, Comision10=0, Comision15=0, VentaMinima=1000000000, VentaMaxima=0, i=1;
	float  PromedioVenta=0, Porcentaje5=0, Porcentaje10=0, Porcentaje15=0;
	
	cout<<"Ingrese la cantidad de vendedores de la empresa: ";
	cin>>CantidadVendedores;
	while(CantidadVendedores<0){
			cout<<"Valor invalido"<<endl<<"Ingrese un valor valido ";
			cin>>CantidadVendedores;
		}
		
	do{
		cout<<"Ingrese el total vendido por el empleado numero "<<i<<" : ";
		cin>>Venta;
		while(Venta<0){
			cout<<"Valor invalido"<<endl<<"Ingrese un valor valido ";
			cin>>Venta;
		}
		
		if(Venta<5000000){
			Comision=Venta*0.05;
			cout<<"La comision del empleado "<<i<<" sera de: "<<Comision<<endl;
			ComisionNomina+=Comision;
			Comision5++;
		}
		else if((Venta>=5000000) && (Venta<10000000)){
			Comision=Venta*0.10;
			cout<<"La comision del empleado "<<i<<" sera de: "<<Comision<<endl;
			ComisionNomina+=Comision;
			Comision10++;
		}
		else if(Venta>10000000){
			Comision=Venta*0.15;
			cout<<"La comision del empleado "<<i<<" sera de: "<<Comision<<endl;
			ComisionNomina+=Comision;
			Comision15++;
		}
		
		if(VentaMinima>Venta){
			VentaMinima=Venta;
		}
		if(VentaMaxima<Venta){
			VentaMaxima=Venta;
		}
		VentaAcumulada+=Venta;
		i++;
	}
	while(i<=CantidadVendedores);

	PromedioVenta=VentaAcumulada/CantidadVendedores;
	Porcentaje5=(Comision5*100)/CantidadVendedores;
	Porcentaje10=(Comision10*100)/CantidadVendedores;
	Porcentaje15=(Comision15*100)/CantidadVendedores;
	
	cout<<fixed<<setprecision(2);
	cout<<"Valor a cancelar por el total de comisiones: "<<ComisionNomina<<endl<<"Promedio de ventas: "<<PromedioVenta<<endl<<"Vendedores que obtuvieron una comision del 5%: "<<Comision5<<" y su porcentaje: "<<Porcentaje5<<endl<<"Vendedores que obtuvieron una comision del 10%: "<<Comision10<<" y su porcentaje: "<<Porcentaje10<<endl<<"Vendedores que obtuvieron una comision del 15%: "<<Comision15<<" y su porcentaje: "<<Porcentaje15<<endl<<"Venta maxima: "<<VentaMaxima<<endl<<"Venta minima: "<<VentaMinima;
}
