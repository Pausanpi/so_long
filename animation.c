#include "include/so_long.h"

int animation(t_game game)
{
	while(game->time < 1000)
		game->time++;
	game->time = 0;
	mlx_destroy_image(game->mlx, game->colect);
	if (game->pos_colect == 1)
		game->img_colect = mlx_xpm_file_to_image(game->mlx,
				"Primera imagen", &game->img_w, &game->img_h);
	else if (game->pos_colect == 2)
		game->img_colect = mlx_xpm_file_to_image(game->mlx,
				"Segunda imagen", &game->img_w, &game->img_h);
	else if (game->pos_colect == 3)
		game->img_colect = mlx_xpm_file_to_image(game->mlx,
				"Tercera imagen", &game->img_w, &game->img_h);
	else if (game->pos_colect == 4)
	{
		game->img_colect = mlx_xpm_file_to_image(game->mlx,
				"Cuarta imagen", &game->img_w, &game->img_h);
		game->pos_colect = 1;
	}
	map_draw(game);
	game->pos_colect++;
	return (0);
}