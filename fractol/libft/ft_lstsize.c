/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:32:49 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/28 17:47:39 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize(t_list **lst)
{
	t_list	*ptr;
	int		i;

	if (!lst || !(*lst))
		return (0);
	ptr = *lst;
	i = 0;
	while (*lst)
	{
		i++;
		*lst = (*lst)->next;
		if (*lst == ptr)
			break ;
	}
	return (i);
}
