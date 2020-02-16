// Fix the bugs

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node * next;
};

typedef struct node Node;

int main()
{

	Node* iterator;
	// Create a linked list with 10 elements

	iterator = malloc(sizeof(Node));
	iterator->value = 0;

	iterator->next = malloc(sizeof(Node));
	iterator->next->value = 1;

	iterator->next->next = malloc(sizeof(Node));
	iterator->next->next->value = 2;

	iterator->next->next->next = malloc(sizeof(Node));
	iterator->next->next->value = 3;

	iterator->next->next->next->next = malloc(sizeof(Node));
	iterator->next->next->next->value = 4;

	iterator->next->next->next->next->next = malloc(sizeof(Node));
	iterator->next->next->next->next->value = 5;

	iterator->next->next->next->next->next->next = malloc(sizeof(Node));
	iterator->next->next->next->next->next->value = 6;

	iterator->next->next->next->next->next->next->next = malloc(sizeof(Node));
	iterator->next->next->next->next->next->next->value = 7;

	iterator->next->next->next->next->next->next->next->next = malloc(sizeof(Node));
	iterator->next->next->next->next->next->next->next->value = 8;

	iterator->next->next->next->next->next->next->next->next->next = malloc(sizeof(Node));
	iterator->next->next->next->next->next->next->next->next->value = 9;

	iterator->next->next->next->next->next->next->next->next->next = NULL;


	// Printing the values
	Node* current = iterator;
	while(current != NULL)
	{
		printf("Value %d\n", current->value);
		current = current->next;
	}
}
