/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarab <mbelarab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:01:22 by mbelarab          #+#    #+#             */
/*   Updated: 2026/10/24 11:48:18 by mbelarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	free_split(char **res, unsigned int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static char	**fill_str(char const *s, char **res, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	len;

	i = 0;
	start = 0;
	len = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		if (!s[start])
			break ;
		len = 0;
		while (s[start + len] && s[start + len] != c)
			len++;
		res[i] = ft_substr(s, start, len);
		if (!res[i])
			return (free_split(res, i), NULL);
		i++;
		start += len;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char *s, char c)
{
	unsigned int	words;
	char			**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res = fill_str(s, res, c);
	return (res);
}
