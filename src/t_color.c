#include "t_color.h"

t_color gen_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (t_color){r, g, b, a};
}

int get_color_int(t_color color)
{
	return (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_color get_int_color(int color)
{
	t_color c;

	c.a = color >> 24 & 0xFF;
	c.r = color >> 16 & 0xFF;
	c.g = color >> 8 & 0xFF;
	c.b = color & 0xFF;
	return c;
}
