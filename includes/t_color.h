#ifndef T_COLOR_H
#define T_COLOR_H

typedef struct s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} t_color;

int get_color_int(t_color color);
t_color get_int_color(int color);

#endif