/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:37:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 17:20:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char	*ft_strnstr(const char *stack, const char *needle, int len);
char	*join_three_strs(char *s1, char *s2, char *s3);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

void	*ft_calloc(int nelem, int elsize);
void	ft_putstr_fd(char *s, int fd);
void	*ft_malloc(size_t size);

int		execute_cmd(int argc, char *argv[], char **envp);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strlen(const char *s);

bool	ft_strcmp(char *s1, char *s2);

#endif