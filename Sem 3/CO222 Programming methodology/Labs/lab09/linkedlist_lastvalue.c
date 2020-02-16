#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node* next;
	int value;
} Node;

int findLastNodeValue(Node * head)
{
	int retval = 0;

	if(head == NULL){
		printf("EMPTY LIST\n");
		return 1;
	}else{

		if(head->next == NULL){
			retval = head->value;
			printf("Last node value is = %d\n",retval);
		}
	}
	return retval;
}

int main()
{
	Node *node1,*node2;
	node1 = (Node *) malloc(sizeof(Node));

	node1->value = 78;

	node2 = NULL;
	node1->next = node2;

	findLastNodeValue(node1);
	findLastNodeValue(node2);
}
