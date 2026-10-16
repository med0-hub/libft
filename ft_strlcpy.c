/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarab <mbelarab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:55:13 by mbelarab          #+#    #+#             */
/*   Updated: 2026/10/16 17:44:28 by mbelarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	else if (size == 0)
		return (ft_strlen(src));
	else if (size == 1)
	{
		dst[0] = '\0';
		return (ft_strlen(src));
	}
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}
