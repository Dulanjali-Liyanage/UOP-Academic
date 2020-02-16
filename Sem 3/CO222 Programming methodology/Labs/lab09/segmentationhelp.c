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
	Node head;
	Node* iterator = &head;
	// Create a liked list with 10 elements
	int i = 0;
	Node* newNodep;
	Node* hell = newNodep;

	for(i = 0; i<10 ; i ++)
	{
		//Node* newNodep;
		//iterator->next = newNodep;
		//newNodep->value = i;
		//iterator = newNodep;

	}






	// Printing the values
	//iterator = &head;
	Node* current = iterator;
	while(current != NULL)
	{
		printf("Value %d\n", current->value);

		current = current->next;
	}
}
