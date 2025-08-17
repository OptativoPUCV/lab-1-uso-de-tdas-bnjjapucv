#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for (int k = 1; k < 11; k++){
      int *lista = (int*) malloc(sizeof(int));
      if (lista == NULL){
         return NULL;
      }
      *lista = k;
      pushBack(L, lista);

   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;

   int *valor = (int *) first(L);
    
   while (valor != NULL) {
      suma += *valor;  
      valor = (int *) next(L);  
   }

   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   if(L == NULL) return; 

   int* actual = first(L); 
   while(actual != NULL){
      if(*actual == elem){
         popCurrent(L); 
         actual = next(L); 
      }
      else{
         actual = next(L); 
      }
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* auxiliar = create_stack();
   while(top(P1) != NULL)
   {
      void* elemento = top(P1);
      pop(P1);
      push(auxiliar, elemento);
   }

   while(top(auxiliar) != NULL)
   {
      void* elemento = top(auxiliar);
      pop(auxiliar);
      push(P1, elemento);
      push(P2, elemento);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   int n = strlen(cadena);
   char *stack = malloc(n);
   if (!stack) return 0;

   int top = -1;

   for (int i = 0; cadena[i] != '\0'; i++) {
      char c = cadena[i];

      if (c == '(' || c == '[' || c == '{') {
         stack[++top] = c;
      }
      
      else if (c == ')' || c == ']' || c == '}') {
         if (top == -1) { 
               free(stack);
               return 0;
            }
         char apertura = stack[top--]; 

            if ((c == ')' && apertura != '(') ||
               (c == ']' && apertura != '[') ||
               (c == '}' && apertura != '{')) {
               free(stack);
               return 0;
            }
        }
    }

   int balanceado = (top == -1);
   free(stack);

   return balanceado;
}


