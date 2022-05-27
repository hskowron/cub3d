/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:55:04 by hskowron          #+#    #+#             */
/*   Updated: 2022/05/27 15:41:13 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->north = NULL;
	map_info->east = NULL;
	map_info->west = NULL;
	map_info->south = NULL;
	map_info->floor = 0;
	map_info->ceiling = 0;
	map_info->collected = 0;
}

/*
**	parsing:
**	we move through our input file wit gnl and keep checking every non-empty line, assign that value to our map attributes
**	we only move on if we have filled out all the neccessary attributes, if one or more are missing we exit with an error
*/

void	parsing(int fd, t_game *game)
{
	char	*buf;
	int		x;

	x = 0;
	buf = get_next_line(fd);
	while (buf && game->map_info->collected < 6)
	{
		if (buf[x] != '\0' || buf[x] != '\n')
		{
			while (buf[x] == ' ')
				x++;
			check_ele(&buf[x], game);
		}
		free(buf);
		buf = get_next_line(fd);
		x = 0;
		game->map_start++;
	}
	if (!buf && game->map_info->collected < 6)
		err_exit("invalid input", game);
	parsing_on(fd, game, buf);
}

/*
**	parsing_on:
**	at this point we have all 6 attributes filled, so we move through our file until we find the first line of the actual map
**	we skip whitespace in every line, if there is then any other character in the line we have found the map
**	if we reach EOF before we found the map we will exit with an error
*/

void	parsing_on(int fd, t_game *game, char *buf)
{
	int		x;

	x = 0;
	while (buf)
	{
		if (buf[0] != '\0' && buf[0] != '\n')
		{
			while (buf[x] == ' ')
				x++;
			if (buf[x])
			{
				copy_map(buf, fd, game);
				return ;
			}
		}
		free(buf);
		buf = get_next_line(fd);
		x = 0;
		game->map_start++;
	}
	err_exit("invalid input", game);
}

/*
**	check_ele:
**	we check our current line if it has one of our attributes we are looking for
*/

void	check_ele(char *buf, t_game *game)
{
	if (ft_strncmp(buf, "NO ", 3) == 0)
		get_no(buf + 2, game);
	else if (ft_strncmp(buf, "SO ", 3) == 0)
		get_so(buf + 2, game);
	else if (ft_strncmp(buf, "WE ", 3) == 0)
		get_we(buf + 2, game);
	else if (ft_strncmp(buf, "EA ", 3) == 0)
		get_ea(buf + 2, game);
	else if (ft_strncmp(buf, "F ", 2) == 0)
		get_f(buf + 1, game);
	else if (ft_strncmp(buf, "C ", 2) == 0)
		get_c(buf + 1, game);
}

/*
**	copy_map:
**	we copy the rest of the file into a 2d-array, which should give us the entire map, ready to be validated
*/

void	copy_map(char *buf, int fd, t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->map = malloc(sizeof(char *) * (2 + count_lines(game->map_path)
				- game->map_start));
	if (!game->map)
		err_exit("malloc error", game);
	while (buf)
	{
		if (buf[x] != '\0')
		{
			game->map[y] = ft_strdup_mnl(buf);
			y++;
		}
		game->map[y] = NULL;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
}
