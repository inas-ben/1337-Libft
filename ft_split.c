/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:26:02 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/02 16:32:46 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			if (i == 0 || s[i - 1] == c)
				words++;
			i++;
		}
	}
	return (words);
}

static char	*word(const char *s, char c, size_t index)
{
	size_t	len;

	len = 0;
	while (s[index + len] && s[index + len] != c)
		len++;
	return (ft_substr(s, index, len));
}

static void	free_all(char **tab, size_t n)
{
	while (n > 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
}

static int	fill(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			arr[i] = word(s, c, j);
			if (!arr[i])
			{
				free_all(arr, i);
				return (0);
			}
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!fill(tab, s, c))
		return (NULL);
	return (tab);
}
