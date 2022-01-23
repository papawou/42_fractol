#ifndef FRACTAL_H
#define FRACTAL_H

#include "camera.h"
#include "t_mlx.h"

double n_frac(double z_r, double z_i, double c_r, double c_i, int n_max);
void julia(t_img *img, t_cam cam);
void mandelbrot(t_img *img, t_cam cam);

#endif