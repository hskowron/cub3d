/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:58:22 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/24 12:25:01 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wip_stuff(t_game *game, char **argv)
{
	int i = 0;
	int	j = 0;
	int fd = open(argv[2], O_RDONLY);
	game->map = malloc(9 * sizeof(char *));
	game->map[8] = NULL;
	while (i < 8)
	{
		game->map[i] = get_next_line(fd);
		game->map[i] = ft_substr(game->map[i] , 0, ft_strlen(game->map[i]) - 1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	i = 0;
	game->player = mlx_xpm_file_to_image(game->mlx, "./workxpm/player.xpm",
			&game->wdth, &game->hght);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./workxpm/floor.xpm",
			&game->wdth, &game->hght);
	while (i < 8)
	{
		while (j < 8)
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->north, j * 64, i * 64);
			}
			if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor, j * 64, i * 64);
			}
			if (game->map[i][j] == 'W')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor, j * 64, i * 64);
				mlx_put_image_to_window(game->mlx, game->win, game->player, j * 64 + 16, i * 64 + 16);
				float y = 0;
				for (float x = 0; x < 800; x+= 1)
				{
					mlx_pixel_put (game->mlx, game->win, j * 64 + 32 + x, i * 64 + 32 + y, game->floor_c);
					y = sin(20) * x + cos(20) * y;
				}
				for (float x = 0; x < 800; x+= 1)
				{
					mlx_pixel_put (game->mlx, game->win, j * 64 + 32 + x, i * 64 + 32, game->floor_c);
				}
				y = 0;
				for (float x = 0; x < 800; x+= 1)
				{
					mlx_pixel_put (game->mlx, game->win, j * 64 + 32 + x, i * 64 + 32 + y, game->floor_c);
					y = sin(30) * x + cos(30) * y;
				}
				y = 0;
				for (float x = 0; x < 8000; x+= 1)
				{
					mlx_pixel_put (game->mlx, game->win, j * 64 + 32 + x, i * 64 + 32 + y, game->floor_c);
					y = sin(10) * x + cos(10) * y;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

