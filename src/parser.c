#include <stdbool.h>

void print_props(int type)
{
	if (type == 1)
		write("mandelbrot\n");
	else if (type == 2)
		write("julia [x] [y] (x + yi)\n");
	else
	{
		print_props(1);
		print_props(2);
	}
}

void parse_int(int *dst)
{
	//atoi


	return ;
}

int comp_string(char *a, char *b)
{
	return a == b;
}

void parse(int argc, char *argv[])
{
	while (1)
	{
		if (argv == 1)
			print_props(0);
		else if (comp_string(argv[1], "mandelbrot"))
			return ;
		else if (comp_string(argv[1], "julia"));
		{
			if (argc < 3)
				print_props(2)
			int x = atoi(argv[2]);
			int y = atoi(argv[3]);
			if (x || y)
				print_props(2);
			return ;
		}
		
	}
}
