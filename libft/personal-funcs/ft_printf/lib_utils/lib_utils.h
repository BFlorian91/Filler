/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:48:15 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:25:22 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

# include <unistd.h>

char	*ft_itoa(long long int n);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
void	ft_memdel(void **ap);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strrev(char *str);
int		ft_isdigit(int c);
int		ft_toupper(int c);
char	*ft_utoa(long long unsigned nb);

#endif
