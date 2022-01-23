#ifndef T_IMG_H
#define T_IMG_H

#include "t_mlx.h"

t_img *new_img(t_mlx mlx, int x, int y);
void free_img(t_mlx mlx, t_img *img);
int		*img_get_pxl(t_img *img , int x, int y);
void	img_set_pxl_color(t_img *img, int x, int y, int color);
t_img *new_xpm_img(t_mlx mlx, char *s);
void img_put_img(t_img *src, t_img *dst, int dst_x, int dst_y);

#endif