/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:28:47 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/03 17:38:05 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/// @brief Affiche un message d'erreur et quitte le programme
void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

/// @brief Affiche un message d'erreur et donne l'utilisation du programme
void	usage_pipex(void)
{
	ft_putstr_fd(RED BAD_ARG_ERR RESET, STDERR_FILENO);
	ft_putstr_fd(USAGE_MSG
		BLUE INFILE_MSG
		GREEN CMD_MSG
		BLUE OUTFILE_MSG RESET,
		STDOUT_FILENO);
}

/// @brief Libere un tableau de chaine de caracteres
/// @param paths Tableau de la chaine a liberer
void	free_split(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
