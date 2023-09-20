#include "monty.h"

/**
 * main - Create a program that inteprete the monty
 * bytecode
 * @ac: argument count;
 * @argv: argument vector
 *
 * Return: Always (0) Success
 */

int main(int ac, char **argv)
{
	FILE *file_p;
	stack_t *stack = NULL;
	size_t n = 0;
	ssize_t line_read = 0;
	unsigned int line_count = 0;
	char lines[1024][100], *buf = NULL;


	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_p = fopen(argv[1], "r");
	if (file_p == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_read = getline(&buf, &n, file_p);
		if (line_read == -1)
			break;
		strcpy(lines[line_count], buf);
		line_count++;
	}
	free(buf);
	/*fread(ptr, sizeof(char), 3000, file_p);*/
	fclose(file_p);
	read_file(lines, &stack, line_count);
	free_list(stack);
	return (0);
}
char *op_code[2];
/**
 * read_file - read lines from a file
 * @lines: the content of the file
 * @stack: a double pointer to the first node in the linked list
 * @line_count: the number of lines in the file
 *
 * Return: void
 */
void read_file(char lines[][100], stack_t **stack, unsigned int line_count)
{
	unsigned int line_number = 1, i = 0;

	for (i = 0; i < line_count; i++)
	{
		tokenize_line(lines[i]);
		if (!op_code[0])
		{
			line_number++;
			continue;
		}
		monty_interpreter(line_number, stack);
		line_number++;
	}
}

/**
 * tokenize_line - split lines in words
 * @buf: the line
 *
 * Return: void
 */
void tokenize_line(char *buf)
{
	char *delim = " \n";

	op_code[0] = strtok(buf, delim);
	op_code[1] = strtok(NULL, delim);
}

/**
 * monty_interpreter - interprete opcodes
 * @line_number: line number of the opcodes
 * @stack: a double pointer to the first node in the linked list
 *
 * Return: void
 */
void monty_interpreter(unsigned int line_number, stack_t **stack)
{
	int i = 0;

	instruction_t arr_instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"sub", sub_top1_from_top2},
		{"div", div_top2_by_top1},
		{NULL, NULL}
	};
	for (i = 0; arr_instructions[i].opcode != NULL; i++)
	{
		if ((strcmp(op_code[0], arr_instructions[i].opcode) == 0))
		{
			arr_instructions[i].f(stack, line_number);
			return;
		}
	}
	if ((strcmp(op_code[0], "nop") != 0))
	{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
			line_number, op_code[0]);
	free_list(*stack);
	exit(EXIT_FAILURE);
	}
}

