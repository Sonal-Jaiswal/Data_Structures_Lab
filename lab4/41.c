/*
	WAP to create a single linked list of n nodes and perform the following menu based operations on it using functions:
	1. Insert a node at specific position
	2. Deletion of a node at specific position
	3. Count nodes
	4. Traverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert(int pos, int e)
{
	struct node *temp = head, *new = (struct node *)malloc(sizeof(struct node));
	int count = 1;
	new->data = e;
	if (pos == 1)
	{
		new->next = head;
		head = new;
	}
	else
	{
		while (count != pos - 1 && temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		new->next = temp->next;
		temp->next = new;
	}
	printf("Element inserted");
}

void delete(int pos)
{
	struct node *temp = head;
	int count = 1;
	if (pos == 1)
	{
		head = temp->next;
	}
	else
	{
		while (count != pos - 1 && temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
	printf("Element deleted ");
}

int count()
{
	struct node *temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void traverse()
{
	struct node *temp = head;
	if (head == NULL)
		printf("Empty List");
	else
		while (temp != NULL)
		{
			printf("%d", temp->data);
			temp = temp->next;
			if (temp != NULL)
				printf(" -> ");
		}
}

int main()
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	int n, ch = 0, e, p;

	printf("Enter number of nodes : ");
	scanf("%d", &n);
	printf("Enter the elements : ");
	scanf("%d", &temp->data);

	temp->next = NULL;
	head = temp;
	
	for (int i = 0; i < n - 1; i++)
	{
		struct node *current = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &current->data);
		current->next = NULL;
		temp->next = current;
		temp = temp->next;
	}
        printf("1. Insert a node at specific position\n");
		printf("2. Deletion of a node at speciic position\n");
		printf("3. Count\n");
		printf("4. Traversal\n");
		printf("5. Exit\n");
	while (ch != 5)
	{
		
		printf("Enter choice ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the element and position to insert at : ");
			scanf("%d %d", &e, &p);
			if (p <= 0)
				printf("Invalid Position");
			else
				insert(p, e);
			break;
		case 2:
			printf("Enter the position to be deleted : ");
			scanf("%d", &p);
			delete (p);
			break;
		case 3:
			printf("The number of elements are : %d", count());
			break;
		case 4:
			printf("The list is \n");
			traverse();
			break;
		case 5:
			printf("Exiting....");
			break;
		default:
			printf("Invalid Choice");
			break;
		}
		printf("\n");
	}
	return 0;
}