/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:49:25 by hskowron          #+#    #+#             */
/*   Updated: 2022/05/27 13:50:58 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	placeholder, need to free and handle messages correctly
*/

void	err_exit(char *msg, t_game *game)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
