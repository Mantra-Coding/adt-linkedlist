#include "item.h"

typedef struct c_list *list;

list new_list();
int is_empty(list);
item get_first(list);
int insert(list, item, int);
int remove_l(list, int);
int get_item_pos(list l, item i);
item get_item(list l, int pos);
list clone_list(list l);
list reverse_list(list l);
int delete_list(list l);
int get_size(list l);
void output_list(list l);