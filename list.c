/**
 * @file
 * */

#include <stdlib.h>
#include "list.h"

struct c_list {
    struct node *first;
    int size;
};

struct node {
    item val;
    struct node *next;
};

/**
 * Create a new list and initialize its fields
 * @returns A new empty list
 * */
list new_list() {
    list l_new = malloc(sizeof(struct c_list));
    if (!l_new) return NULL;
    l_new->size = 0;
    l_new->first = NULL;
    return l_new;
}

/**
 * Get how many elements are in a list
 * @param[in] l A list you wanna get the size
 * @retuns The number of elements in list l
 * */
int get_size(list l) {
    if(!l) return -1;
    return l->size;
}

/**
 * Check if a list is empty or not
 * @param[in] l The list to check
 * @return -1 The list is pointing to NULL (not allocated)
 * @return 1 The list is empty
 * @return 0 The list has at least 1 item in it
 * */
int is_empty(list l) {
    if(!l) return -1;
    return l->size == 0;
}

/**
 * Given a node returns the node next to the given one
 * @param[in] n The node to "tail"
 * @return The node next to n
 * @return NULL If n is the last node
 * */
static struct node *tail_list(struct node *n) {
    return n->next;
}

/**
 * Given a node inserts a new node before the given one
 * Used in {@link #insert(list, item, int)} method
 * @param[in] n The node to be the next of the one created
 * @param[in] i1 The value assigned to the new node
 * @return nn The new node inserted in the list
 * */
static struct node *insert_ontop(struct node *n, item i1) {
    struct node *nn = malloc(sizeof(struct node));
    nn->next = n;
    nn->val = i1;
    return nn;
}

/**
 * Get the value of the first node in a list
 * @param[in] l The list to get the value from
 * @return NULL_ITEM If the list is NULL (not allocated)
 * @return val The value of the first item
 * */
item get_first(list l) {
    if (!l) return NULL_ITEM;
    return l->first->val;
}

/**
 * Insert a new node in the list l at a given position
 * @param[in] l The list in which to insert the item
 * @param[in] i The item to insert
 * @param[in] index The position where to insert the item
 * @return -1 If the list l is NULL (not allocated) or it is empty
 * @return 0 If the index parameter is out of bounds
 * @return 1 If the operation was successful
 * */
int insert(list l, item i, int index) {
    if (!l || l->size == 0) return -1;
    if (index == 0) {
        struct node *n = insert_ontop(l->first, i);
        l->size++;
        l->first = n;
        return 1;
    }
    if (index < 0 || index > l->size) return 0;

    int in;
    struct node *l1 = l->first;

    //Scorro fino al nodo di pos. precedente a index
    for (in = 0; in < index-1; in++) l1 = tail_list(l1);
    //Inserisco il nuovo nodo prima dell'elemento in pos. successiva a index
    struct node *new = insert_ontop(l1->next, i);
    l1->next = new;
    l->size++;
    return 1;
}

/**
 * Remove an item from a list
 * @param[in] l The list containing the element to remove
 * @param[in] index The position of the element to remove
 * @return -1 If the list l is NULL (not allocated) or it is empty
 * @return 0 If the index is out of bounds
 * @return 1 If the operation was successful
 * */
int remove_l(list l, int index) {
    if (!l || l->size == 0) return -1;
    struct node *del;
    if (index > l->size) return 0;
    if (index == 0) {
        del = l->first;
        l->first = tail_list(l->first);
        l->size--;
        free(del);
        return 1;
    }

    struct node *ll = l->first;

    int i;
    for (i = 0; i < index-1; i++) ll = tail_list(ll);
    if (index == l->size-1) {
        del = ll->next;
        ll->next = NULL;
        free(del);
        return 1;
    }
    del = ll->next;
    ll->next = ll->next->next;
    l->size--;
    free(del);
    return 1;
}

/**
 * Get the index of an item in a list
 * @param[in] l The list containing the item
 * @param[in] i The item to get the position of
 * @return -2 If the element was not found in the list
 * @return -1 If the list l is NULL (not allocated) or it is empty
 * @return pos The position of the item in the list
 * */
int get_item_pos(list l, item i) {
    if (l == NULL || l->size == 0) {
        return -1;
    }

    int pos = 0;
    int found = 0;

    struct node *temp = l->first;

    while(pos < l->size && !found) {
        if (equals(temp->val, i)) found = 1;
        else {
            temp = tail_list(temp);
            pos++;
        }
    }

    if (!found) return -2;
    else return pos;
}

/**
 * Get the item at a given position, in the list
 * @param[in] l The list containing the item
 * @param[in] pos The position of the item
 * @return NULL_ITEM If `pos` is out of bounds
 * @return The item at the position `pos` in the list
 * */
item get_item(list l, int pos) {
    if (pos < 0 || pos > l->size) return NULL_ITEM;
    if (pos == 0) return l->first->val;

    struct node *n = l->first;

    int i;
    for (i = 0; i < pos; i++) n = tail_list(n);
    return n->val;
}

/**
 * Clone a given list
 * @param[in] l The list to clone
 * @return NULL If the given list is not allocated
 * @return A new list identical to the given one
 * */
list clone_list(list l) {
    if (l == NULL) return NULL;
    list new = new_list();
    if (!new) return NULL;

    new->first = malloc(sizeof(struct node));
    new->first->val = l->first->val;
    new->size = l->size;

    struct node *p = l->first;
    struct node *p_n = new->first;
    struct node *p_before = new->first;
    while (1) {
        p = tail_list(p);
        if (!p) break;
        p_n = tail_list(p_n);
        p_n = malloc(sizeof(struct node));
        p_n->val = p->val;
        p_before->next = p_n;
        p_before = tail_list(p_before);
    }

    return new;

}

/**
 * Given a list clones and reverses it
 * @param[in] l The list to reverse
 * @return NULL If the given list is NULL (not allocated)
 * @return The given list reversed
 * */
list reverse_list(list l) {
    if (!l) return NULL;
    list new_reverse = new_list();
    if (!new_reverse) return NULL;

    new_reverse->first = malloc(sizeof(struct node));
    new_reverse->first->val = l->first->val;
    new_reverse->size = l->size;

    struct node *p = l->first;
    struct node *n = new_reverse->first;

    for (int i = 0; i < l->size-1; i++) {
        p = tail_list(p);
        n = insert_ontop(n, p->val);
    }
    new_reverse->first = n;
    return new_reverse;
}

/**
 * Given a list deallocates its nodes and deletes links between nodes
 * @param[in] l The list to delete
 * @return 0 If the list is NULL (not allocated)
 * @return 1 If the operation was successful
 * */
int delete_list(list l) {
    if (!l) return 0;
    if (l->size == 0) return 1;
    l->size = 0;

    struct node *temp = l->first;
    struct node *temp1;
    while(1) {
        if (!temp) break;
        temp1 = temp;
        temp = tail_list(temp);
        free(temp1);
    }

    l->first = NULL;
    return 1;
}

/**
 * Prints a list to stdout
 * @param[in] l The list to print
 * */
void output_list(list l) {
    int i;
    for (i = 0; i < l->size; i++) {
        output_item(get_item(l, i));
    }
}