/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:51:26 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:03:34 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*lorst;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	lorst = (char *)malloc(l + 1);
	if (!lorst)
		return (NULL);
	while (s1 && s1[i])
	{
		lorst[i] = s1[i];
		i++;
	}
	while (s2[j])
		lorst[i++] = s2[j++];
	lorst[i] = '\0';
	return (free(s1), lorst);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)(s + i)) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	int	*p;

	p = 0;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}
