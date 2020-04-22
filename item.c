#include <stdio.h>
#include <stdlib.h>
#include "item.h"

/*
 * Change this file to reflect correct operations
 * for the type you are assigning to item
 * */

int equals(item i1, item i2) {
    return i1 == i2;
}

void input_item(item *i1) {
	scanf("%d", i1);
}

void output_item(item i) {
	printf("%d", i);
}

item clone_item(item i) {
	item clone = i;
	return clone;
}

