#include <iostream>
#include<iomanip>
using namespace std;

int main(){
	int N, suma=0, i=0, j=0, aux2, min=999999999;
	string aux;
	
	cout<<"Cual es el numero de participantes?: ";
	cin>>N;
	
	int parti[N][3];
	int general[N];
	string nombres[N];
	int categoria[3];
	
	for(i=0; i<=N-1; i++){
			cout<<"Datos participante #"<<i+1<<endl;
			suma=0;
			cout<<"Nombre: ";
			fflush(stdin); getline(cin, nombres[i]);
		for(j=0; j<=3-1; j++){
			if(j==0){
				cout<<"Puntos por inteligencia: ";
				cin>>parti[i][j];
				suma+=parti[i][j];
			}
			if(j==1){
				cout<<"Puntos por cultura general: ";
				cin>>parti[i][j];
				suma+=parti[i][j];
			}
			if(j==2){
				cout<<"Puntos por belleza: ";
				cin>>parti[i][j];
				suma+=parti[i][j];
			}
		}
		general[i]=suma;
	}
	
	for(j=0; j<=3-1; j++){
		suma=0;
		for(i=0; i<=N-1; i++){
			suma+=parti[i][j];
		}
		categoria[j]=suma;
		if(categoria[j]<min){
			min=categoria[j];
		}
	}
	
	for(i=0; i<=N-1; i++){
		for(j=0; j<=N-2; j++){
			if(general[j]<general[j+1]){
				aux2=general[j];
				general[j]=general[j+1];
				general[j+1]=aux2;
				aux=nombres[j];
				nombres[j]=nombres[j+1],
				nombres[j+1]=aux;
			}
		}
	}
	cout<<endl;
	cout<<"Nombre"<<setw(15)<<"Inteligencia"<<setw(15)<<"Cultura"<<setw(15)<<"Belleza"<<setw(15)<<"Puntaje total"<<endl;
	for(i=0; i<=N-1; i++){
		cout<<nombres[i]<<setw(15);
		for(j=0; j<=3-1; j++){
			if(j==0){
				cout<<parti[i][j]<<setw(15);
			}
			if(j==1){
				cout<<parti[i][j]<<setw(15);
			}
			if(j==2){
				cout<<parti[i][j]<<setw(15);
				cout<<general[i]<<endl;
			}
		}
	}
	
	cout<<"Categoria"<<setw(10);
	for(i=0; i<=N-1; i++){
		cout<<categoria[i]<<setw(15);
	}
	cout<<endl<<endl;
	cout<<"Concursante con mayor puntaje: "<<nombres[0]<<"    "<<general[0]<<endl;
	cout<<"Puntaje acumulado en la categoria inteligencia: "<<categoria[0]<<endl;
	cout<<"Puntaje acumulado en la categoria cultura: "<<categoria[1]<<endl;
	cout<<"Puntaje acumulado en la categoria belleza: "<<categoria[2]<<endl;
	
	if((categoria[0]<categoria[1])&&(categoria[0]<categoria[2])){
		cout<<"La categoria con el menor puntaje acumulado es inteligencia con: "<<categoria[0]<<endl;
	}
	if((categoria[1]<categoria[0])&&(categoria[1])<categoria[2]){
		cout<<"La categoria con el menor puntaje acumulado es cultura con: "<<categoria[1]<<endl;
	}
	if((categoria[2]<categoria[0])&&(categoria[2]<categoria[1])){
		cout<<"La categoria con el menor puntaje acumulado es belleza con: "<<categoria[2]<<endl;
	}	
}
