#include "monty.h"

/**
 * pall - prints all values on the stack, starting from the top of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
