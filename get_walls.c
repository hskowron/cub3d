/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:48 by hskowron          #+#    #+#             */
/*   Updated: 2022/05/27 14:31:29 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_no(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->north == NULL)
		game->map_info->north = ft_strdup_mnl(&buf[x]);
	else
		err_exit("invalid input", game);
	game->map_info->collected++;
}

void	get_so(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->south == NULL)
		game->map_info->south = ft_strdup_mnl(&buf[x]);
	else
		err_exit("invalid input", game);
	game->map_info->collected++;
}

void	get_we(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->west == NULL)
		game->map_info->west = ft_strdup_mnl(&buf[x]);
	else
		err_exit("invalid input", game);
	game->map_info->collected++;
}

void	get_ea(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->east == NULL)
		game->map_info->east = ft_strdup_mnl(&buf[x]);
	else
		err_exit("invalid input", game);
	game->map_info->collected++;
}
