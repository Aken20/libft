/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:47:00 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/27 21:06:42 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_ascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *s_in, const char *s_for, size_t len);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_toupper(char *c);
int		ft_tolower(char *c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memset(void *b, int c, unsigned int len);
void	*ft_memcpy(void *dest, void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, int n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);