#include "camera.h"

void reset_camera(t_cam *cam)
{
	cam->precision = 0.01;
	cam->n_iter = 50;
	cam->target.x = 0.0;
	cam->target.y = 0.0;
}