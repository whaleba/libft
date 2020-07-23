/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:32:48 by harmida           #+#    #+#             */
/*   Updated: 2020/05/26 16:12:08 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	if (!(*lst) || !lst || del == NULL)
		return ;
	while (*lst != NULL)
	{
		while (temp->next != NULL)
		{
			temp2 = temp;
			temp = temp->next;
		}
		del(temp->content);
		free(temp);
		if (temp2 != temp)
		{
			temp2->next = NULL;
			temp = *lst;
		}
		else
			*lst = NULL;
	}
}
