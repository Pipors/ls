/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:34:40 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:15:49 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_infile(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)g_data.cmds->content;
	if (cmd->error == 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->infile, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("ambiguous redirect", 2);
		g_data.exit_status = 1;
		if (g_data.signalchild)
			exit(g_data.exit_status);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->infile, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(cmd->errno_value), 2);
		g_data.exit_status = 1;
		if (g_data.signalchild)
			exit(g_data.exit_status);
	}
}

void	error_command_not_found(char *s, char *str, int status_code)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found", 2);
	ft_putstr_fd("\n", 2);
	exit(status_code);
}

void	exit_strerr(char *str, int err, int exit_status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(err), 2);
	exit(exit_status);
}

void	error_msg(char *str, int err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(err), 2);
}
