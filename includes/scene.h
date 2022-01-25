#ifndef T_SCENE_H
#define T_SCENE_H

#include "t_mlx.h"
#include "camera.h"
#include "color.h"

typedef struct s_scene
{
	t_mlx mlx;
	t_mlx_win win;
	t_img *frame;

	t_cam cam;
} t_scene;

void free_scene(t_scene *sc);
int init_scene(t_scene *sc);

#endif