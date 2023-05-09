#include "monty.h"

extern char *globe_val = NULL;
/**
 * get_opcode - trim each line and get the string containing opcode
 * @str: input parameter
 * Return: pointer to opcode string
 */
char *get_opcode(char *str)
{
	char *op;
/*	extern char *globe_val;
*/
	op = strtok(str, " \t\n");
	while (op != NULL)
	{
		globe_val = strtok(NULL, " \t\n");
	}
	return (op);
}

/**
 * main - Entry point
 * @argc: count of input command
 * @argv: pointer to command string
 * Return: void
 */
void main(int argc, char *argv[])
{
	FILE *file;
	char *line, *op;
	size_t line_length;
	ssize_t line_read;
	unsigned int line_number;
	stack_t *stack;

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
	printf("file 00.m opened successfully\n");
	line = NULL;
	line_length = 0;
	line_number = 0;
	stack = NULL;
	line_read = getline(&line, &line_length, file);
	while (line_read != -1)
	{
		line_number = line_number + 1;
		op = get_opcode(line);
		if (op != NULL)
		{
			run_op(op, &stack, line_number);
		}
		line_number = line_number + 1;
		line_read = getline(&line, &line_length, file);
	}
	free(line);
	/**need to free stack
	 */
	fclose(file);
	return;
}
