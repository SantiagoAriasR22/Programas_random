#include <iostream>
using namespace std;

int main(){
	int N, M, opcion, i=0, j=0, v, c, sw=0, dato;
	float suma=0;
	
	do{
		cout<<"OPERACIONES MATRIZ"<<endl;
		cout<<"1. Visualizar toda la matriz"<<endl;
		cout<<"2. Sumar cada fila de la matriz"<<endl;
		cout<<"3. Sumar cada columna de la matriz"<<endl;
		cout<<"4. Sumar la diagonal principal"<<endl;
		cout<<"5. Sumar la diagonal inversa"<<endl;
		cout<<"6. Sumar una fila en especifico"<<endl;
		cout<<"7. Suma de una columna en especifico"<<endl;
		cout<<"8. La media de todos los valores de la matriz"<<endl;
		cout<<"9. Buscar un valor dado en la matriz"<<endl;
		cout<<"10. Salir"<<endl;
		cin>>opcion;
		
		
		if(opcion==10){
			exit(0);
		}
		else if(opcion==4 || opcion==5){
			do{
				cout<<"Para este procedimiento la matriz debe ser cuadrada"<<endl;
				cout<<"Ingrese el numero de filas de la matriz: ";
				cin>>N;
				cout<<"Ingrese el numero de columnas de la matriz: ";
				cin>>M;
			}while(N!=M);
		}
		else{
			cout<<"Ingrese el numero de filas de la matriz: ";
			cin>>N;
			cout<<"Ingrese el numero de columnas de la matriz: ";
			cin>>M;
		}
		
		int matriz[N][M];
		
		for(i=0; i<=N-1; i++){
			for(j=0; j<=M-1; j++){
				cout<<"Ingrese el dato que va a guardar en la posicion ["<<i<<"]["<<j<<"]: ";
				cin>>matriz[i][j];
			}
		}
		
		switch(opcion){
			case 1: 
			cout<<"VISUALIZACION DE LA MATRIZ"<<endl;
				for(i=0; i<=N-1; i++){
					for(j=0; j<=M-1; j++){
					cout<<"Posicion["<<i<<"]["<<j<<"]   "<<matriz[i][j]<<endl;
					}
				}
			break;
			
			case 2:
				cout<<"SUMA DE LAS FILAS"<<endl;
					for(i=0; i<=N-1; i++){
						suma=0;
						for(j=0; j<=M-1; j++){
							suma+=matriz[i][j];
						}
						cout<<"Fila #"<<i<<": "<<suma<<endl;
					}
			break;
			
			case 3:
				cout<<"SUMA DE LAS COLUMNAS"<<endl;
					for(j=0; j<=M-1; j++){
						suma=0;
						for(i=0; i<=N-1; i++){
							suma+=matriz[i][j];
						}
						cout<<"Columna #"<<j<<": "<<suma<<endl;
					}
			break;
			
			case 4:
				cout<<"SUMA DE LA DIAGONAL PRINCIPAL: "<<endl;
				suma=0;
					for(i=0; i<=N-1; i++){
						for(j=i; j<=i; j++){
							suma+=matriz[i][j];
						}
					}
					cout<<"Diagonal principal: "<<suma<<endl;
			break;
			
			case 5:
				cout<<"SUMA DE LA DIAGONAL INVERSA: "<<endl;
				suma=0;
					for(i=N-1; i>=0; i--){
						for(j=N-1-i; j==N-1-i; j++){
							suma+=matriz[i][j];
						}
					}
					cout<<"Diagonal inversa: "<<suma<<endl;
			break;
			
			case 6:
				do{
					cout<<"De que fila quiere obtener la suma?: ";
					cin>>v;
				}while(v<0 || v>N);
				
				suma=0;
				for(i=0; i<=N-1; i++){
					for(j=0; j<=M-1; j++){
						if(v==i){
							suma+=matriz[i][j];
						}
					}
				}
				cout<<"Sumatoria Fila "<<v<<": "<<suma<<endl;
			break;
				
			case 7:
				do{
					cout<<"De que columna quiere obtener la sumatoria?: ";
					cin>>c;
				}while(c<0 || c>M);
				 
				suma=0;
				for(j=0; j<=M-1; j++){
					for(i=0; i<=N-1; i++){
						if(c==j){
							suma+=matriz[i][j];
						}
					}
				}
				cout<<"Sumatoria de la fila #"<<c<<": "<<suma<<endl;
			break;
			
			case 8:
				suma=0;
				for(i=0; i<=N-1; i++){
					for(j=0; j<=M-1; j++){
						suma+=matriz[i][j];
					}
				}
				cout<<"Media de todos los valores de la matriz: "<<suma/(N*M)<<endl;
			break;
			
			case 9:
				
				cout<<"Ingrese el dato que quiere buscar dentro del arreglo: ";
				cin>>dato;
				sw=0;
				for(i=0; i<=N-1; i++){
					for(j=0; j<=M-1; j++){
						if(dato==matriz[i][j]){
							sw=1;
							cout<<"El dato "<<dato<<" se encuentra en la posicion: ["<<i<<"]["<<j<<"]"<<endl;
						}
					}
				}
				if(sw==0){
					cout<<"El dato no se encuentra dentro de la matriz"<<endl;
				}
			break;
		}
	}while(opcion!=10);
}
