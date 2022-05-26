/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:37:10 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/18 13:52:45 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_north(t_game *game, char **file)
{
	int i;
	int	j;
	char *str;
	char *tmp;

	j = 2;
	i = 0;
	while (ft_strncmp(file[i], "NO", 2) && file[i])
		i++;
	if (!file[i])
	{
		printf("Error\nno path included\n");
		exit(EXIT_FAILURE);
	}
	while (file[i][j] == ' ')
		j++;
	str = ft_substr(file[i], j, (ft_strlen(file[i]) - j));
	if (str[ft_strlen(str) - 1] == '\n')
	{
		tmp = str;
		str = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	if (open(str, O_RDONLY) < 0)
	{
		printf("Error\ncouldn't open path to image\n");
		exit(EXIT_FAILURE);
	}
	game->north = mlx_xpm_file_to_image(game->mlx, str,
			&game->wdth, &game->hght);
}

void	get_south(t_game *game, char **file)
{
	int i;
	int	j;
	char *str;
	char *tmp;

	j = 2;
	i = 0;
	while (ft_strncmp(file[i], "SO", 2) && file[i])
		i++;
	if (!file[i])
	{
		printf("Error\nno path included\n");
		exit(EXIT_FAILURE);
	}
	while (file[i][j] == ' ')
		j++;
	str = ft_substr(file[i], j, (ft_strlen(file[i]) - j));
	if (str[ft_strlen(str) - 1] == '\n')
	{
		tmp = str;
		str = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	if (open(str, O_RDONLY) < 0)
	{
		printf("Error\ncouldn't open path to image\n");
		exit(EXIT_FAILURE);
	}
	game->south = mlx_xpm_file_to_image(game->mlx, str,
			&game->wdth, &game->hght);
}

void	get_east(t_game *game, char **file)
{
	int i;
	int	j;
	char *str;
	char *tmp;

	j = 2;
	i = 0;
	while (ft_strncmp(file[i], "EA", 2) && file[i])
		i++;
	if (!file[i])
	{
		printf("Error\nno path included\n");
		exit(EXIT_FAILURE);
	}
	while (file[i][j] == ' ')
		j++;
	str = ft_substr(file[i], j, (ft_strlen(file[i]) - j));
	if (str[ft_strlen(str) - 1] == '\n')
	{
		tmp = str;
		str = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	if (open(str, O_RDONLY) < 0)
	{
		printf("Error\ncouldn't open path to image\n");
		exit(EXIT_FAILURE);
	}
	game->east = mlx_xpm_file_to_image(game->mlx, str,
			&game->wdth, &game->hght);
}

void	get_west(t_game *game, char **file)
{
	int i;
	int	j;
	char *str;
	char *tmp;

	j = 2;
	i = 0;
	while (ft_strncmp(file[i], "WE", 2) && file[i])
		i++;
	if (!file[i])
	{
		printf("Error\nno path included\n");
		exit(EXIT_FAILURE);
	}
	while (file[i][j] == ' ')
		j++;
	str = ft_substr(file[i], j, (ft_strlen(file[i]) - j));
	if (str[ft_strlen(str) - 1] == '\n')
	{
		tmp = str;
		str = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	if (open(str, O_RDONLY) < 0)
	{
		printf("Error\ncouldn't open path to image\n");
		exit(EXIT_FAILURE);
	}
	game->west = mlx_xpm_file_to_image(game->mlx, str,
			&game->wdth, &game->hght);
}