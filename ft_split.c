/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:10:37 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/17 21:14:18 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
		count++;
		i++;
	}
	return (count);
}

static char	**split_support(char **arr, char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		i++;
		len = i;
		while (s[len] && s[len] != c)
		len++;
		if (s[i])
		{
			arr[j] = malloc((len - i + 1) * sizeof(char));
			ft_strlcpy(arr[j++], s + i, len - i + 1);
		}
			i = len;
	}	
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	split_support(arr, s, c);
	return (arr);
}
