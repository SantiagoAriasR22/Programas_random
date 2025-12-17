#include <iostream>
using namespace std;

int main(){
	
	setlocale(LC_ALL, "spanish");
	
	int vector[12];
	int inf, *i=vector, max=0, min=999999, j=0;
	float acum=0;
	
	for(; i<&vector[12]; i++, j++){
		cout<<"Ingrese la inflacion del mes #"<<j+1<<": ";
		cin>>inf;
		
		acum+=inf;
		
		if(inf>max){
			max=inf;
		}
		
		if(inf<min){
			min=inf;
		}
	}
	
	cout<<"Inflacion promedio durante el año: "<<acum/12<<"%"<<endl;
	cout<<"Inflacion mas alta: "<<max<<"%"<<endl;
	cout<<"Inflacion mas baja: "<<min<<"%"<<endl;
	
}
