// Implementation for a binary search tree set of functions.
// Dina M, Winter 2024, Data Structures Sec 3

#include "binarySearch.h"
#include <stdio.h>
#include <stdlib.h>

link NewNode(char item, link left, link right) {
	link pNew = (link)malloc(sizeof(*pNew));
	pNew->data = item;
	pNew->pLeft = left;
	pNew->pRight = right;
	return(pNew);
}

void TreeInit(void) {
	head = NewNode(NullData, NULL, NULL); // Start empty
}

// 1. Insertion
link TreeInsert(link h, char item) {
	if (h == NULL) return(NewNode(item, NULL, NULL)); // If no head exists, insert it at the start

	// Go left, or go right?
	if ( item < h->data ) {
		h->pLeft = TreeInsert(h->pLeft, item);
	}
	else if ( item > h->data ) {
		h->pRight = TreeInsert(h->pRight, item);
	}
	return h;
}

void Insert(char item) {
	head = TreeInsert(head, item);
}

// 2. Searching
char TreeSearch(link h, char* searchKey) {

	if (h == NULL) return(NullData); // If we reached the end, return a leaf node

	if (searchKey == h->data ) return h->data; // Found the item, return the data

	// Otherwise, we haven't found it-- check the left & right child
	if ( searchKey < h->data ) return(TreeSearch(h->pLeft, searchKey));
	else return(TreeSearch(h->pRight, searchKey));
}

// 3. Determining count
int count(link h) {
	// Counts the total number of nodes in a tree, recursively
	if (h == NULL) return 0;
	return(count(h->pLeft) + count(h->pRight) + 1);

}

// 4. Determining height
int height(link h) {
	int iLeftH;
	int iRightH;
	if (h == NULL) return (-1);

	iLeftH = height(h->pLeft);
	iRightH = height(h->pRight);

	if (iLeftH > iRightH) {
		return(iLeftH + 1);
	}
	else {
		return(iRightH + 1);
	}
}

// Traverses the tree, and prints the node in order (inorder/alphabetical)
void traverse(link root) {
	if (root != NULL) {
		traverse(root->pLeft);
		printf("%c", root->data);
		traverse(root->pRight);
	}
}
