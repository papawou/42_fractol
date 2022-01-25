#include <stdlib.h>
#include "gradient.h"
#include "utils.h"

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

void free_gradient(t_gradient *grad)
{
	if (grad == NULL)
		return ;

	if (grad->keys)
		free(grad->keys);
	if (grad->colors)
		free(grad->colors);
	free(grad);
}

t_gradient *create_gradient()
{
	t_gradient *grad;

	grad = malloc(sizeof(t_gradient));
	grad->len = 5;

	grad->colors = malloc(sizeof(t_color) * grad->len);
	grad->colors[0] = get_int_color(0xff000000);
	grad->colors[1] = get_int_color(0xffff0000);
	grad->colors[2] = get_int_color(0xff00ff00);
	grad->colors[3] = get_int_color(0xff0000ff);
	grad->colors[4] = get_int_color(0xffffffff);
	
	/*
	grad->colors[0] = (t_color){255, 0, 0, 0};
	grad->colors[1] = (t_color){0, 255, 0, 0};
	grad->colors[2] = (t_color){0, 0, 255, 0};
	*/
	if (grad->len == 1)
		grad->keys = NULL;
	else
	{
		grad->keys = malloc(sizeof(double) * (grad->len));
		grad->keys[0] = 0.0;
		grad->keys[1] = 0.25;
		grad->keys[2] = 0.50;
		grad->keys[3] = 0.75;
		grad->keys[4] = 1.0;
	}
	return grad;
}