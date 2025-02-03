/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:46:21 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/03 14:56:47 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/// @brief Cree un processus enfant pour exec une cmd dans une pipeline
///		- Le parent lit depuis le pipe
///		- L'enfant ecrit dams le pipe et exec cmd
/// @param argv La commande a executer
/// @param envp Les variables d'environnement du programme
void	child_process_bonus(char *argv, char **envp, int infile, int outfile)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == PIPE_ERR)
		error();
	pid = fork();
	if (pid == FORK_ERR)
		error();
	if (pid == FORK_SUCCESS)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(infile);
		close(outfile);
		execute_command(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		clsoe(fd[0]);
		waitpid(pid, NULL, RET_OK);
	}
}

/// @brief Lit l'entree standard jusqu'au delimiteur
///		- stocke dans here_doc (fichier tmp)
///		- l'utilise comme entree du pipe
/// @param limiter Limiteur du here_doc
/// @return fd de here_doc_pipex ou -1 en cas d'erreur
int	here_doc(char *limiter)
{
	char	*line;
	int		tmp_here_doc;

	tmp_here_doc = open(HERE_DOC_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_here_doc < 0)
		return (ft_putstr_fd(WRITE_ERR HERE_DOC_PATH, STDERR_FILENO), -1);
	ft_putstr_fd(HERE_DOC_PROMPT, STDIN_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(line, tmp_here_doc);
		ft_putstr_fd(HERE_DOC_PROMPT, STDIN_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(tmp_here_doc);
	tmp_here_doc = open(HERE_DOC_PATH, O_RDONLY, 0444);
	if (tmp_here_doc < 0)
		ft_putstr_fd(READ_ERR HERE_DOC_PATH, STDERR_FILENO);
	return (tmp_here_doc);
}
