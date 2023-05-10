#include "monty.h"
/**
  * _is_valid_intstr - check is a string is valid to convert to an int
  * @str: string to be checked
  * Return: pointer to a valid str or NULL if not
  */
char *_is_valid_intstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i = i + 1;
		}
		if (isdigit(str[i]) == 0)
		{
			return (NULL);
		}
		i = i + 1;
	}
	return (str);
}

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

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	token_val = strtok(NULL, " \t\n");
	if (token_val == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (_is_valid_intstr(token_val) == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token_val);
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
