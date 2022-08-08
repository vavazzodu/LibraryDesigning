#include <stdio.h>
#include "./dll.h"
#include <string.h>
#include <stdlib.h>

typedef struct student {
	int roll_no;
	char name[25];
	double weight;
}student_t;

typedef struct employee {
	int id;
	char name[25];
	char designation[25];
}employee_t;

void print_student_list(const dll_t *student_list);
void print_employee_list(const dll_t *employee_list);
/* Normal search functions */
student_t * find_student(const dll_t *student_list, int key);
employee_t * find_employee(const dll_t *employee_list, int key);
/* Functions to print the node */
void print_student(const student_t *data);
void print_employee(const employee_t *data);
/* call-back functions */
int student_record_match(void *, void *);
int employee_record_match(void *, void *);

int
main(int argc, char **argv){
	student_t *student1 = calloc(1, sizeof(student_t));
	student1->roll_no = 10;
	strcpy(student1->name , "Karan");
	student1->weight = 55;
	
	student_t *student2 = calloc(1, sizeof(student_t));
	student2->roll_no = 20;
	strcpy(student2->name , "Raval");
	student2->weight = 60.7;
	
	student_t *student3 = calloc(1, sizeof(student_t));
	student3->roll_no = 30;
	strcpy(student3->name , "Rahul");
	student3->weight = 70.65;

	dll_t *student_data = get_dll();
	if(!student_data){
		printf("Error: get_dll returned NULL\n");
		return -1;
	}
	register_call_back(student_data, student_record_match);
	add_node(student_data, student1);
	add_node(student_data, student2);
	add_node(student_data, student3);

	/* This is search using call-back */
	student_t *student = find_from_db(student_data, (void *)30);
	if(!student){
		printf("Student record not found\n");
	}
	else{
		printf("Student found\n");
		print_student(student);
	}

	/* This is normal search */
	/*
	student_t *student = find_student(student_data, 10);
	if(!student)
		printf("Student is not found\n");
	else{
		printf("student found\n");
		print_student(student);
	}
	*/
	
	employee_t *emp1 = calloc(1, sizeof(employee_t));
	emp1->id = 111;
	strcpy(emp1->name, "ABC");
	strcpy(emp1->designation, "Manager");
	
	employee_t *emp2 = calloc(1, sizeof(employee_t));
	emp2->id = 222;
	strcpy(emp2->name, "XYZ");
	strcpy(emp2->designation, "Developer");
	
	employee_t *emp3 = calloc(1, sizeof(employee_t));
	emp3->id = 333;
	strcpy(emp3->name, "LLL");
	strcpy(emp3->designation, "Tester");

	dll_t *employee_data = get_dll();
	register_call_back(employee_data, employee_record_match);
	add_node(employee_data, emp1);
	add_node(employee_data, emp2);
	add_node(employee_data, emp3);
	
	/* This is search using call-back */
	employee_t *employee = find_from_db(employee_data, (void *)111);
	if(!employee){
		printf("Emloyee record not found\n");
	}
	else{
		printf("Employee found\n");
		print_employee(employee);
	}
	/* This is normal search */
	/*
	employee_t *employee = find_employee(employee_data, 222);
	if(!employee)
		printf("Employee is not found\n");
	else{
		printf("Employee found\n");
		print_employee(employee);
	}
	*/
	return 0;
}
void
print_student(const student_t *data){

	printf("===============================\n");
	printf("Roll no : %d\n",data->roll_no);
	printf("Name : %s\n",data->name);
	printf("Weight : %.2f\n",data->weight);
}
void
print_employee(const employee_t *data){

	printf("===============================\n");
	printf("Emp Id : %d\n",data->id);
	printf("Name : %s\n",data->name);
	printf("Designation : %s\n",data->designation);
}
void
print_student_list(const dll_t *student_list){
	dll_node_t *temp_head = NULL;
	student_t *data = NULL;
	if(student_list == NULL || student_list->head == NULL){
		printf("List is empty\n");
		return;
	}
	temp_head = student_list->head;
	while(temp_head)
	{
		data = (student_t *)temp_head->data;
		print_student(data);
		temp_head = temp_head->next;
	}
	return;
}
void
print_employee_list(const dll_t *employee_list){
	dll_node_t *temp_head = NULL;
	employee_t *data = NULL;
	if(employee_list == NULL || employee_list->head == NULL){
		printf("List is empty\n");
		return;
	}
	temp_head = employee_list->head;
	while(temp_head)
	{
		data = (employee_t *)temp_head->data;
		print_employee(data);
		temp_head = temp_head->next;
	}
	return;
}
student_t *
find_student(const dll_t *student_list, int key){
	if(student_list == NULL || student_list->head == NULL){
		printf("The list is empty\n");
		return NULL;
	}
	dll_node_t *temp_head = student_list->head;
	student_t *data = NULL;
	while(temp_head){
		data = temp_head->data;
		if(data->roll_no == key)
			return data;
		temp_head = temp_head->next;
	}
}
employee_t *
find_employee(const dll_t *employee_list, int key){
	if(employee_list == NULL || employee_list->head == NULL){
		printf("The list is empty\n");
		return NULL;
	}
	dll_node_t *temp_head = employee_list->head;
	employee_t *data = NULL;
	while(temp_head){
		data = temp_head->data;
		if(data->id == key)
			return data;
		temp_head = temp_head->next;
	}
}
int 
student_record_match(void *dll_data, void *key){
	student_t *lvdata = (student_t *)dll_data;
	int lvRollno = (int)key;
	if(lvdata->roll_no == lvRollno)
		return 0;
	else
		return 1;

}
int employee_record_match(void *dll_data, void *key){
	employee_t *lvdata = (employee_t*)dll_data;
	int lvEmpId = (int)key;
	if(lvdata->id == lvEmpId)
		return 0;
	else
		return 1;
}

