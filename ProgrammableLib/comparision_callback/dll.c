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
register_comparision_callback(dll_t *dll, int (*call_back)(void *, void *)){
    if(dll == NULL){
	printf("dll is NULL\n");
        return;
    }
    else{
        dll->cmp = call_back;
	return;
    }
}
int
sorted_add_data(dll_t *db, void *data){
    if(db == NULL){
	    printf("db is NULL\n");
	    return -1;
    }
    dll_node_t *lvNode;
    lvNode = calloc(1,sizeof(dll_node_t));
    lvNode->prev = NULL;
    lvNode->data = data;
    lvNode->next = NULL;
    /* If DLL is empty & this is the first node */
    if(db->head == NULL){
        db->head = lvNode;
	return 0;
    }
    /* If there is only one node in DLL */
    if(db->head && db->head->next == NULL){
	/* Existing rollno is less than new rollno, add new node at end
	 * else add at begining */
        if(db->cmp(db->head->data, data) == -1){
            lvNode->prev = db->head;
            db->head->next = lvNode;
	}
	else{
	    lvNode->next = db->head;
	    db->head->prev = lvNode;
	    db->head = lvNode;
	}
	return 0;
    }
    /* If there are more than one node in the list */
    if(db->cmp(db->head->data, data) == 1){ //Add at begin
	lvNode->next = db->head;
        db->head->prev = lvNode;
        db->head = lvNode;
    }
    dll_node_t *lvcur = db->head;
    dll_node_t *lvprev = NULL;
    while(lvcur){
	    if(db->cmp(lvcur->data, data) == -1){ //If current node is not less than new node
		lvprev = lvcur;
		lvcur = lvcur->next;
		continue;
	    }
	    lvNode->next = lvprev->next;
	    lvcur->prev = lvNode;
	    lvprev->next = lvNode;
	    lvNode->prev = lvprev;
	    return 0; 
    }
    lvprev->next = lvNode;
    lvNode->prev = lvprev;
    return 0;
}
