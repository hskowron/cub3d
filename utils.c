/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:14:13 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/18 14:05:54 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
		*dest = '\0';
		return (dest);
	}
	dest = malloc(len + 1);
	if (dest == 0)
		return (0);
	while (i < start)
		i++;
	ft_strlcpy(dest, (s + i), len + 1);
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (src == 0)
		return (0);
	src_len = ft_strlen(src);
	if (dest == 0 || src == 0)
		return (0);
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < (size - 1) && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size < src_len)
		dest[size - 1] = '\0';
	else if (size != 0)
		dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (i == n)
			return (0);
		if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
			return (0);
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
}

int	count_lines(char **argv)
{
	int		lines;
	char	*str;
	int		fd;

	lines = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free (str);
		lines++;
	}
	close(fd);
	return (lines);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	vrz;

	i = 0;
	vrz = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			vrz = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (vrz * res);
}

