#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct empleado{
    long id;
    char nombre[50];
    int hrs_trab;
    int hrs_ext;
    int vlr_hrs;
    long sal_ord;
    long sal_ext;
    long desc_salud;
    long desc_pension;
    long neto;
    char eps[50];
    char pension[50];
};

void registro(struct empleado vec[], int N);
void calculo(struct empleado vec[], int N);
void menu_consultas(struct empleado vec[], int N);
void consulta_empleado(struct empleado vec[], int N);
void info_banco(struct empleado vec[], int N);
void generar_bancotxt(struct empleado vec[], int N);
void imprimir_bancotxt(struct empleado vec[], int N);
void info_pila(struct empleado vec[], int N);
void generar_pilatxt(struct empleado vec[], int N);
void imprimir_pilatxt(struct empleado vec[], int N);

int main(){

    int N, centi;

    cout<<"Ingrese la cantidad de empleados: ";
    cin>>N;

    empleado vec[N];

    do{
        cout<<"1. Ingresar datos de la nomina"<<endl;
        cout<<"2. Calcular nomina"<<endl;
        cout<<"3. Consultas"<<endl;
        cout<<"4. Informacion banco"<<endl;
        cout<<"5. Pago pila"<<endl;
        cout<<"6. Salir"<<endl;
        cin>>centi;

        switch(centi){
            case 1: registro(vec, N); break;
            case 2: calculo(vec, N); break;
            case 3: menu_consultas(vec, N); break;
            case 4: info_banco(vec, N); break;
            case 5: info_pila(vec, N); break;
        }

    }while(centi!=6);

}

void registro(struct empleado vec[], int N){

    cout<<"Registro datos nomina"<<endl;
    for(int i=0; i<N; i++){
        cout<<"Empleado "<<i+1<<endl;

        cout<<"ID: ";
        cin>>vec[i].id;

        cout<<"Nombre: ";
        cin.ignore(); cin.getline(vec[i].nombre, 50);

        cout<<"Horas trabajadas: ";
        cin>>vec[i].hrs_trab;

        cout<<"Valor de la hora: ";
        cin>>vec[i].vlr_hrs;

        cout<<"Eps afiliada: ";
        cin.ignore(); cin.getline(vec[i].eps, 50);

        cout<<"Empresa administradora de fondos pensionales afiliada: ";
        cin.getline(vec[i].pension, 50);

        cout<<"Se registraron los datos correctamente"<<endl;
        system("pause");
        system("cls");
    }
}

void calculo(struct empleado vec[], int N){

    cout<<endl;
    cout<<"Desprendible de pago"<<endl;

    for(int i=0; i<N; i++){

        cout<<endl;
        cout<<"Nombre: "<<vec[i].nombre<<endl;
        cout<<"Horas trabajadas: "<<vec[i].hrs_trab<<endl;
        
        if(vec[i].hrs_trab>40){
            vec[i].hrs_ext=vec[i].hrs_trab-40;
            vec[i].hrs_trab=40;
        }
        else vec[i].hrs_ext=0;

        cout<<"Horas extras trabajadas: "<<vec[i].hrs_ext<<endl; 
        cout<<"Valor de la hora: "<<vec[i].vlr_hrs<<endl;
        vec[i].sal_ord=vec[i].vlr_hrs*vec[i].hrs_trab;
        cout<<"Salario ordinario: "<<vec[i].sal_ord<<endl;
        vec[i].sal_ext=vec[i].hrs_ext*(vec[i].vlr_hrs*2);
        cout<<"Salario horas extras: "<<vec[i].sal_ext<<endl;
        vec[i].neto=vec[i].sal_ord+vec[i].sal_ext;
        vec[i].desc_pension=vec[i].neto*0.04;
        cout<<"Descuento por pension: "<<vec[i].desc_pension<<endl;
        vec[i].desc_salud=vec[i].neto*0.04;
        cout<<"Descuento por salud: "<<vec[i].desc_salud<<endl;
        vec[i].neto=vec[i].neto-(vec[i].desc_pension+vec[i].desc_salud);
        cout<<"Neto a pagar: "<<vec[i].neto<<endl;

        system("pause");
    }
}

