#include <stdio.h>
#include "dll.h"
#include <stdlib.h>
#include <string.h>

typedef struct person_{

    char name[32];
    int age;
    int weight;
} person_t;
void
print_person_db(dll_t *dll_head){
	if(dll_head == NULL || dll_head->head == NULL){
		printf("No data found\n");
		return;
	}
	person_t *data = NULL;
	dll_node_t *temp = dll_head->head;
	while(temp){
		data = temp->data;
		printf("Name: %s\n",data->name);
		printf("Age: %d\n", data->age);
		printf("Weight: %d\n", data->weight);
		temp = temp->next;
	}
}
int
main(int argc, char **argv){
	person_t *person1 = calloc(1, sizeof(person_t));
	strncpy(person1->name, "Karan",strlen("Karan"));
	person1->age = 27;
	person1->weight = 75;
	person_t *person2 = calloc(1, sizeof(person_t));
	strncpy(person2->name, "Raval",strlen("Raval"));
	person2->age = 55;
	person2->weight = 57;
	person_t *person3 = calloc(1, sizeof(person_t));
	strncpy(person3->name, "Krishna",strlen("Krishna"));
	person3->age = 27;
	person3->weight = 37;
	//Create link list
	dll_t *person_db = NULL;
	person_db = get_dll();
	if(person_db == NULL)
		return 0;
	add_node(person_db, person1);
	add_node(person_db, person2);
	add_node(person_db, person3);

	print_person_db(person_db);
        remove_data_from_dll_by_data_ptr(person_db, "Karan");
	printf("After removing Karan\n");
	print_person_db(person_db);
	if(is_empty(person_db) == 0)
		printf("Linked list is empty\n");
	else
		printf("Linked list is not empty\n");
        drain_dll(person_db);
	printf("After draining all\n");
	print_person_db(person_db);
 	return 0;
}
