#include "monty.h"

/**
 * main - read monty file
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
		op = strtok(line, " \t\n");
		if (op == NULL)
		{
			line_number = line_number + 1;
			line_read = getline(&line, &line_length, file);
			continue;
		}
		run_op(op, &stack, line_number);
		line_read = getline(&line, &line_length, file);
		line_number = line_number + 1;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
