#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - summing list
 * @head: points to head
 *
 * Return: amount.
 */
int sum_listint(listint_t *head)
{
	int amount = 0;

	if (head)
	{
		while (head)
		{
			amount += head->n;
			head = head->next;
		}
	}

	return (amount);
}
