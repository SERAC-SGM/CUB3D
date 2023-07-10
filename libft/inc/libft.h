/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:03:59 by maaliber          #+#    #+#             */
/*   Updated: 2022/11/10 16:03:59 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>

# define BRED	"\033[1m\033[31m"      /* Bold Red */
# define BWHITE	"\033[1m\033[37m"      /* Bold White */
# define RESET	"\033[0m"

//---------------------------------------------//
//--------------------LIBFT--------------------//
//---------------------------------------------//

int			ft_issign(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
ssize_t		ft_index(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, unsigned int size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nstr);
int			ft_atoi_base(const char *nstr, char *base);
void		*ft_calloc(size_t n, size_t size);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
void		free_tab(char **tab);
char		**ft_split(char const *s, char c);
size_t		ft_nblen(long long n);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char s, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_abs(int nb);

int			ft_isspace(int c);
int			ft_ischarset(char c, char const *set);

//---------------------------------------------//
//---------------------GNL---------------------//
//---------------------------------------------//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

size_t		ft_linelen(char *text);
char		*ft_strjoin_gnl(char *txt, char *add);
char		*getline_and_store(char *store, char *text);
char		*read_file(char *store, int fd);
char		*get_next_line(int fd);

//---------------------------------------------//
//------------------FT_PRINTF------------------//
//---------------------------------------------//

typedef struct s_param
{
	unsigned int	alt;
	unsigned int	space;
	unsigned int	left;
	unsigned int	showsign;
	unsigned int	padded;
	int				width;
	int				prec;
}	t_param;

typedef struct s_arg_spec
{
	struct s_param		param;
	int					type;
	int					size;
}	t_arg_spec;

typedef struct s_lst_arg
{
	struct s_arg_spec	*spec;
	struct s_lst_arg	*next;
}	t_lst_arg;

typedef struct s_output
{
	char	*to_print;
	ssize_t	size;
}	t_output;

/*Function for list - used in Parsing functions*/
void		del_arg(t_arg_spec *spec);
t_lst_arg	*ft_lstnew_arg(t_arg_spec *spec);
t_lst_arg	*ft_lstlast_arg(t_lst_arg *lst);
void		ft_lstadd_back_arg(t_lst_arg **lst, t_lst_arg *lnew);
void		ft_lstdelone_arg(t_lst_arg *lst, void (*del)(t_arg_spec*));
void		ft_lstclear_arg(t_lst_arg **lst);

/*Utilised functions - Used functions*/
char		*ft_strjoin_free(char *s1, char *s2);
void		*ft_setalloc(size_t size, char c, int null_terminated);
char		*ft_strinsert(char *s, char *to_ins, size_t pos);
char		*ft_strinsert_free(char *s, char *to_ins, size_t pos);

/*Parsing functions - used in Main functions*/
int			atoi_printf(const char *nstr, t_arg_spec *spec);
const char	*find_next_fmt(const char *format);
int			init_option(t_arg_spec	*spec, const char *fmt);
t_arg_spec	*init_arg(const char *fmt);
t_lst_arg	*ft_parse_format(const char *fmt);

/*Error functions*/
void		err_msg_ftp(char *msg, int c);
int			flag_comp_err(t_arg_spec *spec);
void		flag_err_msg(int errno);
int			flag_error(t_arg_spec *spec);
int			ft_format_error(t_lst_arg *spec_list, char *sup_types);

/*Convert functions - used in Process functions*/
size_t		ft_intlen_base(long long n, size_t b_size);
size_t		ft_uintlen_base(unsigned long long n, size_t b_size);
char		*ft_utoa(unsigned long long n);
char		*ft_itoa_base(int64_t n, char *base);
char		*ft_utoa_base(uint64_t n, char *base);

/*Specifiers modifier functions - used in Ouput functions*/
void		ctype_mod(t_output *output, t_arg_spec *spec);
void		s_null_case(t_output *output, t_arg_spec *spec);	
void		prec_smod(t_output *output, t_arg_spec *spec);
void		prec_nmod(t_output *output, t_arg_spec *spec);
void		padded_mod(t_output *output, t_arg_spec *spec);
void		alt_mod(t_output *output, t_arg_spec *spec);
void		sign_space_mod(t_output *output, t_arg_spec *spec);
void		left_width_mod(t_output *output, t_arg_spec *spec);

/*Process functions - used in Output functions*/
void		p_char(t_output *output, va_list ap);
void		p_str(t_output *output, va_list ap);
void		p_ptr(t_output *output, va_list ap);
void		p_int(t_output *output, va_list ap);
void		p_uint(t_output *output, va_list ap);
void		p_hex(t_output *output, va_list ap);
void		p_uphex(t_output *output, va_list ap);
void		p_pct(t_output *output, va_list ap);

/*Output functions - used in Main functions*/
void		spec_mod(t_output *output, t_arg_spec *spec);
ssize_t		write_arg(va_list ap, t_arg_spec *spec);
ssize_t		ft_output(const char *fmt, va_list ap, t_lst_arg *arg_list);

/*Main function*/
int			ft_printf(const char *format, ...);

#endif	
