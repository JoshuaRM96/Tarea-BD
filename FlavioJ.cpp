#include <iostream> 
#include <string.h> 

using namespace std; 

int Josefo(int n, int m); 

int main(){ 

    int Numero_Personas, Numero_Eliminacion; 

     
    cout<<" Por favor ingrese el numero de personas: "; 
    cin>>Numero_Personas; 

    cout<<"Por Favor ingrese el numero de saltos para eliminar: "; 
    cin>>Numero_Eliminacion; 

    cout<<"El sobreviviente es: "<<Josefo(Numero_Personas,Numero_Eliminacion)<<endl; 

    return (0); 

} 

 
int Josefo(int n, int m){ 

    char Lista[100000]; //Creo un array 
    int Cont1=-1, Cont2=0, Cont3=0;//Necesito 3 contadores inicializados en 0 
    int Sobreviviente=0;//Variable para retornar 
    bool Salir=false; //Boolean para salir del while 

    while ((Cont1<n) && (Salir==false)){ 

        Cont1++; 
        Cont2++; 
        if ((Cont2==m) || (Lista[Cont1]=='X')){ 
            if (Lista[Cont1]!='X'){ 
                Lista[Cont1]='X'; 

                Cont2=0; 

                Cont3++; 
            } 

            else Cont2--; 

        } 
        if (Cont1>n){ 

            Cont1=-1; 
        } 
        if (Cont3==(n-1)) Salir=true; 

    } 
    for (int i=0; i<n; i++){ 

        if (Lista[i] != 'X') Sobreviviente=i; 
    } 
    return (Sobreviviente); 
} 
