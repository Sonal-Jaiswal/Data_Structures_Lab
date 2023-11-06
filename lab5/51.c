/*
	Write a program to create a double linked list and perform the following menu based operations on it:
	i. insert an element at specific position
	ii. delete an element from specific position
	iii. Traverse the list
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* prev, * next;
};

struct node* head = NULL;

void insert(int e, int pos)
{
	struct node* temp = head, * curr = (struct node*)malloc(sizeof(struct node));
	curr->data = e;
	int count = 0;
	if (pos == 1)
	{
		curr->prev = NULL;
		curr->next = head;
		head = curr;
	}
	else
	{
		while (temp->next != NULL && count == pos - 1)
		{
			temp = temp->next;
			count++;
		}
		curr->prev = temp;
		curr->next = temp->next;
		temp->next = curr;
	}
	printf("Element Inserted");
}

void delete(int pos)
{
	struct node* temp = head;
	int count = 0;
	if (pos == 1)
		head = head->next;
	else
	{
		while (temp->next != NULL && count == pos - 1)
		{
			temp = temp->next;
			count++;
		}
		temp->next = temp->next->next;
	}
	printf("Element Deleted");
}

void traverse()
{
	struct node* temp = head;
	if (head == NULL)
	{
		printf("Empty List\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%d", temp->data);
		if (temp->next != NULL)
			printf(" -> ");
		temp = temp->next;
	}
}

int main()
{
	int n, ch, e, p;
	struct node* temp;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	printf("Enter elements : ");
	for (int i = 0; i < n; i++)
	{
		struct node* curr = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &curr->data);
		curr->next = NULL;
		if (head == NULL)
		{
			curr->prev = NULL;
			temp = curr;
			head = temp;
		}
		else
		{
			curr->prev = temp;
			temp->next = curr;
			temp = temp->next;
		}
	}
        printf("\nMENU : \n");
		printf("1. Insert an element at specific position\n");
		printf("2. Delete an element at specific position\n");
		printf("3. Traverse\n");
		printf("4. Exit\n");
	do
	{
		
		printf("Enter the choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the element and position : ");
			scanf("%d %d", &e, &p);
			if (p < 0)
				printf("Invalid Position");
			else
				insert(e, p);
			break;
		case 2:
			printf("Enter the position to delete element from : ");
			scanf("%d", &p);
			if (p < 0)
				printf("Invalid Position");
			else
				delete (p);
			break;
		case 3:
			traverse();
			break;
		case 4:
			printf("Exiting.....");
			break;
		default:
			printf("Invalid Choice");
		}
		printf("\n\n");
	} while (ch != 4);
	return 0;
}