/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:50:44 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/01 19:45:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_mnl(const char *src)
{
	size_t	x;

	x = 0;
	if (!src)
		return (0);
	while (src[x] != '\0' && src[x] != '\n')
	{
		x++;
	}
	return (x);
}
