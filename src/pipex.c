/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:09:53 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/01 14:39:37 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/// @brief Execute le process enfant de la 1ere commande, redirige in / out
/// @param argv Argument de la ligne de commande
/// @param envp Les variables d'environnement
/// @param fd Le tableau contenant les fd pour le pipe
void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0644);
	if (infile == OPEN_ERR)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	execute_command(argv[2], envp);
}

/// @brief Execute le processus enfant pour la 2eme commande redirige in / out
/// @param argv Les arguments de la ligne de commande
/// @param envp Les variables d'envrionnement
/// @param fd Le tableau contenant les fd pour le pipe
void	child_process2(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == OPEN_ERR)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[1]);
	close(fd[0]);
	execute_command(argv[3], envp);
}

/// @brief Fonction main qui gere les process enfants et les pipes
/// @param argc Nombre d'arguments
/// @param argv Arguments de la ligne de commande
/// @param envp Les variables d'environnement
/// @return Return 0 si l'exec se passe bien
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		if (pipe(pipex.fd) == PIPE_ERR)
			error();
		pipex.pid1 = fork();
		if (pipex.pid1 == FORK_ERR)
			error();
		if (pipex.pid1 == FORK_SUCCESS)
			child_process(argv, envp, pipex.fd);
		pipex.pid2 = fork();
		if (pipex.pid2 == FORK_ERR)
			error();
		if (pipex.pid2 == FORK_SUCCESS)
			child_process2(argv, envp, pipex.fd);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		waitpid(pipex.pid1, NULL, FORK_SUCCESS);
		waitpid(pipex.pid2, NULL, FORK_SUCCESS);
	}
	else
		usage_pipex();
	return (0);
}
