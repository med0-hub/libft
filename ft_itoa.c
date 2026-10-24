/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarab <mbelarab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:22:26 by mbelarab          #+#    #+#             */
/*   Updated: 2026/10/21 11:12:38 by mbelarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(long n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;
	long			nb;

	nb = n;
	len = ft_intlen(nb);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[len] = '\0';
	len--;
	while (nb > 9)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	str[len] = nb + '0';
	return (str);
}
