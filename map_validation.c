/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:54:44 by hskowron          #+#    #+#             */
/*   Updated: 2022/05/27 15:53:34 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_validation(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && game->map[y][x] != ' ')
			{
				check_element(game, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_element(t_game *game, int y, int x)
{
	if (y == 0)
		err_exit("invalid map", game);
	if (y == ft_arrlen(game->map))
		err_exit("invalid map", game);
	if (x == 0 || x == ft_strlen(game->map[y]))
		err_exit("invalid map", game);
	if (game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' ')
		err_exit("invalid map", game);
	if (check_above_row(game->map, y, x) == 1)
		err_exit("invalid map", game);
	if (check_below_row(game->map, y, x) == 1)
		err_exit("invalid map", game);
}

int	check_above_row(char **map, int y, int x)
{
	y--;
	if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		return (1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (1);
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		return (1);
	return (0);
}

int	check_below_row(char **map, int y, int x)
{
	y++;
	if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		return (1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (1);
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		return (1);
	return (0);
}
