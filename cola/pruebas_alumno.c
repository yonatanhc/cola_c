#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



void prueba_crear_cola() {

	printf("%s\n","============PRUEBA CREAR COLA======================0" );
	printf("\n");

	cola_t* cola = cola_crear();

	print_test("cola_creada correctamente", cola != NULL);

	print_test("cola recien creada esta vacia", cola_esta_vacia(cola));

	print_test("desencolar en una cola vacia es NULL", cola_desencolar(cola) == NULL);

	print_test("cola_ver_primero en una cola vacia es NULL", cola_ver_primero(cola) == NULL);

	cola_destruir(cola,NULL);
}

int* generar_dato( int valor){

	int* dato=malloc(sizeof(int));

	*dato = valor;

	return dato;
}

void pruebas_de_Volumen() {

	printf("\n");
	printf("%s\n","================= PRUEBA DE VOLUMEN ==============" );

	cola_t* cola = cola_crear();

	printf("%s\n","...............PRUEBA DE ENCOLAR VOLUMEN.............." );

	bool ok = true;

	for (int i = 1; i <= 10000; ++i){
		
		int* dato = generar_dato(i);

		ok &= cola_encolar(cola,dato);

	}

	print_test("se encolaron correctamente todos los datos", ok == true);

	printf("%s\n","...............PRUEBA DESENCOLAR VOLUMEN............." );

	bool ok_desencolar = true;

	ok = true;

	for (int i = 1; i <= 10000 ; ++i){
		
		int* aux = cola_desencolar(cola);
		
		if (*aux != i){
			
			ok_desencolar = false;
		}

		ok &= ok_desencolar;

		free(aux);
	}

	print_test("todos los datos se desencolan correctamente", ok == true);

	print_test("despues de desencolar la cola esta vacia", cola_esta_vacia(cola));

	cola_destruir(cola,NULL);
}

void pruebas_generales() {

	printf("\n");
	printf("%s\n","=======PRUEBAS DE ENCOLAR Y DESENCOLAR AL MISMO TIEMPO ==========" );

	cola_t* cola = cola_crear();

	print_test("la cola se creo correctamente", cola != NULL);
	print_test("la cola recien creada esta vacia", cola_esta_vacia(cola));

	int aux1 = 10;
	int* dato1 = &aux1;
	print_test("el primer dato se encolo correctamente", cola_encolar(cola,dato1));
	print_test("el primer elemento es el correcto", cola_ver_primero(cola) == dato1);
	print_test("al desencolar el valor es dato1", cola_desencolar(cola) == dato1);

	int aux2 = 20;
	int* dato2 = &aux2;
	print_test("el primer dato se encolo correctamente", cola_encolar(cola,dato2));
	print_test("el primer elemento es el correcto", cola_ver_primero(cola) == dato2);
	print_test("al desencolar el valor es dato1", cola_desencolar(cola) == dato2);

	int aux3 = 30;
	int* dato3 = &aux3;
	print_test("el primer dato se encolo correctamente", cola_encolar(cola,dato3));
	print_test("el primer elemento es el correcto", cola_ver_primero(cola) == dato3);
	print_test("al desencolar el valor es dato1", cola_desencolar(cola) == dato3);

	print_test("la cola se encuentra vacio", cola_esta_vacia(cola));
	print_test("desencolar una cola vacia es NULL", cola_desencolar(cola) == NULL);
	print_test("cola_ver_primero en una cola vacia es NULL", cola_ver_primero(cola) == NULL);

	cola_destruir(cola,NULL);

}

void pruebas_destruir() {

	printf("\n");
	printf("%s\n","=============PRUEBA DESTRUIR==============" );

	cola_t* cola = cola_crear();


	bool ok = true;
	for (int i = 1; i <= 100; ++i){
		
		int* dato = generar_dato(i);

		ok &= cola_encolar(cola,dato);
	}

	print_test("todos los datos se encolaron correctamente", ok == true);

	printf("%s\n","los datos almacenados en memoria dinamica se eliminaron correctamente , fijarce valgrind" );
	cola_destruir(cola,free);
}

void pruebas_cola_alumno() {

	prueba_crear_cola();
	pruebas_de_Volumen();
	pruebas_generales();
	pruebas_destruir();
}




	
	
