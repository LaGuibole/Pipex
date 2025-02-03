/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:21:07 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/03 17:32:58 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/// @brief Recupere la valeur de la variable d'environnement "PATH="
/// @param envp Tableau des variables d'environnement
/// @return Un pointeur vers la valeur de PATH ("PATH=" exclu), ou NULL
char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == RET_OK)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

/// @brief Recupere les chemins des repertoires du PATH
/// @param envp Tableau des variables d'environnement
/// @return Un tableau de chaines contenant les chemins du PATH ou NULL
char	**get_paths(char **envp)
{
	char	*path_env;

	path_env = get_env_path(envp);
	if (!path_env)
		return (NULL);
	return (ft_split(path_env, ':'));
}

/// @brief Construit le chemin complet, join un repertoire de PATH avec une CMD
/// @param path Chemin du repertoire
/// @param cmd Nom de la commande
/// @return Un pointeur vers le chemin complet ou NULL
char	*join_cmd_paths(char *path, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full_path)
		return (NULL);
	return (full_path);
}

/// @brief Trouve le chemin absolu d'une commande en utilisant le PATH
/// @param cmd Nom de la commande
/// @param envp Tableau des variables d'environnement
/// @return	Le chemin absolu de la commande ou NULL
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	if (!cmd || !envp)
		return (NULL);
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	if (access(cmd, F_OK | X_OK) == RET_OK)
		return (free_split(paths), cmd);
	i = 0;
	while (paths[i])
	{
		full_path = join_cmd_paths(paths[i], cmd);
		if (!full_path)
			continue ;
		if (access(full_path, X_OK) == RET_OK)
			return (free_split(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_split(paths), NULL);
}

/// @brief Execute la commande en recherchant le chemin dans PATH
/// @param cmd La commande a executer
/// @param envp Tableau des variables d'environnement
void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found\n", STDERR_FILENO);
		free(cmd_path);
		free_split(args);
		exit(127);
	}
	if (execve(cmd_path, args, envp) == EXECVE_ERR)
	{
		perror("execve failed");
		free(cmd_path);
		free_split(args);
	}
	exit(1);
}
