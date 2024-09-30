/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:55 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/28 17:47:22 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// リストの最後に新しいノードを追加する関数
// ft_lstlast関数を使ってリストの最後のノードを見つけ、その次に新しいノードを追加する。

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->pre = new;
	}
	else
	{
		last = (*lst)->pre;
		last->next = new;
		new->pre = last;
		new->next = *lst;
		(*lst)->pre = new;
	}
}
