#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inset nodes at index
 * @h: pointer to head of the link list
 * @idx: the position of the newly inserted node
 * @n: container that will contain the new integer
 * Return: NULL if it work, otherwise address of new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *gen_list;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
	}

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	gen_list = malloc(sizeof(dlistint_t));
	if (gen_list == NULL)
		return (NULL);

	gen_list->n = n;
	gen_list->prev = temp;
	gen_list->next = temp->next;
	temp->next->prev = gen_list;
	temp->next = gen_list;

	return (gen_list);
}
