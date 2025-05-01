/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgret <emegret@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:56:19 by emgret            #+#    #+#             */
/*   Updated: 2025/05/01 14:32:42 by emgret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

//main (not finish)
int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;

	(void)argc;
	(void)argv;

	init_shell(&shell, envp);
	while (1)
	{
		handle_signals(); // ctrl+c, ctrl+\, etc
		shell.input = readline("minishell$ ");
		if (!shell.input) // CTRL+D
			exit_shell(&shell, 0);
		if (shell.input[0] != '\0')
			add_history(shell.input);
		if (parse_input(&shell) == 0) // if parsing OK
			execute_commands(&shell);
		free_everything(&shell); // reset between each input
	}
	return (0);
}
