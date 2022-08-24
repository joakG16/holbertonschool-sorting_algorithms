#include "sort.h"

/**
 * swap_nodes - function thar swap nodes and their respective links
 * @node_ant: node before current one
 * @node_act: actual node
 * Return: void
 */

void swap_nodes(listint_t **node_ant, listint_t **node_act)
{
	(*node_act)->prev = (*node_ant)->prev;
	(*node_ant)->next = (*node_act)->next;
	(*node_act)->next = *node_ant;
	(*node_ant)->prev = *node_act;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: double pointer to the first node from the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *node_ant = NULL, *node_act = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	aux = (*list)->next; /* setting aux to 2nd node */
	for (; aux; aux = aux->next)
	{
		node_ant = aux->prev; /* node before the actual to
				       * check values with it
				       */
		node_act = aux; /* current node where we're standing */
		while (node_ant && (node_ant->n > node_act->n))
		{
			swap_nodes(&node_ant, &node_act);
			if (node_ant->next) /* ant is now current, check if
					     * there's something after
					     */
				node_ant->next->prev = node_ant;
			/* afects node after curr., inderectly, from current */
			if (node_act->prev) /* same here, act is in
					     * ant's ex-position
					     */
				node_act->prev->next = node_act;
			else
				*list = node_act;/* in case of moving first node
						* from list, we need to make
						* head pointer to newly
						* rearanged node(new first)
						*/
			print_list(*list);
			node_ant = node_act->prev; /*moving ant to previous new
						    *ant's node, to start with
						    *their "correct" names
						    */
		}
	}
}
