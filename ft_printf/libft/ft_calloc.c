/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:32:19 by galves-f          #+#    #+#             */
/*   Updated: 2023/11/04 01:44:35 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb > (INT_MAX / size))
		return (NULL);
	arr = malloc(size * nmemb);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb);
	return (arr);
}
