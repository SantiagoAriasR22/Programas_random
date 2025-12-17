#include <iostream>
using namespace std;

float cal_iva(int precio, int iva);

int main(){
	int precio=0, iva=0;
	float costo=0;
	
	cout<<"Ingrese el precio del producto: ";
	cin>>precio;
	
	cout<<"Ingrese el porcentaje de iva a aplicar: ";
	cin>>iva;
	
	costo=cal_iva(precio, iva);
	
	cout<<endl<<endl;
	cout<<"----------FACTURA----------"<<endl;
	cout<<"Coste del producto (sin iva): "<<precio<<endl;
	cout<<"Coste total (con iva): "<<costo<<endl;
}

float cal_iva(int precio, int iva){
	float porc_iva=0, cost_iva=0, total=0; 
	
	porc_iva=iva*0.01;
	cost_iva=precio*porc_iva;
	total=precio+cost_iva;
	
	return total;
}

