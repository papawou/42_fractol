#ifndef CAMERA_H
#define CAMERA_H

#define WIDTH 1900
#define HEIGHT 1000
#define PRESET_MANDEL_X (-2.1 + (0.6 + 2.1)/2.0)

#include "utils.h"
#include "t_color.h"

typedef struct s_cam
{
	double	precision;
	t_fvec2	target;
	int			n_iter;
	t_gradient *grad;
} t_cam;

void reset_camera(t_cam *cam);

#endif