#include "monty.h"

/**
 * push - pushes an element to the the top of stack
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	extern char *globe_val;
	stack_t *tmp;

	if (globe_val != NULL)
	{
		value = atoi(globe_val);
	}
	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		free(tmp);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp->n = value;
	tmp->prev = NULL;
	tmp->next = *stack;	
	if (*stack != NULL)
	{
		(*stack)->prev = tmp;
	}
	*stack = tmp;
}
