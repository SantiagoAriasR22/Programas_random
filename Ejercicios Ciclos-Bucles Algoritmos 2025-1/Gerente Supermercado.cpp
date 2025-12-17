#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int edad=0, vlr_venta=0, cantidad_clientes=0, venta_maxima=0, venta_minima=1000000000, medio_pago;
	char sexo, salida;
	float venta_acumulada=0, venta_promedio=0, hombres=0, mujeres=0, menores=0, adultos=0, mayores=0, tarjec=0, tarjed=0, efectivo=0, nequi=0, otro=0;
	
	do{
		cout<<"Ingrese la edad del cliente: ";
		cin>>edad;
		while(edad<=0){
			cout<<"Ingrese una edad valida"<<endl; cout<<"Ingrese la edad del cliente: "; cin>>edad;
		}
		cout<<"Ingrese el sexo del cliente"<<endl<<"(F)emenino - (M)asculino: ";
		cin>>sexo;
		while(toupper(sexo)!='F' && toupper(sexo)!='M'){
			cout<<"Sexo incorrecto"<<endl; cout<<"Ingrese el sexo del cliente"<<endl<<"(F)emenino - (M)asculino: "; cin>>sexo;
		}
		cout<<"Ingrese el valor de la compra: ";
		cin>>vlr_venta;
		while(0>=vlr_venta){
			cout<<"Cantidad incorrecta"<<endl; cout<<"Ingrese el valor de la compra: "; cin>>vlr_venta;
		}
		cout<<"Escoja un metodo de pago: 1. Efectivo, 2. Tarjeta de Credito, 3. Tarjeta Debito, 4. Nequi, 5. Otro"<<endl;
		cin>>medio_pago;
		while(medio_pago<1 || medio_pago>5){
			cout<<"Metodo de pago incorrecto"<<endl; cout<<"Escoja un metodo de pago: 1. Efectivo, 2. Tarjeta de Credito, 3. Tarjeta Debito, 4. Nequi, 5. Otro"<<endl; cin>>medio_pago;
		}	
		
		venta_acumulada+=vlr_venta;
	
		if(venta_maxima<vlr_venta){
			venta_maxima=vlr_venta;
		}
		if(venta_minima>vlr_venta){
			venta_minima=vlr_venta;
		}
		
		if(toupper(sexo)=='F'){
			mujeres++;
		}
		else{
			hombres++;
		}
		
		if(edad<18){
			menores++;
		}
		else if(edad<60){
			adultos++;
		}
		else{
			mayores++;
		}
		
		switch(medio_pago){
			case 1: efectivo++; break;
			case 2: tarjec++; break;
			case 3: tarjed++; break;
			case 4: nequi++; break;
			case 5: otro++; break;
		}
		cantidad_clientes++;
		
		cout<<"Quiere ingresar la informacion de otro cliente?"<<endl<<"(S)i - (N)o"<<endl;
		cin>>salida;
		while(toupper(salida)!='S' && toupper(salida)!='N'){
			cout<<"Valor incorrecto"<<endl; cout<<"Quiere ingresar la informacion de otro cliente?"<<endl<<"(S)i - (N)o"<<endl; cin>>salida;
		}
	}while(toupper(salida)=='S');
	
	venta_promedio=venta_acumulada/cantidad_clientes;
	
	cout<<fixed<<setprecision(2);
	cout<<"Cantidad de clientes que ingresaron: "<<cantidad_clientes<<endl;
	cout<<"Ventas totales: $"<<venta_acumulada<<endl;
	cout<<"Venta promedio: $"<<venta_promedio<<endl;
	cout<<"Venta maxima: $"<<venta_maxima<<endl<<"Venta minima: $"<<venta_minima<<endl;
	cout<<"Cantidad de hombres: "<<hombres<<endl<<"Cantidad de mujeres: "<<mujeres<<endl<<"Cantidad de menores de edad: "<<menores<<endl<<"Cantidad de adultos: "<<adultos<<endl<<"Cantidad de adultos mayores: "<<mayores<<endl;
	cout<<"Porcentaje de clientes que pagaron con efectivo: "<<efectivo*100/cantidad_clientes<<"%"<<endl;
	cout<<"Porcentaje de clientes que pagaron con tarjeta de credito: "<<tarjec*100/cantidad_clientes<<"%"<<endl;
	cout<<"Porcentaje de clientes que pagaron con tarjeta de debito: "<<tarjed*100/cantidad_clientes<<"%"<<endl;
	cout<<"Porcentaje de clientes que pagaron con nequi: "<<nequi*100/cantidad_clientes<<"%"<<endl;
	cout<<"Porcentaje de clientes que pagaron con otro medio de pago: "<<otro*100/cantidad_clientes<<"%"<<endl;
}
