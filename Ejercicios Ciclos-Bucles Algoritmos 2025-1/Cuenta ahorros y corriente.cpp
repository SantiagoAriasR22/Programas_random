#include <iostream>
using namespace std;

int main(){
	int codigo=0, tipo_cuenta=0, tipo_actualizacion=0, cant_clientes=0, cant_ahorro=0, cant_corriente=0, apor_mayor=0, retiro=0, aporte_ahorros=0, retiro_corriente=0;
	float  prom_retiro=0, monto_aporte=0, monto=0, retiro_acum=0;
	char salida;
	string cuenta, actualizacion;
	
	do{
		do{
			cout<<"Ingrese el codigo del cliente: ";
			cin>>codigo;
		}while(0>=codigo);
		
		cout<<"Escoja el tipo de cuenta del cliente: "<<endl<<"1. Ahorros"<<endl<<"2. Corriente"<<endl;
		cin>>tipo_cuenta;
		switch(tipo_cuenta){
			case 1: cuenta="Ahorros";
					cant_ahorro++;
					break;
			case 2: cuenta="Corriente";
					cant_corriente++;
					break;
			default: while(tipo_cuenta<1 || tipo_cuenta>2){
				cout<<"Ingrese un tipo de cuenta valida"<<endl;
				cout<<"Escoja el tipo de cuenta del cliente: "<<endl<<"1. Ahorros"<<endl<<"2. Corriente"<<endl;
				cin>>tipo_cuenta;
			}
			break;
		}
		cout<<"Escoja el tipo de actualizacion: "<<endl<<"1. Aporte"<<endl<<"2. Retiro"<<endl;
		cin>>tipo_actualizacion;
	
		cout<<"Ingrese el monto de la transaccion: ";
		cin>>monto;
		switch(tipo_actualizacion){
			case 1: monto_aporte+=monto; break;
			case 2: retiro_acum+=monto; 
			retiro++; break;
		}
		
		if(tipo_actualizacion==1){
			if(monto>apor_mayor){
				apor_mayor=monto;
			}
		}
		if(tipo_actualizacion==1 && tipo_cuenta==1){
			aporte_ahorros++;
		}
		if(tipo_actualizacion==2 && tipo_cuenta==2){
			retiro_corriente++;
		}
		cant_clientes++;
		
		cout<<"Quiere ingresar los datos de otro cliente?: "<<endl<<"[S]i"<<endl<<"[N]o"<<endl;
		cin>>salida;
	}while(toupper(salida)=='S');
	
	prom_retiro=retiro_acum/retiro;
	
	cout<<"Cantidad de clientes atendidos: "<<cant_clientes<<endl;
	cout<<"Porcentaje de clientes con cuenta de ahorro: "<<cant_ahorro*100/cant_clientes<<"%"<<endl;	
	cout<<"Porcentaje de clientes con cuenta corriente: "<<cant_corriente*100/cant_clientes<<"%"<<endl;
	cout<<"Monto total del aporte: "<<monto_aporte<<endl;
	cout<<"Cantidad de clientes que hicieron aporte en cuenta de ahorro: "<<aporte_ahorros<<endl;
	cout<<"Cantidad de clientes que hicieron retiro en cuenta corriente: "<<retiro_corriente<<endl;
	cout<<"Promedio retiro: "<<prom_retiro<<endl;
	cout<<"Aporte de mayor valor: "<<apor_mayor<<endl;
}
