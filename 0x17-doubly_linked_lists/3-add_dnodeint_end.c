#include "lists.h"

/**
 * add_dnodeint_end - function that node at the end of linked list
 * @head:  pointer to the head
 * @n: value of the elements
 * Return: The address of new elements
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h_list;
	dlistint_t *gen_list;

	gen_list = malloc(sizeof(dlistint_t));
	if (gen_list == NULL)
		return (NULL);

	gen_list->n = n;
	gen_list->next =  NULL;

	h_list = *head;
	if (h_list != NULL)
	{
		while (h_list->next != NULL)
			h_list = h_list->next;
		h_list->next = gen_list;
	}
	else
	{
		*head = gen_list;
	}

	gen_list->prev = h_list;

	return (gen_list);
}
