#include <stdio.h>
#include <unistd.h>
#include <X11/keysymdef.h>

#include "t_scene.h"
#include "fractal.h"

int render(t_scene *sc)
{
	static t_img *frame = NULL;

	if (frame == NULL)
		frame = new_img(sc->mlx, WIDTH, HEIGHT);
	
	mandelbrot(frame, sc->cam);
	mlx_put_image_to_window(sc->mlx, sc->win, frame->img, 0, 0);
	return 0;
}

int mouse_hook(int button, int x, int y, t_scene *sc)
{
	sc->cam.target.x += remap(0, WIDTH, -WIDTH/2, WIDTH/2, x) * sc->cam.precision;
	sc->cam.target.y -= remap(0, HEIGHT, -HEIGHT/2, HEIGHT/2, y) * sc->cam.precision;
	
	if (button == 4)
		sc->cam.precision *= 0.99;
	else	if(button == 5)
		sc->cam.precision *= 1.01;

	return 0;
}

int key_hook(int code, t_scene *sc)
{

	if (code == 0xff52)
		sc->cam.target.y += sc->cam.precision;
	else if (code == 0xff54)
		sc->cam.target.y -= sc->cam.precision;
	else if (code == 0xff51)
		sc->cam.target.x -= sc->cam.precision;
	else if (code == 0xff53)
		sc->cam.target.x += sc->cam.precision;
	else if (code == 0xffab)
		sc->cam.precision *= 0.99;
	else if (code == 0xffad)
		sc->cam.precision *= 1.01;
	else if (code == 0xffaa)
		++sc->cam.n_iter;
	else if (code == 0xffaf && sc->cam.n_iter > 1)
		--sc->cam.n_iter;
	else if (code == 0x20)
		reset_camera(&sc->cam);
	return 0;
}

int main()
{
	t_scene sc;

	sc.mlx = mlx_init();
	sc.win = mlx_new_window(sc.mlx, WIDTH, HEIGHT, "fractal");
	sc.cam.grad = init_gradient();
	reset_camera(&sc.cam);

	mlx_mouse_hook(sc.win, mouse_hook, &sc);
	mlx_key_hook(sc.win, key_hook, &sc);
	mlx_loop_hook(sc.mlx, render, &sc);
	mlx_loop(sc.mlx);
	return 0;
}

/*
todo
	mulitple gradients

	cmd subject controls
	add antoher fractal
*/