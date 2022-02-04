#ifndef T_MLX_H
#define T_MLX_H

#include <mlx.h>

typedef void *t_mlx;
typedef void *t_mlx_win;
typedef void *t_mlx_img;

typedef struct s_img
{
	t_mlx_img img;
	char			*addr;
	int				height;
	int				width;
	int				bpp;
	int				size_line;
	int				endian;
} t_img;

#include "t_img.h"

#endif