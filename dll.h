/* This is a header file for declaring double linked list data structure and functions */

typedef struct dll_node {
	void *data;
	struct dll_node *prev;
	struct dll_node *next;
}dll_node_t;

typedef struct dll {
	dll_node_t *head;
}dll_t;

dll_t *
get_dll(void);

int
add_node(dll_t *dll, void *app_data);

int
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data);

int
is_empty(dll_t *dll);

void
drain_dll(dll_t *dll);
