#include "monty.h"

/**char *globe_val = NULL;
  */
/**
 * get_opcode - trim each line and get the string containing opcode
 * @str: input parameter
 * Return: pointer to opcode string
 
char *get_opcode(char *str)
{
	char *op;
	ssize_t line_read;
	char *line = NULL;
	FILE *file;
	size_t line_length = 0;
	extern char *g_val;

	op = strtok(str, " \t\n");
	if (op != NULL)
	{
		str = str + 1;
		g_val = strtok(NULL, " \t\n");

		line_read = getline(&line, &line_length, file);
		continue;
	}
	return (op);
}
*/

/**
 * main - Entry point
 * @argc: count of input command
 * @argv: pointer to command string
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line, *op;
	size_t line_length;
	ssize_t line_read;
	unsigned int line_number;
	stack_t *stack;
/*	g_val = NULL;
 */

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = NULL;
	line_length = 0;
	line_number = 1;
	stack = NULL;
	line_read = getline(&line, &line_length, file);
	while (line_read != -1)
	{
		op = strtok(line, " \t");
		run_op(op, &stack, line_number);
		line_read = getline(&line, &line_length, file);
		line_number = line_number + 1;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return(EXIT_SUCCESS);
}
