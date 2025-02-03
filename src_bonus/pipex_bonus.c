/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:46:19 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/03 14:57:11 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void close_fds(int infile, int outfile)
{
	if (infile > 0)
		close(infile);
	if (outfile > 0)
		close(outfile);
}

/// @brief function to open infile and outfile
/// @param argv
/// @param argc
/// @param infile
/// @param outfile
/// @return
int	open_infile_outfile(char **argv, int argc, int *infile, int *outfile)
{
	int	is_here_doc;

	is_here_doc = ft_strncmp(argv[1], "here_doc", 8) == RET_OK;
	if (is_here_doc)
	{
		*infile = here_doc(argv[2]);
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		*infile = open(argv[1], O_RDONLY, 0444);
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (*infile < 0 || *outfile < 0)
		return (RET_ERR);
	return (RET_OK);
}

/// @brief Fonction principale de pipex 
/// @param argc
/// @param argv
/// @param envp
/// @return
int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		if (open_infile_outfile(argv, argc, &infile, &outfile) != RET_OK)
		{
			if (outfile < 0)
				return (ft_putstr_fd(OPEN_OUT_ERR, STDERR_FILENO), RET_ERR);
			else
				return (ft_putstr_fd(OPEN_IN_ERR, STDERR_FILENO), RET_ERR);
		}
		dup2(infile, STDIN_FILENO);
		i = 2 + (ft_strncmp(argv[1], "here_doc", 8) == RET_OK);
		while (i < argc - 2)
			child_process_bonus(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		close_fds(infile, outfile)
		execute_command(argv[argc - 2], envp);
	}
	usage_bonus();
}
