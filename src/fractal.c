#include "fractal.h"
#include "gradient.h"

double n_frac(double z_r, double z_i, double c_r, double c_i, int n_max)
{
	int n = 0;
	double tmp_r;

	while (n < n_max)
	{
		tmp_r = ((z_r * z_r) - (z_i * z_i)) + c_r;
		z_i = ((z_r * z_i) + (z_i * z_r)) + c_i;
		z_r = tmp_r;
		if ((z_r * z_r + z_i * z_i) >= 4.0)
			return ((double)n / n_max);
		++n;
	}
	return 1.0;
}

void julia(t_img *img, t_cam cam)
{
	double c_r = -0.2;
	double c_i = 0.5;

	double y_min = cam.target.y - (cam.precision * HEIGHT / 2);
	double x_min = cam.target.x - (cam.precision * WIDTH / 2);

	double n_percent;
	int x = 0;
	int y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			n_percent = n_frac(x_min + x * cam.precision, y_min + y * cam.precision, c_r, c_i, cam.n_iter);
			img_set_pxl_color(img, x, HEIGHT - 1 - y, get_color_int(get_gradient_color(cam.grad, n_percent)));
			++y;
		}
		++x;
	}
}

void mandelbrot(t_img *img, t_cam cam)
{
	double y_min = cam.target.y - (cam.precision * HEIGHT / 2);
	double x_min = cam.target.x - (cam.precision * WIDTH / 2);
	double n_percent;
	int x = 0;
	int y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			n_percent = n_frac(0, 0, x_min + x * cam.precision, y_min + y * cam.precision, cam.n_iter);
			img_set_pxl_color(img, x, HEIGHT - 1 - y, get_color_int(get_gradient_color(cam.grad, n_percent)));
			++y;
		}
		++x;
	}
}