#include <stdio.h>
#include "./dll.h"
#include <string.h>
#include <stdlib.h>

/* Application specific data structures */
typedef struct student {
	int roll_no;
	char name[25];
	double weight;
}student_t;

void
print_student(const student_t *data){
	printf("===============================\n");
	printf("Roll no : %d\n",data->roll_no);
	printf("Name : %s\n",data->name);
	printf("Weight : %.2f\n",data->weight);
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

typedef struct employee {
	int id;
	char name[25];
	char designation[25];
}employee_t;

void
print_employee(const employee_t *data){
	printf("===============================\n");
	printf("Emp Id : %d\n",data->id);
	printf("Name : %s\n",data->name);
	printf("Designation : %s\n",data->designation);
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

/* call-back functions */
static int compare_student_by_rollno(void *stu1, void *stu2);
static int compare_employee_by_id(void *emp1, void *emp2);

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

	student_t *student4 = calloc(1, sizeof(student_t));
	student4->roll_no = 25;
	strcpy(student4->name , "Krishna");
	student4->weight = 39;
	
	dll_t *student_data = get_dll();
	if(!student_data){
		printf("Error: get_dll returned NULL\n");
		return -1;
	}
	register_comparision_callback(student_data, compare_student_by_rollno);
	sorted_add_data(student_data, student1);
	sorted_add_data(student_data, student2);
	sorted_add_data(student_data, student3);
	sorted_add_data(student_data, student4);
        print_student_list(student_data);

	employee_t *emp1 = calloc(1, sizeof(employee_t));
	emp1->id = 1;
	strcpy(emp1->name, "AB");
	strcpy(emp1->designation, "Manager");
	
	employee_t *emp2 = calloc(1, sizeof(employee_t));
	emp2->id = 3;
	strcpy(emp2->name, "XY");
	strcpy(emp2->designation, "Developer");
	
	employee_t *emp3 = calloc(1, sizeof(employee_t));
	emp3->id = 2;
	strcpy(emp3->name, "MN");
	strcpy(emp3->designation, "Tester");

	dll_t *employee_data = get_dll();
	register_comparision_callback(employee_data, compare_employee_by_id);
	sorted_add_data(employee_data, emp1);
	sorted_add_data(employee_data, emp2);
	sorted_add_data(employee_data, emp3);
        print_employee_list(employee_data);
	
	return 0;
}
static int 
compare_student_by_rollno(void *stu1, void *stu2){
    student_t *student1 = (student_t *)stu1;
    student_t *student2 = (student_t *)stu2;
    if( student1->roll_no < student2->roll_no )
	return -1;
    else if( student1->roll_no == student2->roll_no ){
	printf("Two students can not have same rollno\n");
	return 0;
    }
    else
	return 1;
}

static int
compare_employee_by_id(void *emp1, void *emp2){
    employee_t *employee1 = (employee_t *)emp1;
    employee_t *employee2 = (employee_t *)emp2;
    if( employee1->id < employee2->id )
	return -1;
    else if( employee1->id == employee2->id ){
	printf("Two employees can not have same id\n");
	return 0;
    }
    else
	return 1;
}
