#include "monty.h"

/**
 * main - Create a program that inteprete the monty
 * bytecode
 * @ac: argument count;
 * @argv: argument vector
 *
 * Return: Always (0) Success
 */
char *op_code[2];

int main(int ac, char **argv)
{
	FILE *file_p;
	stack_t *stack = NULL;
	/*size_t read_count;*/
	char ptr[3000] = {'\0'};

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
	fread(ptr, sizeof(char), 3000, file_p);
	fclose(file_p);
	read_file(ptr, &stack);
	free_list(stack);
	return (0);
}
/**
 * read_file - read lines from a file
 * @ptr: the content of the file
 * @stack: a double pointer to the first node in the linked list
 *
 * Return: void
 */
void read_file(char *ptr, stack_t **stack)
{
	char *line_from_file;
	unsigned int line_number = 1;
	char str [1024] = {'\0'};
	int i = 0;
	
	line_from_file = strtok(ptr, "\n");
	while (1)
	{
		if (i != 0)
			line_from_file = strtok(NULL, "\n");
		if (line_from_file == NULL)
			break;
		strcpy(str, line_from_file);
		tokenize_line(str);
		if (!op_code[0])
			continue;
		monty_interpreter(line_number, stack);
		line_number++;
		i++;

	}
	/*free(buf);
	buf = NULL;
	*/
}
/**
 * tokenize_line - split lines in words
 * @buf: the line
 *
 * Return: void
 */
void tokenize_line(char *buf)
{
	char *delim = " ";

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
		{NULL, NULL}
	};
	for (i = 0; arr_instructions[i].opcode != NULL; i++)
	{
		if ((_strcmp(op_code[0], arr_instructions[i].opcode) == 0))
		{
			arr_instructions[i].f(stack, line_number);
			return;
		}
	}
	if ((_strcmp(op_code[0], "nop") != 0))
	{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
			line_number, op_code[0]);
	free_list(*stack);
	exit(EXIT_FAILURE);
	}
}

