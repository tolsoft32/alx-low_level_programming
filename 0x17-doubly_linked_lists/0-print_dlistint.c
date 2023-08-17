#include "lists.h"

/**
 * print_dlistint - function that print double linked list elements
 * @h: pointer to header of the list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int list_node;

	list_node = 0;
	if (h == NULL)
		return (list_node);
	while (h)
	{
		printf("%d\n", h->n);
		list_node++;
		h = h->next;
	}
	return (list_node);
}
