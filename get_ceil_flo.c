#include "cub3d.h"

void	get_c(char *buf, t_game *game)
{
	int	x = 0;

	while (buf[x] == ' ')
		x++;
	if (game->mapInfo->ceiling == NULL)
		game->mapInfo->ceiling = get_colours(*buf[x]);
	else
		err_exit("invalid input", game);
}
void	get_f(char *buf, t_game *game)
{
	int	x = 0;

	while (buf[x] == ' ')
		x++;
	if (game->mapInfo->ceiling == NULL)
		game->mapInfo->ceiling = get_colours(*buf[x]);
	else
		err_exit("invalid input", game);
}
