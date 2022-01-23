#include <stdlib.h>

#include "t_img.h"

t_img *new_img(t_mlx mlx, int x, int y)
{
	t_img *img;
	
	img = (t_img *)malloc(sizeof(t_img));
	img->height = y;
	img->width = x;
	img->img = mlx_new_image(mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	return img;
}

t_img *new_xpm_img(t_mlx mlx, char *s)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(mlx, s, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);

	return img;
}

void free_img(t_mlx mlx, t_img *img)
{
	if (img == NULL)
		return ;
	mlx_destroy_image(mlx, img->img);
	free(img);
}

int *img_get_pxl(t_img *img , int x, int y)
{
	return (int *) (img->addr + (img->size_line * y + x * (img->bpp / 8)));
}

void img_set_pxl_color(t_img *img, int x, int y, int color)
{
	*img_get_pxl(img, x, y) = color;
}

void img_put_img(t_img *src, t_img *dst, int dst_x, int dst_y)
{
	int x;
	int y = 0;

	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			img_set_pxl_color(dst, dst_x + x, dst_y + y, *img_get_pxl(src, x, y));
			++x;
		}
		++y;
	}
}