void menu_consultas(struct empleado vec[], int N){

    int opc;

    cout<<"Menu de consultas"<<endl;
    cout<<"1. Consulta un empleado"<<endl;
    cout<<"2. Reporte nomina"<<endl;
    cout<<"3. Reporte horas extra"<<endl;
    cin>>opc;

    switch(opc){
        case 1: consulta_empleado(vec, N);
    }
}

void consulta_empleado(struct empleado vec[], int N){

    long id;
    bool centi=false;

    cout<<"Ingrese la ID: ";
    cin>>id;

    for(int i=0; i<N; i++){
        if(id==vec[i].id){
            centi=true;

            cout<<"Nombre: "<<vec[i].nombre<<endl;
            cout<<"ID: "<<vec[i].id<<endl;
            cout<<"Horas ordinarias trabajadas: "<<vec[i].hrs_trab<<endl;
            cout<<"Horas extras: "<<vec[i].hrs_ext<<endl;
            cout<<"Valor de la hora: "<<vec[i].vlr_hrs<<endl;
            cout<<"Salario ordinario: "<<vec[i].sal_ord<<endl;
            cout<<"Salario horas extras: "<<vec[i].sal_ext<<endl;
            cout<<"Descuento por salud: "<<vec[i].desc_salud<<endl;
            cout<<"Descuento por pension: "<<vec[i].desc_pension<<endl;
            cout<<"Eps afialiada: "<<vec[i].eps<<endl;
            cout<<"Empresa administradora de fondos pensionales afiliada: "<<vec[i].pension<<endl;
        }
    }

    if(!centi){
        cout<<"No se encontro el empleado"<<endl;
    }
}

void info_banco(struct empleado vec[], int N){

    int opc;

    cout<<"1. Generar archivo de texto"<<endl;
    cout<<"2. Imprimir archivo de texto"<<endl;
    cin>>opc;

    switch(opc){
        case 1: generar_bancotxt(vec, N); break;
        case 2: imprimir_bancotxt(vec, N); break;
    }
}

void generar_bancotxt(struct empleado vec[], int N){

    ofstream banco("pagobanco.txt");

    if(banco.fail()){
        cout<<"El archivo no se pudo abrir correctamente"<<endl;
        return;
    }

    for(int i=0; i<N; i++){
        banco<<vec[i].nombre<<";"<<vec[i].id<<";"<<vec[i].neto<<endl;
    }

    banco.close();
    cout<<"Archivo de texto generado con exito"<<endl;

}

void imprimir_bancotxt(struct empleado vec[], int N){

    string linea;

    ifstream banco("pagobanco.txt");

    if(banco.fail()){
        cout<<"No fue posible abrir el archivo de texto"<<endl;
        return;
    }

    
    while(getline(banco, linea)){
        cout<<linea<<endl;
    }

    banco.close();
    system("pause");
}

void info_pila(struct empleado vec[], int N){

    int opc;

    cout<<"1. Generar archivo de texto"<<endl;
    cout<<"2. Imprimir archivo"<<endl;
    cin>>opc;

    switch(opc){
        case 1: generar_pilatxt(vec, N); break;
        case 2: imprimir_pilatxt(vec, N); break;
    }
}

void generar_pilatxt(struct empleado vec[], int N){

    ofstream pila("Pila.txt");

    if(pila.fail()){
        cout<<"No se logro abrir el archivo con exito"<<endl;
        return;
    }

    for(int i=0; i<N; i++){
        pila<<vec[i].id<<";"<<vec[i].nombre<<";"<<vec[i].desc_salud<<";"<<vec[i].desc_pension<<";"<<vec[i].eps<<";"<<vec[i].pension<<endl;
    }

    pila.close();
    cout<<"Se genero el archivo de pila con exito"<<endl;
    system("pause");
}

void imprimir_pilatxt(struct empleado vec[], int N){

    ifstream pila("pila.txt");
    string linea;

    if(pila.fail()){
        cout<<"No se logro abrir el archivo correctamente"<<endl;
        return;
    }

    while(getline(pila, linea)){
        cout<<linea<<endl;
    }

    pila.close();
    system("pause");

}