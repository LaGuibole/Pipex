/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:46:23 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/03 14:52:26 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/// @brief Fonction d'erreur pour pipex bonus, donne l'utilisation du programme
/// @param
void	usage_bonus(void)
{
	ft_putstr_fd(RED BAD_ARG_ERR RESET, STDERR_FILENO);
	ft_putstr_fd(EX_NAME
		BLUE INFILE_MSG
		GREEN CMD_MSG
		BLUE OUTFILE_MSG RESET,
		STDOUT_FILENO);
	ft_putstr_fd(EX_BONUS_NAME
		BLUE HERE_DOC_MSG
		GREEN CMD_BONUS_MSG
		BLUE OUTFILE_MSG RESET,
		STDOUT_FILENO);
}
