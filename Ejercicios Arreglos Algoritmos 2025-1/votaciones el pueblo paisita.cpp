#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int N, votos, porc, i=0, j=0, c=0, maximo;
	float suma=0, suma2=0, aux, aux3;
	string aux2;
	
	cout<<"Ingrese la cantidad de cantidatos: ";
	cin>>N;
	
	string candi[N];
	float matriz[N][5];
	
	for(i=0; i<=N-1; i++){
		cout<<"Ingrese el nombre del candidato #"<<i+1<<": ";
		fflush(stdin); getline(cin, candi[i]);
	}
	
	cout<<endl<<"VOTACION"<<endl;
	
	for(j=0; j<=5-1; j++){
		cout<<"Zona #"<<j+1<<endl;
		for(i=0; i<=N-1; i++){
			cout<<"Ingrese los votos obtenidos por el candidato "<<candi[i]<<": ";
			cin>>matriz[i][j];
			suma2+=matriz[i][j];
		}
	}
	
	float porcentaje[N];
	float sumatoria[N];
	
	c=0;
	for(i=0; i<=N-1; i++){
		suma=0;
		for(j=0; j<=5-1; j++){
			suma+=matriz[i][j];
		}
		sumatoria[c]=suma;
		porcentaje[c]=(suma*100)/suma2;
		c++;
	}
	
	maximo=porcentaje[0];
	for(i=0; i<=N-1; i++){
		for(j=0; j<=N-2; j++){
			if(porcentaje[j]<porcentaje[j+1]){
				aux=porcentaje[j];
				porcentaje[j]=porcentaje[j+1];
				porcentaje[j+1]=aux;
				aux2=candi[j];
				candi[j]=candi[j+1];
				candi[j+1]=aux2;
				aux3=sumatoria[j];
				sumatoria[j]=sumatoria[j+1];
				sumatoria[j+1]=aux3;
			}
		}
	}
	system("cls");
	
	cout<<"ELECCIONES 2016 - PUEBLO PAISITA"<<endl;
	cout<<left<<setw(15)<<"CANDIDATO"<<setw(12)<<"VOTOS"<<setw(12)<<"PORCENTAJE"<<endl;
	for(i=0; i<=N-1; i++){
		cout<<fixed<<setprecision(2);
		cout<<left<<setw(15)<<candi[i]<<setw(12)<<sumatoria[i]<<setw(12)<<porcentaje[i]<<"%"<<endl;
	}	
	
	if(porcentaje[0]>porcentaje[1]){
		cout<<"Ganador: "<<candi[0];
	}
	if(porcentaje[0]==porcentaje[1]){
		cout<<"Empate: "<<candi[0]<<" y "<<candi[1];
	}
}
