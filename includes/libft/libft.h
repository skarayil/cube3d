/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:40:42 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:40:43 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *b, int c, size_t len);

#endif