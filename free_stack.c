#include "monty.h"
/**
 * free_stack - a function that frees stack_t stack
 * @head: input parameter of a pointer to the
 * beginning of a stack
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *ptr;
	stack_t *temp;

	ptr = head;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
}
