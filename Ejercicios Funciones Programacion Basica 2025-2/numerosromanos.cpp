#include <iostream>
using namespace std;

int main(){
    int suma=0;
    string s;
    
    cout<<"Ingrese un numero en romano: "<<endl;
    cin>>s;
    
    for(int i=0; i<s.length(); i++){
        char caracter = s[i];
        char siguiente = (i+1<s.length()) ? s[i+1] : ' ';
		
        switch(caracter){
            case 'I': 
            if(siguiente=='V' || siguiente=='X'){
            	suma-=1;
			}
			else{
				suma+=1;
			}
			break;
            case 'V': suma+=5; break;
            case 'X': 
            if(siguiente=='L' || siguiente=='C'){
            	suma-=10;
			}
			else{
				suma+=10;
			}
			break;
            case 'L': suma+=50; break;
            case 'C': 
            if(siguiente=='D' || siguiente=='M'){
            	suma-=100;
			}
			else{
				suma+=100;
			}
			break;
            case 'D': suma+=500; break;
            case 'M': suma+=1000; break;

            default: cout<<caracter<<" no es valido"<<endl;
        }
    }
    
}
