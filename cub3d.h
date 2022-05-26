/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:26 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/26 18:30:06 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "minilibx/mlx.h"

# define pi 3.14159265359

typedef struct s_or {
	float x;
	float y;
}				t_or;

// struct um beim parsen alles zu speichern
typedef struct s_mapInfo
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
	int		collected;
}				t_mapInfo;

typedef struct s_game {
	int		map_start;
	char	*map_path;
	t_mapInfo	*mapInfo;
	char	**map;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*player;
	int		ceiling_c;
	int		floor_c;
	void	*win;
	void	*mlx;
	int		hght;
	int		wdth;
	t_or	*or;
	float	degree;
	/* wip stuff */
	void	*floor;
}				t_game;

/* R,G,B functions */
int		create_rgb(int r, int g, int b);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);

/* utils */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		count_lines(char **argv);
int		ft_atoi(const char *str);

/* gnl utils */
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		ft_assign(int readl, char **str, char *buf, int fd);
char	*ft_getline(char **str, int fd);

/* filling variables */
void	use_cub(t_game *game, char **file);

/* getting wall images */
void	get_north(t_game *game, char **file);
void	get_south(t_game *game, char **file);
void	get_east(t_game *game, char **file);
void	get_west(t_game *game, char **file);

/* getting ceiling/floor colours */
void	get_ceiling(t_game *game, char **file);
void	get_floor(t_game *game, char **file);
int		get_colours(char *str);

/* free functions */
void	free2d(char **str);

/* wip stuff */
void	wip_stuff(t_game *game, char **argv);

#endif