#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - Add a new node at the beginning of a linked list
 * @head: The head of a linked list
 * @n: The value to add to the new node.
 *
 * Return: The address of the new elements, or NULL if failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_list;

	if (head != NULL)
	{
		new_list = malloc(sizeof(listint_t));
		if (new_list == NULL)
			return (NULL);

		new_list->n = n;
		new_list->next = *head;
		*head = new_list;

		return (new_list);
	}

	return (NULL);
}
