/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarab <mbelarab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:28:01 by mbelarab          #+#    #+#             */
/*   Updated: 2026/10/24 09:12:05 by mbelarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*count;

	count = *lst;
	while (count)
	{
		count = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = count;
	}
	*lst = NULL;
}
