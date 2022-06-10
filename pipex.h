/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:06:53 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/19 12:13:45 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//LIBRARIES
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<errno.h>

//STRUCT
typedef struct s_pipex
{
	pid_t	id1;
	pid_t	id2;
	pid_t	end[2];
	int		fd1;
	int		fd2;
	char	**c_av;
	char	**path;
}	t_pipex;

//FONCTIONS
char		**ft_split(char *s, char c);
int			ft_strncmp(char *s1, char *s2, size_t n);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
char		**ft_path(char **env);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
int			ft_strlen(char *s);
char		*joining_access(char **path, char *av);
void		child1(int *end, char **av, char **env);
void		child2(int *end, char **av, char **env);
void		no_leaks(char **s);
void		ft_perror(char *s);

#endif