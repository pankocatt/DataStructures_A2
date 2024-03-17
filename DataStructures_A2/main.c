// Interface for a binary search tree set of functions.
// Dina M, Winter 2024, Data Structures Sec 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarySearch.h"

int main(void) {

	TreeInit();

	// Generate random amt. of characters
	srand(time(NULL));
	int r = (rand() % 20) + 11;
	// Generate a random letter
	char randomletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];

	link root = NULL;
	root = TreeInsert(root, randomletter);

	printf("\nTree unorganized: ");

	// 1. Inserting a random amount (11 - 20) of characters that are random ( a - z )
	for (int i = 0; i < r; i++) {
		// Generate random data
		char randomletter = 'A' + rand() % 26;
		
		printf("%c", randomletter); // printing letter for proof of randomness
		TreeInsert(root, randomletter);
	}

	// 2. Printing nodes in order
	printf("\nTree in order: ");
	traverse(root);

	// 3. Printing number of nodes
	printf("\nTree count: %d", count(root));

	// 4. Printing tree height
	printf("\nTree height: %d", height(root));
	return 0;
}