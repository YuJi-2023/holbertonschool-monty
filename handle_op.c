#include "monty.h"
/** check_op - check if contains valid opcode
 * @str: input parameter to be checked
 * Return: valid opcode or NULL if not
 *
char *check_op(char *str)
{

}
*/

/** run_op - execute matching operation
 * @op: input parameter
 * @stack: stack to operate
 * @line_number: input parameter
 * Return: void
 */
void run_op(char *op, stack_t **stack, unsigned int n)
{
	int i;
	instruction_t opfunc[] = {
		{"push", push},
		{"pall", pall},
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
	fprintf(stderr, "L%u:unknown instruction %s\n", n, op);
	exit(EXIT_FAILURE);
}
