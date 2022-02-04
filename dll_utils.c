#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include <string.h>
int
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data);

int
is_empty(dll_t *dll);

void
drain_dll(dll_t *dll);

int
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data){
	if (dll == NULL || dll->head == NULL){
		printf("Linked list is empty\n");
		return -1;
	}
	char *dummy = (char *)data;
	dll_node_t *temp, *temp1;
	temp = dll->head;
	temp1 = NULL;
	if(!(strcmp((char *)temp->data,dummy))){  //If first node matches
		dll->head = temp->next;
		dll->head->prev = NULL;
		free(temp);
		return 0;
	}
	temp1 = temp;
	temp = temp->next;
	while(temp->next){  //Iterate till last node
	        if(!(strcmp((char *)temp->data,dummy))){
			temp1->next = temp->next;
			temp->next->prev = temp1;
			free(temp);
			return 0;
		}
		temp1 = temp;
		temp = temp->next;
	}
	if(!(strcmp((char *)temp->data,dummy))){ //checking last node and match found
		temp1->next = NULL;
		free(temp);
		return 0;
	}
	else{
		printf("Node is unavailable..\n");
		return -1;
	}
}
int
is_empty(dll_t *dll){
	if(dll == NULL || dll->head == NULL)
		return 0;
	else
		return -1;
}
void
drain_dll(dll_t *dll){
	dll_node_t *temp, *temp1;
	temp = dll->head;
	while(temp->next){
		temp1 = temp;
		temp = temp->next;
		free(temp1);
		temp1 = NULL;
	}
	temp1 = temp;
	free(temp1);
	temp1 = NULL;
	dll->head = NULL;
	dll = NULL;
}
