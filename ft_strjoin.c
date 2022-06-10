/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:01:42 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/17 21:18:11 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src [j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len_s;
	int		len_p;
	int		len_sum;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_p = ft_strlen(s1);
	len_s = ft_strlen(s2);
	len_sum = len_s + len_p;
	str = (char *)malloc(sizeof(char) * len_sum + 1);
	if (str)
	{
		while (i < len_sum)
		{
			str[i] = 0;
			i++;
		}
		ft_strcat(str, (char *)s1);
		ft_strcat(str, (char *)s2);
		return (str);
	}
	return (NULL);
}
