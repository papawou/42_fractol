#ifndef CAMERA_H
#define CAMERA_H

#define WIDTH 300
#define HEIGHT 200
#define PRESET_MANDEL_X (-2.1 + (0.6 + 2.1)/2.0)

#include "utils.h"

typedef struct s_cam
{
	double	precision;
	t_fvec2	target;
	int			n_iter;
} t_cam;

void reset_camera(t_cam *cam);

#endif