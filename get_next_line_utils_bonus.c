/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:28:13 by jinspark          #+#    #+#             */
/*   Updated: 2021/03/20 02:28:14 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char			*dst;
	size_t			i;
	const size_t	len = (ft_strlen(s1) > n) ? n : ft_strlen(s1);

	if (!(dst = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
		dst[i++] = *s1++;
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			i;
	const size_t	str_len = ft_strlen(s1) + ft_strlen(s2);

	if (!(str = malloc((str_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
