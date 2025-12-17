#include <iostream>
using namespace std;

int main(){
	int N=7, M=4, i=0, j=0, dia=0, semana=0, dia_s=0, semana_s=0;
	float sumatoria_s=0, max=0, min=99999999;
	float mes[N][M];
	
	for(i=0; i<=M-1; i++){
		cout<<"Semana: "<<i<<endl;
		for(j=0; j<=N-1; j++){
			cout<<"Dia: "<<j<<endl;
			cout<<"Registre la temperatura media de hoy: ";
			cin>>mes[j][i];
			
			if(mes[j][i] > max){
				max=mes[j][i];
				dia_s=[j];
				semana_s=[i];
			}
			if(mes[j][i] < min){
				min=mes[j][i];
				dia=[j];
				semana=[i];
			}
		}
	}
	cout<<endl;
	cout<<"Temperatura media por semana"<<endl;
	for(i=0; i<=M-1; i++){
		sumatoria_s=0;
		for(j=0; j<=N-1; j++){
			sumatoria_s+=mes[j][i];
		}
		cout<<"Semana #"<<i<<": "<<sumatoria_s/N<<endl<<endl;
	}
	
	cout<<"Temperatura minima, registrada el dia "<<dia<<"de la semana "<<semana<<": "<<min<<endl;
	cout<<"Temperatura maxima, registrada el dia "<<dia_s<<" de la semana "<<semana_s<<": "max<<endl;
}

	
