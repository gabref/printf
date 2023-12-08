/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:17:45 by galves-f          #+#    #+#             */
/*   Updated: 2023/11/05 00:28:19 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		i;
	int		size;

	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	size = (int)len;
	while (s[start] && size-- > 0)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
