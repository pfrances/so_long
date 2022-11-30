/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:32:29 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/28 11:43:23 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;
	char	*s_bytes;

	i = 0;
	s_bytes = (char *)s;
	while (i < n)
	{
		s_bytes[i] = '\0';
		i++;
	}
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	size;

	size = ft_strlen_gnl(s) + 1;
	if (size > n)
		size = n + 1;
	dup = malloc(sizeof(char) * (size));
	if (dup != NULL)
		ft_strlcpy_gnl(dup, s, size);
	return (dup);
}

char	*ft_strjoin_with_free(char *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_length;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	total_length = s1_len + s2_len;
	result = malloc(sizeof(char) * (total_length + 1));
	if (result == NULL)
		return (result);
	ft_strlcpy_gnl(result, s1, s1_len + 1);
	ft_strlcpy_gnl(result + s1_len, s2, s2_len + 1);
	free(s1);
	return (result);
}
