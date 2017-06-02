/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:17:56 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/17 16:50:40 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <inttypes.h>
# include <stdarg.h>
# include <wchar.h>

# define GNL_BUFF_SIZE 4

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	int				fd;
	char			*buff;
	struct s_file	*next;
}					t_file;

typedef struct		s_pfarg
{
	char			*cnt;
	size_t			cnt_len;
	int				fmt_flags;
	int				width;
	int				prec;
	int				size_flag;
	char			c_type;
	int				is_zero_char;
	va_list			*argp;
}					t_pfarg;

void				ft_putchar(char ch);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_fdputchar(char ch, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_fdputstr(char const *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					ft_isprint(int ch);
int					ft_isascii(int ch);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_atoi(const char *str);
intmax_t			ft_atoimax(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(ssize_t n);
int					ft_nbrlen(ssize_t n);
char				**ft_strsplit(char const *s, char c);
int					ft_countwords(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_strsplit_lst(char const **word_tab);
void				ft_lstadd_back(t_list *alst, t_list *new);
void				*ft_lstfold(t_list *alst, void *(*f)(t_list *elem));
void				*ft_lst_concat(t_list *lst);
size_t				ft_lstcount(t_list *lst);
void				ft_lstrev(t_list **alst);
void				ft_swap_int(int *a, int *b);
char				*ft_uitoa_base(size_t val, int base);
char				*ft_strndup(const char *s1, unsigned int n);
char				*ft_dstrjoin(char *s1, char *s2, int ff1, int ff2);
void				ft_strcap(char *str);
void				ft_swap_chars(char *a, char *b);

int					get_next_line(int const fd, char **line);

int					ft_printf(const char *str, ...);
void				struct_parse(const char **str, va_list *ap,
								size_t *b_printed, int fd);
int					parse_size_flags(const char **str, t_pfarg *arg);
int					parse_prec(const char **str, t_pfarg *arg, int prec);
int					parse_width(const char **str, t_pfarg *arg);
int					parse_fmt_flags(const char **str, t_pfarg *arg);
size_t				s_size_parse(t_pfarg *arg);
size_t				u_size_parse(t_pfarg *arg);
char				*string_parse(t_pfarg *arg);
char				*char_parse(t_pfarg *arg, int udef_flag);
long double			ft_round_fraction(long double t);
char				*pre_format(t_pfarg *arg);
void				prec_format(t_pfarg *arg, char **end_content);
void				hash_format(t_pfarg *arg, char **end_content);
void				signed_sign_format(t_pfarg *arg, char **end_content);
void				zero_minus_format(t_pfarg *arg, char **end_content);
void				common_format(t_pfarg *arg);
char				*ft_uitoa(size_t n);
void				ft_pfputstr(t_pfarg *arg, int fd);
char				*ft_ftoa(long double val, int prec);
char				*ft_etoa(long double val, int prec);
int					*parse_values(int a, int b, int c);
char				*e_conversion(long double val, int prec);
char				*fe_dispatcher(t_pfarg *arg);
void				ft_pfputstr(t_pfarg *arg, int fd);

#endif
