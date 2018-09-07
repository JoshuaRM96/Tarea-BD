//librerias a incluir
#include<iostream>
using namespace std;

//definiciones
struct Libro{
    char *tit;
    int ADP;
    struct Libro* next;
    struct Libro* previous;
};
//prototipos del programa
Libro* C_libro();
void I_libro(Libro** ,Libro**);
void imprimir(Libro* );
Libro* B_libro(Libro* );
void M_libro(Libro* );


int main(){
    Libro* lista=NULL;
    Libro* cola=NULL;
	return 0;
}

Libro* C_libro(){
    int anio=0;
    char *tit=new char[64];
    cout<<"Ingresa el libro: "<<endl;
     cin>>tit;
    cout<<"Ingresa su Año de publicacion: "<<endl;
    cin>>anio;
    Libro* nuevo_libro=new Libro();
    nuevo_libro->tit=tit;
    nuevo_libro->ADP=anio;
    return nuevo_libro;
}

void I_libro(Libro** lista,Libro** cola){
    Libro* nuevo_libro=crear_libro();
    if(*lista==NULL){
        *lista=nuevo_libro;
        nuevo_libro->next=NULL;
        nuevo_libro->previous=NULL;
        *cola=nuevo_libro;
    } 
    else{
        Libro* aux=*cola;
        aux->next=nuevo_libro;
        nuevo_libro->previous=aux;
        nuevo_libro->next=NULL;
        *cola=nuevo_libro;
    }
}

void imprimir(Libro* lista){
    Libro* aux=lista;
    if(lista==NULL){
        cout<<"Lista vacia"<<endl;
    }
    while(aux!=NULL){
        cout<<aux->tit<<endl;
        cout<<aux->ADP<<endl;
        aux=aux->next;
    }
}



Libro* B_libro(Libro* lista){
    if(lista==NULL){
        cout<<"Error no hay contenido"<<endl;
    }
    else{
        char *tit=new char[64];
        int anio=0;
        cout<<"que libro necesitas"<<endl;
        cin>>tit;
        cout<<"En que año fue publicado"<<endl;
        cin>>anio;
        Libro* aux=lista;
        while(aux!=NULL && aux->tit!=tit && aux->ADP!=anio){
            aux=aux->next;
        }
        return aux;
    }
}

void M_libro(Libro* lista){
    Libro* modificado=buscar_libro(lista);
    cout<<"Ingresa nuevo titulo "<<endl;
    cin>>modificado->tit;
    cout<<"Ingresa el año de publicacion"<<endl;
    cin>>modificado->ADP;
}
