/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:16:50 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/04/05 12:17:16 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_fprintf(int fd, const char *str, ...);
int		ft_fputchar(int fd, int c);
int		ft_fputnbr_base(int fd, unsigned long n, char *base, int i);
int		ft_fputpointer(int fd, void *ptr);
int		ft_fputstr(int fd, char *str);
char	*ft_strchar(const char *s, int c);
int		ft_fputunsigned_nbr(int fd, unsigned long long n, char *base, int i);

#endif
