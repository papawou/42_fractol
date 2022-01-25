#include <stdlib.h>
#include "scene.h"

int init_scene(t_scene *sc)
{
	sc->mlx = mlx_init();
	if (sc->mlx == NULL)
		return 1;
	sc->win = mlx_new_window(sc->mlx, WIDTH, HEIGHT, "fractal");
	if (sc->win == NULL)
		return 1;
	sc->frame = new_img(sc->mlx, WIDTH, HEIGHT);
	if (sc->frame == NULL)
		return 1;
	sc->cam.grad = create_gradient();
	if(sc->cam.grad == NULL)
	{
		free_img(sc->mlx, sc->frame);
		return 1;
	}
	reset_camera(&sc->cam);
	return 0;
}

void free_scene(t_scene *sc)
{
	if (sc == NULL)
		return ;
	free_gradient(sc->cam.grad);
	free_img(sc->mlx, sc->frame);
}