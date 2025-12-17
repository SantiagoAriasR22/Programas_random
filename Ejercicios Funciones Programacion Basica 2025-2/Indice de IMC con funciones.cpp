/*
I. Se solicita desarrollar un programa que permita interpretar el grado de obesidad  para un grupo de N personas. 
Para interpretar el IMC e indicar la condición física  se debe tener en cuenta los rangos de la siguiente tabla:
a)     menos de 18,5 bajo peso
b)     entre 18,5 y 24,9 peso normal
c)     entre 25 y 29,9 sobrepeso
d)     mayor a 30 obesidad
Diseñar un programa  que muestre el nombre, peso, altura, IMC
IMC = p/a^2

Se requiere implementar las siguientes función que permita:
Leer y validar que el peso ingresado es correcto para ser retornado al main (Formato función no recibe retorna)
Leer y validar que la altura ingresada es correcta para ser retornada al main  

(Formato función no recibe retorna)
Calcular el IMC esta función debe recibir el peso y la altura y retornar el IMC al main. 

(Formato función recibe y retorna)
Potencia esta función debe recibir como parámetro la altura y el exponente y retornar a la función calcular IMC para completar el proceso 

 (Formato función recibe y retorna)
Acumular IMC el cual se debe retornar cuando se sume el IMC de la última persona evaluada. 

 (Formato función recibe y retorna)
Interpretar el grado de obesidad debe recibir el IMC y mostrar la condición física de la persona 

 (Formato función recibe y  No retorna)
*/


#include <iostream>
using namespace std;

float leer_peso();
float leer_alt();
float cal_imc(float peso, float alt);
float potencia(float base, int expo);
float acumular_imc(float imc, int i, int N);
void interpretar(float imc);

int main(){
	int i=0, N=0;
	float peso=0, alt=0, imc=0, acum_imc=0;
	string nombre;
	
	cout<<"A cuantas personas va a registrar?: ";
	cin>>N;
	
	for(i=0; i<N; i++){
		cout<<"Ingrese el nombre: ";
		fflush(stdin); getline(cin, nombre);
		
		peso=leer_peso();
		alt=leer_alt();
		imc=cal_imc(peso, alt);
		
		cout<<"DATOS DEL CLIENTE"<<endl<<endl;
		cout<<"Nombre: "<<nombre<<endl;
		cout<<"Peso [kg]: "<<peso<<endl;
		cout<<"Estatura [m]: "<<alt<<endl;
		cout<<"IMC: "<<imc<<endl;
		cout<<"Grado de IMC: ";
		interpretar(imc);
		cout<<endl<<endl;
		
		if(i+1==N){
			acum_imc=acumular_imc(imc, i, N);
			cout<<"IMC promedio: "<<acum_imc/N<<endl;
		}
		else{
			acumular_imc(imc, i, N);
		}
	}
}

float leer_peso(){
	int x=0;
	float p=0;
	
	do{
		if(x>=1){
			cout<<"Ingrese un peso correcto"<<endl;
		}
		cout<<"Ingrese el peso [kg]: ";
		cin>>p;
		x++;
	}while(p<=0 || p>500);
	
	return p;
}

float leer_alt(){
	int x=0;
	float a=0;
	
	do{
		if(x>=1){
			cout<<"Ingrese una altura correcta"<<endl;
		}
		cout<<"Ingrese la altura [m]: ";
		cin>>a;
		x++;
	}while(a<=0 || a>2.70);
	
	return a;
}

float cal_imc(float peso, float alt){
	return peso/potencia(alt, 2);
}

float potencia(float alt, int expo){
	int x=0;
	float po=1;
	
	for(x=0; x<expo; x++){
		po*=alt;
	}
	
	return po;
}

float acumular_imc(float imc, int i, int N){
	static float imc_suma=0;
	
	imc_suma+=imc;
	
	if(i+1==N){
		return imc_suma;
	}
}

void interpretar(float imc){
	if(imc<18.5){
		cout<<"Bajo peso"<<endl;
	}
	else if(imc<25){
		cout<<"Peso normal"<<endl;
	}
	else if(imc<30){
		cout<<"Sobrepeso"<<endl;
	}
	else{
		cout<<"Obesidad"<<endl;
	}
}
