
# adt-linkedlist
![GitHub issues](https://img.shields.io/github/issues/mantra-coding/adt-linkedlist?style=for-the-badge) ![GitHub](https://img.shields.io/github/license/mantra-coding/adt-linkedlist?color=%23ff6e40&style=for-the-badge)

**An Abstract-Data-Structure representing a Linked List in C.** 
Defining new data-structures in C can be long and complex. This module gives you the opportunity to use a Linked List in your projects through several operators to create a list, insert and remove items and more... ([refer to the docs](https://mantra-coding.github.io/adt-linkedlist)).
## Usage
Clone the repo with `git clone` and move the files to your workspace, then include `list.h` into your source code like so:
```c
#include "list.h"
```
After doing this you can start using the operators. 
To store your own data types in the list edit `item.c` to reflect the correct assignments and operations for the data you want to store (do not remove or rename the defaults operators, just edit them to reflect the operations for your type).  In the following example we are printing all the items (int) stored in the list.
### Example
```c
list.c

#include "list.h"

int main() {
	list l = new_list();
	int size = get_size(l);
	//The following prints all the items in the list to stdout
	for (int i = 0; i < size; i++) {
		output_item(get_item(l, i);
	}
}	

item.c

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
```
## License
MIT License

Copyright (c) 2020 MantraCoding
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
