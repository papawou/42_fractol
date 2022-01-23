#ifndef T_SCENE_H
#define T_SCENE_H

#include "t_mlx.h"
#include "camera.h"
#include "t_color.h"

typedef struct s_scene
{
	t_mlx mlx;
	t_mlx_win win;
	
	t_cam cam;
} t_scene;

#endif