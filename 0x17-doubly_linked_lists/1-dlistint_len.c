#include "lists.h"

/**
 * dlistint_len - function that return the element in double linked list
 * @h: pointer to the head
 * Return: the number of element in the linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int list_node;

	list_node = 0;
	if (h == NULL)
		return (list_node);
	while (h)
	{
		list_node++;
		h = h->next;
	}
	return (list_node);
}
