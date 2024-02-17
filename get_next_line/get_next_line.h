/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:25:57 by zabdulza          #+#    #+#             */
/*   Updated: 2023/06/04 16:21:21 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

size_t	ft_strcspn(const char *str, const char *charset);
size_t	ft_len(char *s);
char	*ft_nw_crt_bfr(char *bfr);
char	*ft_creat_bfr(char *bfr, int bfr_sze, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
int		ft_find_n(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
