/*
 *@file grafo.cpp
 */

#include "grafo.h"
#include <iostream>
#include<stdlib.h>
#define Max 100

using namespace std;

int Matriz[Max][Max];

class node {
public:


    int ady;
    int peso;
    node *siguiente;
    node(int v,int p, node *sig = NULL)
    {
        ady = v;
        peso=p;
        siguiente = sig;
    }
};


struct nodo {

public:

    int vertice;
    node *puntero;
    nodo *siguiente;
    nodo(int v, nodo *sig = NULL,node *punt=NULL)
    {
        vertice = v;
        siguiente = sig;
        puntero=punt;
    }

    class lista;
};

typedef nodo *nodoPtr;

class lista {
public:

    nodoPtr primero;

    lista() {
        primero =  NULL;
    }


    void crearVertice(int v);
    bool listaVacia();
    nodoPtr buscar( int v);
    bool listaExiste(int i,int f);
    void crearArco(int i,int f,int peso);
    void crearMatriz();
    void mostrarMatriz();
    int cantidadVertices();
    int existeArco(int i,int f);
    bool buscarAdy(nodoPtr aux,int ad);

};
/*
 *@brief funcion que crea un arco
 */

void lista::crearArco(int i,int f,int peso){
    nodoPtr pos;
    pos=primero;
    if(listaExiste(i,f)){
        while(pos!=NULL){
            if(i == pos->vertice ){

                if(pos->puntero==NULL){
                    pos->puntero=new node(f,peso);
                }
                else {
                    node *temp=pos->puntero;
                    while(temp->siguiente!=NULL){
                        temp=temp->siguiente;
                    }
                    temp->siguiente=new node(f,peso);
                    temp=NULL;
                    delete temp;
                }
            }
            pos=pos->siguiente;
        }
    }



}

bool lista::listaExiste(int i,int f){
    if(buscar(i)!=NULL&&buscar(f)!=NULL){
        return true;
    }
    else{
        return false;
    }

}


/*
 *@brief Funcion que crea un vertice
 */


void lista::crearVertice(int v){
    nodoPtr  anterior;
    if(listaVacia())
    {
        primero = new nodo(v, primero);
    }else { if(v<=primero->vertice){
            primero =new nodo(v, primero) ;
        }else{

            anterior = primero;
            while((anterior->siguiente) && (anterior->siguiente->vertice<=v)){
                anterior = anterior->siguiente; }


            anterior->siguiente = new nodo(v, anterior->siguiente);
        }


    }
}
/*
 *@brief Funcion que borra todo el contenido de la lista
 */
bool lista::listaVacia(){
    return primero == NULL;

}

int lista::cantidadVertices(){
    nodoPtr nodo=primero;
    int i=0;
    while(nodo!=NULL){
        i++;
        nodo=nodo->siguiente;
    }
    return i;
}

/*
 *@brief Funcion que determina si hay un arco entre dos vertices
 */

int lista::existeArco(int i,int f){
    nodoPtr nodo;
    int a=1;
    nodo=buscar(i);
    if(nodo){
        if(buscarAdy(nodo,f)){
            return a;
        }else{
            return a=0;
        }
    }
}
/*
 *@brief Funcion que busca las adyacencias
 */
bool lista::buscarAdy(nodoPtr aux,int ad){
    node *temp=aux->puntero;
    bool a;
    while(temp){
        if(ad==temp->ady){
            return a=true;}
        temp=temp->siguiente;
    }
    return a=false;
}

/*
 *@brief Funcion que busca un valor determinado
 */

nodoPtr lista::buscar(int valor){
    nodoPtr indice,n=NULL;
    indice=primero;
    while(indice!=NULL){
        if(valor == indice->vertice ){
            return indice;
        }
        indice=indice->siguiente;
    }
    cout<<"\n\n\tEL VALOR BUSCADO NO ESTA EN EL GRAFO";
    return n;
}
/*
 *@brief Funcion que crea una matriz para ser mostrada
 */
void lista::crearMatriz(){
    nodoPtr nodo=primero,nodotemp;
    int i,j;
    int cant=cantidadVertices();
    for(i=0;i<cant;i++){
        nodotemp=primero;
        for(j=0;j<cant;j++){
            Matriz[i][j]=existeArco(nodo->vertice,nodotemp->vertice);
            nodotemp=nodotemp->siguiente;
        }
        nodo=nodo->siguiente;
    }
    delete nodo;
    delete nodotemp;
}
/*
 *@brief Funcion para imprimir una matriz
 */

void lista::mostrarMatriz(){
    int i,j,cant;
    nodoPtr nodo=primero;
    cant=cantidadVertices();
    cout<<"   ";

    for(i=0;i<cant;i++){ //ciclo for.
        cout<<"\t"<<nodo->vertice<<" ";
        nodo=nodo->siguiente;
    }
    nodo=primero;


    for( i=0;i<cant;i++){ //ciclo for.

        cout<<nodo->vertice;
        for(j=0;j<cant;j++){
            cout<<"\t"<<Matriz[i][j]<<" ";
        }
        nodo=nodo->siguiente;
        cout<<"\n";
    }
}

