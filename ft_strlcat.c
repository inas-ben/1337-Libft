/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:23:54 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/02 12:14:18 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	if (destsize == 0 && !dest)
		return (ft_strlen(src));
	while (len < destsize && dest[len])
		len++;
	i = 0;
	while (src[i])
		i++;
	if (len >= destsize)
		return (destsize + i);
	j = 0;
	while (src[j] && j < destsize - len - 1)
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (len + i);
}
