#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "spanish");
	string meses[12]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	string nombre;
	char centinela;
	float depo_anual=0, depo_total=0, interes_anual=0, interes_total=0, inversion=0;
	int depo=0, years=0, mes=0;
	
	do{
		cout<<"Ingrese su nombre: ";
		fflush(stdin); getline(cin, nombre);
		cout<<"Ingrese la cantidad de años que va a durar la inversion: ";
		cin>>years;
		
		for(int i=1; i<=years; i++){
			mes=0;
			interes_anual=0;
			depo_anual=0;
			cout<<"Año "<<i<<endl;
			do{
				cout<<endl;
				cout<<meses[mes]<<endl<<endl;
				cout<<"Ingrese el valor que va a depositar: ";
				cin>>depo;
				depo_anual+=depo;
				mes++;
			}while(mes<12);
			interes_anual=depo_anual*0.1;
			cout<<"Total ahorrado durante el año: "<<depo_anual<<endl;
			cout<<"Interes generado en el año: "<<interes_anual<<endl;
			depo_total+=depo_anual;
			interes_total+=interes_anual;
			cout<<endl<<endl;
		}
		cout<<"Periodo de inversion finalizado"<<endl;
		cout<<"Monto total depositado: "<<depo_total<<endl;
		cout<<"Interes total generado: "<<interes_total<<endl;
		cout<<"Valor final de la inversion: "<<depo_total+interes_total<<endl<<endl;
		
		cout<<"Quieres ingresar los datos de otro cliente?:   Si (S) -- No (N) ";
		cin>>centinela;
	}while(toupper(centinela)!='N');
}
