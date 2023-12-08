/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:11:56 by galves-f          #+#    #+#             */
/*   Updated: 2023/11/06 00:15:22 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	while (current->next)
	{
		temp = current;
		current = current->next;
		del(temp->content);
		free(temp);
	}
	del(current->content);
	free(current);
	*lst = NULL;
}
