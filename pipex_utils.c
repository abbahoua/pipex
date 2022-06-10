/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:05:47 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/17 21:18:00 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2 [i] && s1[i] == s2[i] && i < n)
		i++;
	if (n == i)
		i--;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	if (size > 0)
	{	
		i = 0;
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}	
	return (j);
}
