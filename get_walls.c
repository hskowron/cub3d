#include "cub3d.h"

void	get_no(char *buf, t_game *game)
{
	int	x = 0;

	while (buf[x] == ' ')
		x++;
	if (game->mapInfo->north == NULL)
		game->mapInfo->north = ft_strdup(*buf[x]);
	else
		err_exit("invalid input", game);
}

void	get_so(char *buf, t_game *game)
{
	int	x = 0;

	while (buf[x] == ' ')
		x++;
	if (game->mapInfo->south == NULL)
		game->mapInfo->south = ft_strdup(*buf[x]);
	else
		err_exit("invalid input", game);
}

void	get_we(char *buf, t_game *game)
{
	int	x = 0;

	while (buf[x] == ' ')
		x++;
	if (game->mapInfo->west == NULL)
		game->mapInfo->west = ft_strdup(*buf[x]);
	else
		err_exit("invalid input", game);
}

void	get_ea(char *buf, t_game *game)
{
	int	x = 0;

	while (buf[x] == ' ')
		x++;
	if (game->mapInfo->east == NULL)
		game->mapInfo->east = ft_strdup(*buf[x]);
	else
		err_exit("invalid input", game);
}
