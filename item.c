#include <stdio.h>
#include "item.h"

int equals(item i1, item i2) {
    return i1 == i2;
}

void input_item(item *i1) {
	scanf("%d", i1);
}

void output_item(item i) {
	printf("%d", i);
}

