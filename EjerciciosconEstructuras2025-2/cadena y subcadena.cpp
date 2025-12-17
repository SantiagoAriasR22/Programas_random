#include<iostream>
#include<string.h>
using namespace std;

int cadenas(char cad1[], char cad2[]){
	
	char aux[50];
	int si=0, j=0;
	
	for(int i=0; cad1[i]!='\0'; i++){
		if(isblank(cad1[i])==true){
			aux[j]='\0';
			if(strcmp(aux, cad2)==0){
				si++;
			}
			j=0;
		}
		else{
			aux[j]=cad1[i];
			j++;
		}
	}
	
	if(j>0){
        aux[j] = '\0';
        if(strcmp(aux, cad2) == 0){
            si++;
        }
    }
	
	return si;
} 

int main(){
	
	char cad1[50];
	char cad2[50];
	int num;
	
	cout<<"Ingrese una cadena: ";
	fflush(stdin); gets(cad1);
	
	cout<<"Ingrese una subcadena: ";
	fflush(stdin); gets(cad2);
	
	num=cadenas(cad1, cad2);
	
	cout<<"La cantidad de veces que la subcadena esta en la cadena es: "<<num<<endl;
}
