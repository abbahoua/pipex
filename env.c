/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:02:24 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/19 11:28:48 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path(char **env)
{
	char	**sub_path;
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = &env[i][5];
		i++;
	}
	sub_path = ft_split(path, ':');
	return (sub_path);
}

char	*joining_access(char **path, char *av)
{
	int		i;
	char	*join1;
	char	*join2;

	i = 0;
	while (path[i])
	{
		join1 = ft_strjoin(path[i], "/");
		join2 = ft_strjoin(join1, av);
		free(join1);
		if ((access(join2, X_OK | F_OK)) == 0)
			return (join2);
		i++;
	}
	free(join2);
	return (NULL);
}

void	ft_perror(char *s)
{
	perror(s);
	exit (1);
}
