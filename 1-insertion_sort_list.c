#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Insertion
 * sort algorithm
 * @list: the doubly linked list to be sorted
 * Return: void function
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *prev_node = NULL, *next_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;

	while (curr != NULL)
	{
		next_node = curr->next;
		prev_node = curr->prev;

		while (prev_node != NULL && (prev_node)->n > curr->n)
		{
			(prev_node)->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = (prev_node);
			curr->next = prev_node;
			curr->prev = (prev_node)->prev;
			(prev_node)->prev = curr;

			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
			(prev_node) = curr->prev;
		}
		curr = next_node;
	}
}
