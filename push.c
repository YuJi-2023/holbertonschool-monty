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
	char *token_val;
	int value;
	stack_t *tmp;

	token_val = strtok(NULL, " \t");
	value = atoi(token_val);
	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		free(tmp);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		/**fprintf(stderr, "Error: malloc failed\n");*/
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
