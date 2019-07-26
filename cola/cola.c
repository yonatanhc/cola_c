#include "cola.h"
#include<stdlib.h>


typedef struct nodo{

	void* dato;

	struct nodo* siguiente;

}nodo_t;

nodo_t* crear_nodo(void* valor){

	nodo_t* nodo = malloc(sizeof(nodo_t));

	if ( nodo == NULL) return NULL;

	nodo->dato = valor;

	nodo->siguiente = NULL;

	return nodo;
}

struct cola {

    nodo_t* primero;

    nodo_t* ultimo;
    
};

cola_t* cola_crear(void) {

	cola_t* cola = malloc(sizeof(cola_t));

	if (cola == NULL) return NULL;

	cola->primero = NULL;

	cola->ultimo = NULL;

	return cola;
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)){
		
	while(!cola_esta_vacia(cola)){

		void* aux = cola_desencolar(cola);

		if (destruir_dato != NULL){
				
			destruir_dato(aux);
		}

	}
	free(cola);
}

bool cola_esta_vacia(const cola_t *cola) {

	return cola->primero == NULL ;
}

bool cola_encolar(cola_t *cola, void* valor) {

	nodo_t* nodo = crear_nodo(valor);

	if (nodo == NULL) return false;

	if (cola->primero == NULL) cola->primero = nodo;
		
	else cola->ultimo->siguiente = nodo;

	cola->ultimo = nodo;

	return true;
}

void* cola_ver_primero(const cola_t *cola) {

	if (cola_esta_vacia(cola)) return NULL;

	return cola->primero->dato;
}

void* cola_desencolar(cola_t *cola) {

	if (cola_esta_vacia(cola)) return NULL;

	void* aux = cola->primero->dato;

	nodo_t* nodo_desencolar = cola->primero;

	cola->primero = nodo_desencolar->siguiente;

	if (cola->primero == NULL) cola->ultimo = NULL;

	free(nodo_desencolar);

	return aux;
}