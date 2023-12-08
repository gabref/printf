/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:56:39 by galves-f          #+#    #+#             */
/*   Updated: 2023/11/05 13:23:19 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (*str && str[i++] != c)
		words++;
	while (str[i])
	{
		if (str[i] && str[i] != c && str[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**splitted;
	int		c_word;
	int		start;
	int		end;

	words = count_words((char *)s, c);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	c_word = 0;
	start = 0;
	end = 0;
	while (c_word < words)
	{
		start = end;
		while (s[start] && s[start] == c)
			start++;
		end = start + 1;
		while (s[end] && s[end] != c)
			end++;
		splitted[c_word] = ft_substr((const char *)s, start, end - start);
		c_word++;
	}
	*(splitted + c_word) = NULL;
	return (splitted);
}
