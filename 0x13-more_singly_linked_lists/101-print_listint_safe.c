#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Count the numbers of unique nodes
 * in a looped listint linked list
 * @head: A pointer to the head of listint_t to check
 *
 * Return: If the list is not looped - 0.
 * Otherwise - The number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *turtle, *mouse;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	turtle = head->next;
	mouse = (head->next)->next;

	while (mouse)
	{
		if (turtle == mouse)
		{
			turtle = head;
			while (turtle != mouse)
			{
				nodes++;
				turtle = turtle->next;
				mouse = mouse->next;
			}

			turtle = turtle->next;
			while (turtle != mouse)
			{
				nodes++;
				turtle = turtle->next;
			}

			return (nodes);
		}
		turtle = turtle->next;
		mouse = (mouse->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Print a listint_t list safely
 * @head: A pointer to the head of listint_t list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = loope_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head  = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("->,[%p] *d\n", (void *)head, head->n);
	}

	return (nodes);
}
