// Interface for a binary search tree set of functions.
// Dina M, Winter 2024, Data Structures Sec 3

#pragma once

#include <stdio.h>

typedef struct TreeNode* link;

struct TreeNode {
	char data;
	link pLeft;
	link pRight;
};

static char NullData = {0};
static link head;

link NewNode(char item, link left, link right);

void TreeInit(void);

// 1. Insert
link TreeInsert(link h, char item);

void Insert(char item);

// 2. Searching
char TreeSearch(link h, char* searchKey);

// 3. Determining count
int count(link h);

// 4. Determining height
int height(link h);

void traverse(link h);