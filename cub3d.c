/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:55 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/26 18:31:54 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_input(int fd, t_game *game, char **argv)
{
	char	**file;
	char	*str;
	int		i;

	i = 0;
	file = malloc((count_lines(argv) + 1) * sizeof(char *));
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		file[i] = str;
		i++;
	}
	// for (int j = 0; j < count_lines(argv); j++)
	// {
	// 	printf("%s", file[j]);
	// }
	// printf("\n");
	// printf("%i\n%i\n", count_lines(argv), i);
	file[i] = NULL;
	use_cub(game, file);
	free2d(file);
	return ;
}

void	use_cub(t_game *game, char **file)
{
	// get_map(game, file);
	get_north(game, file);
	get_south(game, file);
	get_east(game, file);
	get_west(game, file);
	get_ceiling(game, file);
	get_floor(game, file);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*check;
	t_game	game;

	if (argc != 2)
	{
		printf("Error\ninvalid input\n");
		// exit(EXIT_FAILURE);
	}
	game.mapInfo = malloc(sizeof(t_mapInfo));
	game.map_path = ft_strdup(argv[1]);
	game.map_start = 1;
	if (!game.mapInfo)
		exit(EXIT_FAILURE);
	init_mapInfo(game.mapInfo);
	check = ft_substr(argv[1], ft_strlen(argv[1] - 4), 4);
	if (ft_strncmp(check, ".cub", 4))
	{
		printf("Error\nno .cub extension\n");
		free(check);
		exit(EXIT_FAILURE);
	}
	free(check);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\ninvalid map\n");
		exit(EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	game.wdth = 64;
	game.hght = 64; 
	parsing(fd, &game);
	// take_input(fd, &game, argv);
	game.win = mlx_new_window(game.mlx, game.wdth * 8, game.hght * 8, "cub3d");
	wip_stuff(&game, argv);
	mlx_loop(game.mlx);
	return (0);
}
