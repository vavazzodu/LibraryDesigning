/* This file contains defination of the functions defined in dll.h file */
#include <stdio.h>
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
void
register_call_back(dll_t *dll, int (*call_back)(void *, void*)){
	if(dll == NULL) return;
	dll->key_match = call_back;
	return;
}
void *
find_from_db(dll_t *dll, void *key){
	if(dll == NULL || dll->head == NULL)
		return NULL;
	dll_node_t *lvNode = dll->head;
	while(lvNode){
		if((dll->key_match(lvNode->data, key)) == 0){
			return (void *)lvNode->data;
		}
		else
			lvNode = lvNode->next;
	}
	return NULL;
}
