/*
	WAP to create a singly linked list of n nodes and perform the following menu based operations on it using function :
	1. Insert the node at the position
	2. Delete the node at the position
	3. Count
	4. Traverse
	5. Search
	6. Sort ( in ascending order )
	7. Reverse
	8. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;

void swap(struct node *a, struct node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

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

int search(int element)
{
	struct node *temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		if (temp->data == element)
			return count;
		temp = temp->next;
	}
	return 0;
}

void sort()
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	struct node *temp = head;
	struct node *new = head->next;
	for (temp->data; temp != NULL; temp = temp->next)
	{
		for (new->data; new != NULL; new = new->next)
			if (temp->data > new->data)
				swap(temp, new);
		new = temp->next;
	}
}

void reverse()
{
	struct node *prev = NULL;
	struct node *current = head;
	struct node *next = current->next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

int main()
{
	int n, ch = 0;
	int e;
	int p;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	printf("Enter the elements : ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	head = temp;
	for (int i = 1; i < n; i++)
	{
		struct node *current = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &current->data);
		current->next = NULL;
		temp->next = current;
		temp = temp->next;
	}
        printf("1. Insert the node at the position\n");
		printf("2. Delete the node at the position\n");
		printf("3. Count\n");
		printf("4. Traverse\n");
		printf("5. Search\n");
		printf("6. Sort\n");
		printf("7. Reverse\n");
		printf("8. Exit\n");

	while (ch != 8)
	{
		
		printf("Enter your choice : ");
		scanf("%d", &ch);
		
		switch (ch)
		{
		case 1:
			printf("Enter the element and position to insert at : ");
			scanf("%d %d", &e, &p);
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
			traverse();
			break;
		case 5:
			printf("Enter the element to search : ");
			scanf("%d ", &e);
			if (search(e))
				printf("Elment found at position : %d", search(e));
			else
				printf("Element not found");
			break;
		case 6:
			sort();
			break;
		case 7:
			reverse();
			break;
		case 8:
			printf("Exiting...");
			break;
		default:
			printf("Invalid Choice");
			break;
		}
		printf("\n\n");
	}
}