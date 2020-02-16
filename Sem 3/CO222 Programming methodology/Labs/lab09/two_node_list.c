// Warning This code is wrong though sometimes it may not give a segmentation fault

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node* next;
	int value;
} Node;

Node* CreateTwoNodeList()
{
	Node* head = (Node*) malloc(sizeof(Node));
	Node* tail = (Node*) malloc(sizeof(Node));
	tail -> value = 0;
	tail -> next = NULL;
	head -> value = 0;
	head -> next = tail;
	head -> next -> next = NULL;
	return head;
}

void FreeTwoNodeList(Node* head)
{
	free(head->next);
	free(head);
}

int main()
{
	// Create a 2 node list
	Node *head = CreateTwoNodeList();

	// Add some values

	head -> next = malloc(sizeof(Node));
	head-> value = 10;

	head -> next->next = malloc(sizeof(Node));
	head->next->value = 20;
	head->next->next = NULL;


	// Delete the list
	FreeTwoNodeList(head);



	// Add some values
	head -> next = malloc(sizeof(Node));
	head-> value = 50;

	head -> next -> next = malloc(sizeof(Node));
	head->next->value = 80;
	head->next->next = NULL;


}
