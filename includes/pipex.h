/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:01:02 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/03 16:43:40 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

// STRUCTS
typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

// RETURNS
# define RET_OK			0
# define RET_ERR		1
# define EXECVE_ERR		-1
# define PIPE_ERR		-1
# define FORK_ERR		-1
# define PIPE_SUCCESS	0
# define FORK_SUCCESS	0
# define OPEN_ERR		-1

// NAME & ERROR MESSAGES
# define P_NAME				"pipex: "
# define HERE_DOC_PATH		"/tmp/here_doc_pipex\n"
# define HERE_DOC_PROMPT	"here_doc> "
# define WRITE_ERR			"Could not write "
# define READ_ERR			"Could not read "
# define OPEN_OUT_ERR		"Could not open outfile\n"
# define OPEN_IN_ERR		"Could not open infile\n"
# define BAD_ARG_ERR		"Error : Bad Argement\n"
# define USAGE_MSG			"Usage : ./pipex "
# define EX_NAME			"Ex : ./pipex "
# define EX_BONUS_NAME		"     ./pipex_bonus "
# define INFILE_MSG			"<infile> "
# define OUTFILE_MSG		"<outfile>\n"
# define HERE_DOC_MSG		"here_doc <LIMITER> "
# define CMD_MSG			"<cmd1> <cmd2> "
# define CMD_BONUS_MSG		"<cmd1> <cmd2> <...> "
# define ERR_PIPE_INIT		"Error initializing pipe.\n"
# define ERR_FORK_INIT		"Error initializing fork.\n"
# define ERR_MISSING_ARG	"Not enough arguments.\n"
# define ERR_ACC_OUTFILE	"Error accessing outfile.\n"

// ERROR COLORS
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define GREEN		"\033[32m"
# define RESET		"\033[0m"

// PATHING + EXEC
char	*get_env_path(char **envp);
char	**get_paths(char **envp);
char	*get_cmd_path(char *cmd, char **envp);
void	execute_command(char *cmd, char **envp);
int		is_script_cmd(char *cmd);

// ERRORS FUNCTIONS
void	error(void);
void	usage_pipex(void);
void	free_split(char **paths);

// BONUS FUNCTIONS
void	usage_bonus(void);
void	child_process_bonus(char *argv, char **envp);
int		here_doc(char *limiter);
int		open_file(char *argv, int flag);
int		open_infile_outfile(char **argv, int argc, int *infile, int *outfile);
#endif
