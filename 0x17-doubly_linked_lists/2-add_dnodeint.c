#include "lists.h"

/**
 * add_dnodeint - function that add node at the beginning
 * @head: the head of the list
 * @n: the value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *gen_list;
	dlistint_t *h_list;

	gen_list = malloc(sizeof(dlistint_t));
	if (gen_list == NULL)
		return (NULL);

	gen_list->n = n;
	gen_list->prev = NULL;
	h_list = *head;

	if (h_list != NULL)
	{
		while (h_list->prev != NULL)
			h_list = h_list->prev;
	}

	gen_list->next = h_list;

	if (h_list != NULL)
		h_list->prev = gen_list;

	*head = gen_list;

	return (gen_list);
}
