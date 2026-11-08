/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:55:22 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/01 17:26:11 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	size_t			i;
	unsigned char	*mem;

	if (size != 0 && (nbr * size) / size != nbr)
		return (NULL);
	if (nbr == 0 || size == 0)
	{
		nbr = 1;
		size = 1;
	}
	mem = malloc(nbr * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < nbr * size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
