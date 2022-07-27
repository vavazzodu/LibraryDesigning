/* This file contains defination of the functions defined in dll.h file */
#include "dll.h"
#include <stdlib.h>

dll_t *
get_dll(void) {
	dll_t *dll;
	dll = calloc(1, sizeof(dll_t));
	if(dll == NULL)
		return NULL;
	else{
		dll->head = NULL;
		return dll;
	}
}

int
add_node(dll_t *dll, void *app_data){
	if(!dll || !app_data)
		return -1;
	dll_node_t *new_node;
	new_node = calloc(1, sizeof(dll_node_t));
	if(new_node == NULL)
		return -1;
	new_node->prev = NULL;
	new_node->data = app_data;
	new_node->next = NULL;
	if(dll->head == NULL){  //If this is the first node
	        dll->head = new_node;
		return 0;
	}
	new_node->next = dll->head;
	dll->head->prev = new_node;
	dll->head = new_node;
	return 0;
}
