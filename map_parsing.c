#include "cub3d.h"

void	init_mapInfo(t_mapInfo *mapInfo)
{
	mapInfo->north = NULL;
	mapInfo->east = NULL;
	mapInfo->west = NULL;
	mapInfo->south = NULL;
	mapInfo->floor = 0;
	mapInfo->ceiling = 0;
	mapInfo->collected = 0;
}

/*
**	parsing:
**	we move through our input file wit gnl and keep checking every non-empty line, assign that value to our map attributes
**	we only move on if we have filled out all the neccessary attributes, if one or more are missing we exit with an error
**	
*/

void	parsing(int fd, t_game *game)
{
	char	*buf;
	int		x;

	x = 0;
	buf = get_next_line(fd);
	while (buf && game->mapInfo->collected < 6)
	{
		if (buf[x] != '\0')
		{
			while (buf[x] == ' ')
				x++;
			check_ele(*buf[x], game)
		}
		buf = get_next_line(fd);
		x = 0;
		game->map_start++;
	}
	if (!buf && game->mapInfo->collcted < 6)
		err_exit("invalid input", game);
	parsing_on(fd, game, buf);
}

void	parsing_on(int fd, t_game *game, char *buf)
{
	int		x;

	x = 0;
	while (buf)
	{
		if (buf[x])
		{
			while (buf[x] == ' ')
				x++;
			if (buf[x])
				copy_map(buf, fd, game);
		}
		buf = get_next_line(fd);
		x = 0;
		game->map_start++;
	}
}

/*
**	check_ele:
**	we check our current line if it has one of our attributes we are looking for
*/

void	check_ele(char *buf, t_game *game)
{
	if (ft_strncmp(buf, "NO ", 3) == 0)
		get_no(buf + 2, game;
	else if (ft_strncmp(buf, "SO ", 3) == 0)
		get_so(buf + 2, game)
	else if (ft_strncmp(buf, "WE ", 3) == 0)
		get_we(buf + 2, game);
	else if (ft_strncmp(buf, "EA ", 3) == 0)
		get_ea(buf + 2, game);
	else if (ft_strncmp(buf, "F ", 2) == 0)
		get_f(buf + 1, game);
	else if (ft_strncmp(buf, "C ", 2) == 0)
		get_c(buf + 1, game);
}



void	copy_map(char *buf, int fd, t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->map = malloc(sizeof(char *) * (2 + count_lines(game->map_path) - game->map_start));
	if (!map)
		err_exit("malloc error", game);
	while (buf)
	{
		if (buf[x] != '\0')
		{
			game->map[y] = ft_strdup(buf);
			y++;
		}
		buf = get_next_line(fd);
	}
}
