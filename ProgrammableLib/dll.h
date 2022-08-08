/* This is a header file for declaring double linked list data structure and functions */

typedef struct dll_node {
	void *data;
	struct dll_node *prev;
	struct dll_node *next;
}dll_node_t;

typedef struct dll {
	dll_node_t *head;
	int (*key_match)(void*, void*);
}dll_t;

dll_t *
get_dll(void);

int
add_node(dll_t *dll, void *app_data);

void
register_call_back(dll_t *, int (*call_back)(void *, void *));

void *
find_from_db(dll_t *, void *);
