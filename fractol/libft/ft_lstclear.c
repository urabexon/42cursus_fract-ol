/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:32:29 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/28 17:47:31 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*first;
	t_list	*ptr;

	if (!lst || !(*lst))
		return ;
	first = *lst;
	while (*lst)
	{
		ptr = *lst;
		(*lst)->num = 0;
		(*lst)->index = 0;
		*lst = (*lst)->next;
		free(ptr);
		ptr = NULL;
		if (*lst == first)
			break ;
	}
	lst = NULL;
}
