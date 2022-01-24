#include <stdlib.h>
#include "t_color.h"
#include "utils.h"
t_color lerp_color(t_color a, t_color b, double alpha)
{
	t_color color;

	color.a = lerp(a.a, b.a, alpha);
	color.r = lerp(a.r, b.r, alpha);
	color.g = lerp(a.g, b.g, alpha);
	color.b = lerp(a.b, b.b, alpha);
	return color;
}

t_color get_gradient_color(t_gradient *grad, double alpha)
{
	int i = 0;

	if (grad->len == 1) //one color set
		return grad->colors[0];

	while (i < grad->len && grad->keys[i] < alpha)
		++i;
	
	if (i == 0) //first inter
		return grad->colors[0];
	if (i == grad->len) //last inter
		return grad->colors[grad->len - 1];
	
	return lerp_color(grad->colors[i - 1], grad->colors[i],
		invlerp(grad->keys[i - 1], grad->keys[i], alpha));
}

t_gradient *init_gradient()
{
	t_gradient *grad;

	grad = malloc(sizeof(t_gradient));
	grad->len = 3;

	grad->colors = malloc(sizeof(t_color) * grad->len);
	/*
			grad->colors[0] = get_int_color(0xff12c2e9);
	grad->colors[1] = get_int_color(0xffc471ed);
	grad->colors[2] = get_int_color(0xfff64f59);
	*/
	grad->colors[0] = (t_color){255, 0, 0, 0};
	grad->colors[1] = (t_color){0, 255, 0, 0};
	grad->colors[2] = (t_color){0, 0, 255, 0};
	
	if (grad->len == 1)
		grad->keys = NULL;
	else
	{
		grad->keys = malloc(sizeof(double) * (grad->len));
		grad->keys[0] = 0.0;
		grad->keys[1] = 0.5;
		grad->keys[2] = 1.0;
	}
	return grad;
}

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
