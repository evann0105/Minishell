/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgret <emegret@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:23:52 by emgret            #+#    #+#             */
/*   Updated: 2025/05/01 14:32:09 by emgret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h> 
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>

typedef struct s_cmd
{
	char			**args;
	char			*cmd_path;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
}	t_cmd;

//dans l'ordre ->
// Arguments de la commande
// Chemin vers l'exécutable
// fd redirection d'entrée
// fd redirection de sortie
// Commande suivante (pour les pipes)

typedef struct s_minishell
{
	char	**envp;
	char	*input;
	t_cmd	*cmds;
	int		last_exit_status;
	int		in_fd_backup;
	int		out_fd_backup;
	int		heredoc_fd;
}	t_minishell;

//dans l'ordre ->
// Environnement modifiable (copie de envp)
// Ligne brute entrée par l'utilisateur
// Liste chaînée des commandes à exécuter
// Dernier code de sortie ($?)
// Sauvegarde stdin
// Sauvegarde stdout
// Gestion spécifique des heredocs

#endif