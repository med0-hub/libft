/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarab <mbelarab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 09:32:06 by mbelarab          #+#    #+#             */
/*   Updated: 2026/10/24 13:42:22 by mbelarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*count;
	int		c;

	count = lst;
	c = 0;
	while (count != NULL)
	{
		count = count->next;
		c++;
	}
	return (c);
}
