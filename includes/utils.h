#ifndef UTILS_H
#define UTILS_H

typedef struct s_fvec2
{
	double x;
	double y;
} t_fvec2;

double lerp(double start, double end, double alpha);
double invlerp(double start, double end, double value);
double remap(double input_a, double input_b, double out_a, double out_b, double value);

#endif