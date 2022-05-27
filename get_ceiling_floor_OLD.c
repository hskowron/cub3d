/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceiling_floor_OLD.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:50:56 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/27 14:18:39 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_ceiling(t_game *game, char **file)
// {
// 	int i;
// 	int	j;
// 	char *str;
// 	char *tmp;

// 	j = 2;
// 	i = 0;
// 	while (ft_strncmp(file[i], "C", 1) && file[i])
// 		i++;
// 	if (!file[i])
// 	{
// 		printf("Error\nno colour included\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (file[i][j] == ' ')
// 		j++;
// 	str = ft_substr(file[i], j, (ft_strlen(file[i]) - j));
// 	if (str[ft_strlen(str) - 1] == '\n')
// 	{
// 		tmp = str;
// 		str = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
// 		free(tmp);
// 	}
// 	game->ceiling_c = get_colours(str);
// }

// void	get_floor(t_game *game, char **file)
// {
// 	int i;
// 	int	j;
// 	char *str;
// 	char *tmp;

// 	j = 2;
// 	i = 0;
// 	while (ft_strncmp(file[i], "F", 1) && file[i])
// 		i++;
// 	if (!file[i])
// 	{
// 		printf("Error\nno colour included\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (file[i][j] == ' ')
// 		j++;
// 	str = ft_substr(file[i], j, (ft_strlen(file[i]) - j));
// 	if (str[ft_strlen(str) - 1] == '\n')
// 	{
// 		tmp = str;
// 		str = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
// 		free(tmp);
// 	}
// 	game->floor_c = get_colours(str);
// }

int	get_colours(char *str)
{
	int i;
	int	j;
	int k;
	char **colours;

	i = 0;
	k = 0;
	colours = malloc(sizeof(char *) * 4);
	colours[3] = NULL;
	while (str[i] && k < 3)
	{
		j = 0;
		while(str[i] == ',' || str[i] == ' ')
			i++;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		colours[k] = ft_substr(str, i, j);
		i = i + j;
		k++;
	}
	j = create_rgb(ft_atoi(colours[0]),ft_atoi(colours[1]),ft_atoi(colours[2]));
	free2d(colours);
	return (j);
}