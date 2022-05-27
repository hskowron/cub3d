/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceil_flo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:39 by hskowron          #+#    #+#             */
/*   Updated: 2022/05/27 14:23:20 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_c(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->ceiling == 0)
		game->map_info->ceiling = get_colours(&buf[x]);
	else
		err_exit("invalid input", game);
	game->map_info->collected++;
}

void	get_f(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->ceiling == 0)
		game->map_info->ceiling = get_colours(&buf[x]);
	else
		err_exit("invalid input", game);
	game->map_info->collected++;
}
