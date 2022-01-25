#ifndef GRADIENT_H
#define GRADIENT_H

#include "color.h"

typedef struct s_gradient
{
	int len;
	double	*keys;
	t_color *colors;
} t_gradient;

void free_gradient(t_gradient *grad);
t_color get_gradient_color(t_gradient *grad, double alpha);
t_gradient *create_gradient();

#endif