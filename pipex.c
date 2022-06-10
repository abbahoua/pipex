/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:20:07 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/19 12:59:15 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int *end, char **av, char **env)
{
	char	**c_av;
	char	**path;
	char	*cmd1;
	int		fd1;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror(av[1]);
		exit(1);
	}
	path = ft_path(env);
	c_av = ft_split(av[2], ' ');
	cmd1 = joining_access(path, c_av[0]);
	close (end[0]);
	dup2(fd1, 0);
	dup2(end[1], 1);
	close(fd1);
	if (!cmd1)
		ft_perror("Error command not found\n");
	execve(cmd1, c_av, env);
}

void	child2(int *end, char **av, char **env)
{
	char	**c_av;
	char	**path;
	char	*cmd2;
	int		fd2;

	fd2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
	{
		perror(av[4]);
		exit(1);
	}
	path = ft_path(env);
	c_av = ft_split(av[3], ' ');
	cmd2 = joining_access(path, c_av[0]);
	close(end[1]);
	dup2(end[0], 0);
	dup2(fd2, 1);
	close(fd2);
	if (!cmd2)
		ft_perror("Error command not found\n");
	execve(cmd2, c_av, env);
}

int	main(int ac, char *av[], char **env)
{
	t_pipex	p;

	if (ac != 5)
		ft_perror("Error Number of args\n");
	if ((pipe(p.end)) == -1)
		ft_perror("Error pipe\n");
	p.id1 = fork();
	if (p.id1 == 0)
		child1(p.end, av, env);
	p.id2 = fork();
	if (p.id2 == 0)
		child2(p.end, av, env);
	close(p.end[0]);
	close(p.end[1]);
	waitpid(p.id1, NULL, 0);
	waitpid(p.id2, NULL, 0);
	return (0);
}
