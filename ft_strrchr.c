/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:11:41 by ibendris          #+#    #+#             */
/*   Updated: 2026/10/15 22:44:18 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	if ((unsigned char)c == '\0')
		return ((char *)&str[len]);
	while (len > 0)
	{
		len--;
		if (str[len] == (unsigned char)c)
			return ((char *)&str[len]);
	}
	return (NULL);
}
