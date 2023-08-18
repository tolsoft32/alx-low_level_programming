#include "lists.h"

/**
 * sum_dlistint - function that sum up all the data
 * @head: pointer to header of the linked list
 * Return: sum of the data in a linked list
 */
int sum_dlistint(dlistint_t *head)
{
	int add;

	add = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			add += head->n;
			head = head->next;
		}
	}
	return (add);
}
