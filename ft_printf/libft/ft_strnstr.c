/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:19:42 by galves-f          #+#    #+#             */
/*   Updated: 2023/11/03 18:48:00 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(const char *str, const char *word)
{
	while (*word)
		if (*word++ != *str++)
			return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	nsize;
	int	search_until;

	if (!*needle)
		return ((char *)haystack);
	nsize = ft_strlen(needle);
	search_until = len - nsize;
	while (*haystack && search_until-- > 0)
		if (is_word(haystack++, needle))
			return ((char *)--haystack);
	return (NULL);
}
