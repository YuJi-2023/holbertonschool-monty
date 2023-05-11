#include "monty.h"

/**
 * sub - subtracts the top element from the second top element of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
