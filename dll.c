/* This file contains defination of the functions defined in dll.h file */
#include "dll.h"
#include <stdlib.h>

dll_t *
get_dll(void) {
	dll_t *dll;
	dll = malloc(sizeof(dll_t));
	if(dll == NULL)
		return NULL;
	else
		dll->head = NULL;
		return dll;
}

int
add_node(dll_t *dll, void *app_data){
	if(!dll || !app_data)
		return -1;
	dll_node_t *temp;
	temp = malloc(sizeof(dll_node_t));
	if(temp == NULL)
		return -1;
	temp->prev = NULL;
	temp->data = app_data;
	temp->next = NULL;
	if(dll->head == NULL){
	        dll->head = temp;
		return 0;
	}
	temp->next = dll->head;
	dll->head->prev = temp;
	dll->head = temp;
	return 0;
}
