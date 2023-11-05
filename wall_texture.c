#include "include/so_long.h"

static int random1to5() {
    return (rand() % 5) + 1;
}

//si no se generan las imagenes añadir como en el init e inicializar todos estas texturas ahí y luego añadirlo aquí
static void draw_element(t_game *game, int x, int y, int random)
{
	if (random == '1')
		mlx_put_image_to_window(game->mlx, game->win, "Sprites/ambar.xpm", x * 32, y * 32);
	else if (random == '2')
		mlx_put_image_to_window(game->mlx, game->win, "Sprites/caracola.xpm", x * 32, y * 32);
	else if (random == '3')
		mlx_put_image_to_window(game->mlx, game->win, "Sprites/crystal.xpm", x * 32, y * 32);
	else if (random == '4')
		mlx_put_image_to_window(game->mlx, game->win, "Sprites/thing.xpm", x * 32, y * 32);
	else if (random == '5')
		mlx_put_image_to_window(game->mlx, game->win, "Sprites/thing2.xpm", x * 32, y * 32);

}

//si la x o la y es 0 indica que es un muro
//si la x o la y es la long maxima indica que es un muro
//necesito saber la long maxima de altura y anchura para saber dos de los muros

static bool extreme(t_game *game, int x, int y)
{
	if (game->map[y + 1][x] != '\0' || game->map[y][x + 1] = '\0' || x == '0' || y == '0')   //creo que está bien, pero si falla mirar si puede ser que el orden de la x e y esté al revés
		return (true);
	return (false);
}

void wall_texture(t_game *game, int x, int y)
{
	int	r;

	r = random1to5();
	if (!extreme(game, x, y)) //si no es un extremo
		draw_element(game, x, y, r);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 32, y * 32);
}
