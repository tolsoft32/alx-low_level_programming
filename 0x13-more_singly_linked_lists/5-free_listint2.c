#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - ignore data type by making it void
 * @head: pointing address of temp
 *
 * Return: any data type declared
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head)
	{
		while (*head)
		{
			temp = (*head);
			*head = (*head)->next;
			free(temp);
		}
	}
	else
	{
		return;
	}

	free(*head);
	head = 0;
}
