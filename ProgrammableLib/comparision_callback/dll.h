/* This is a header file for declaring double linked list data structure and functions */

typedef struct dll_node {
	void *data;
	struct dll_node *prev;
	struct dll_node *next;
}dll_node_t;

typedef struct dll {
	dll_node_t *head;
	int (*cmp)(void*, void*);
}dll_t;

dll_t *
get_dll(void);

int
add_node(dll_t *dll, void *app_data);

/* Function used for registering the callback function
 * dll_t * : Pointer to double linked list
 * call_back : Function pointer passed from application, which will be called from library
 */
void
register_comparision_callback(dll_t *, int (*call_back)(void *, void *));

/* Function which will be called to add data in linked list
 * This function is an agnostic function, based on the callback registered 
 * in db, we will call the respective functions.
 * db: handle to double linked list
 * data: data which needs to be added in the list
 */
int
sorted_add_data(dll_t *db, void *data);
