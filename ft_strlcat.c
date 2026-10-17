/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarab <mbelarab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:30:24 by mbelarab          #+#    #+#             */
/*   Updated: 2026/10/17 07:46:33 by mbelarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	isrc;
	size_t	idst;

	idst = 0;
	while (idst < size && dst[idst])
		idst++;
	if (idst == size)
        return (size + ft_strlen(src));
	isrc = 0;
	while (src[isrc] && (isrc + idst) < size - 1)
	{
		dst[idst + isrc] = src[isrc];
		isrc++;
	}
	dst[idst + isrc] = '\0';
	return (idst + ft_strlen(src));
}
