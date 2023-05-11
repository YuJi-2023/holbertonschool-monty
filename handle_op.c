#include "monty.h"

/**
 * run_op - execute matching operation
 * @op: input parameter
 * @stack: stack to operate
 * @n: input parameter of line_number
 * Return: void
 */
void run_op(char *op, stack_t **stack, unsigned int n)
{
	int i;
	instruction_t opfunc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	i = 0;
	while (opfunc[i].opcode != NULL)
	{
		if (strcmp(op, opfunc[i].opcode) == 0)
		{
			opfunc[i].f(stack, n);
			return;
		}
		i = i + 1;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", n, op);
	exit(EXIT_FAILURE);
}
