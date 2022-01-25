#ifndef EVENTS_H
#define EVENTS_H

#include "scene.h"

int mouse_hook(int button, int x, int y, t_scene *sc);
int key_hook(int code, t_scene *sc);
int close_me(t_scene *sc);

#endif