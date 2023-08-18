#include "lists.h"

/**
 * free_dlistint - function to free list
 * @head: pointer to the head of the list
 * Return: return nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
