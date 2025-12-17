#include <iostream>
using namespace std;

int main(){
	int favorita=0, nuevo=0, estreno=0, super_estrenos=0, dias_atraso=0, cant_clientes=0, categoria, precio, atraso, recargo=0, suma_recargo=0, total_pagar, sumatoria_total=0, mayor=0, menor=1000000000;
	string nombre;
	char salida;
	setlocale(LC_ALL, "spanish");
	
	do{
		system("cls");
		cout<<"Bienvenido"<<endl;
		cout<<"Ingrese su nombre: ";
		fflush(stdin); getline(cin, nombre);
		cout<<"Escoja que categoria de pelicula quiere llevar: "<<endl<<"1. Favoritos $2500  --  Recargo por dia de atraso $500"<<endl;
		cout<<"2. Nuevos $3000  --  Recargo por dia de atraso $750"<<endl<<"3. Estrenos $3500  --  Recargo por dia de atraso $1000"<<endl<<"4. Super estrenos $4000  --  Recargo por dia de atraso $1500"<<endl;
		cin>>categoria; while(categoria<1 || categoria>4){
			cout<<"Por favor ingrese una categoria valida"<<endl<<endl;
			cout<<"Escoja que categoria de pelicula quiere llevar: "<<endl<<"1. Favoritos $2500  --  Recargo por dia de atraso $500"<<endl;
			cout<<"2. Nuevos $3000  --  Recargo por dia de atraso $750"<<endl<<"3. Estrenos $3500  --  Recargo por dia de atraso $1000"<<endl<<"4. Super estrenos $4000  --  Recargo por dia de atraso $1500"<<endl;
			cin>>categoria;
		}
		
		switch(categoria){
			case 1: favorita++;
			precio=2500; 
			atraso=500; break;
			case 2: nuevo++;
			precio=3000; 
			atraso=750; break;
			case 3: estreno++;
			precio=3500; 
			atraso=1000; break;
			case 4: super_estrenos++;
			precio=4000; 
			atraso=1500; break;
		}
		
		cout<<"¿Cuando dias de atraso tiene al momento de entregar la pelicula?: ";
		cin>>dias_atraso;
		
		recargo=atraso*dias_atraso;
		suma_recargo+=recargo;
		
		if(mayor<dias_atraso){
			mayor=dias_atraso;
		}
		if(menor>dias_atraso){
			menor=dias_atraso;
		}
		total_pagar=precio+recargo;
		sumatoria_total+=total_pagar;
		
		cant_clientes++;
		
		cout<<"El total a pagar sera de: $"<<total_pagar<<endl;
		cout<<"¿Quiere ingresar lso datos de otro cliente?: [S]i - [N]o"<<endl;
		cin>>salida;
	}while(toupper(salida)=='S');
	system("cls");
	
	cout<<"Numero de clientes: "<<cant_clientes<<endl<<endl;
	cout<<"Cantidad de clientes que alquilaron por categoria: "<<endl;
	cout<<"Favoritas: "<<favorita<<endl<<"Nuevas: "<<nuevo<<endl<<"Estrenos: "<<estreno<<endl<<"Super estrenos: "<<super_estrenos<<endl<<endl;
	cout<<"Total recaudado: $"<<sumatoria_total<<endl;
	cout<<"Porcentaje de clientes que solicitaron peliculas de super estreno: "<<super_estrenos*100/cant_clientes<<"%"<<endl;
	cout<<"Cantidad de dias de mayor atraso: "<<mayor<<endl<<"Cantidad de dias de menor atraso: "<<menor<<endl;
	cout<<"Total recaudado por dias de atraso en la entrega de peliculas: "<<suma_recargo<<endl;
}
