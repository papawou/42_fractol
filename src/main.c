#include <stdio.h>
#include <unistd.h>
#include <X11/keysymdef.h>

#include "scene.h"
#include "fractal.h"
#include "events.h"
#include "parser.h"

int render(t_scene *sc)
{
	julia(sc->frame, sc->cam);
	//mandelbrot(sc->frame, sc->cam);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->frame->img, 0, 0);
	return 0;
}

int main(int argc, char *argv[])
{
	t_scene sc;

	parse(argc - 1, argv);

	if (init_scene(&sc))
		return 1;
	mlx_hook(sc.win, 17, 0, close_me, &sc);
	mlx_mouse_hook(sc.win, mouse_hook, &sc);
	mlx_key_hook(sc.win, key_hook, &sc);
	mlx_loop_hook(sc.mlx, render, &sc);
	mlx_loop(sc.mlx);

	free_scene(&sc);
	return 0;
}

/*
	add antoher fractal
*/