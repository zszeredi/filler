/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/04 11:22:29 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <float.h>
# include <math.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_parse
{
	int					*array;
	int					num_stars;
	int					width;
	int					precision;
	int					f_minus;
	int					f_plus;
	int					f_space;
	int					f_zero;
	int					f_hash;
	int					ls;
	int					fs_len;
	int					pos;
}						t_parse;

typedef struct			s_s_to_fs
{
	int					position;
	char				*fs;
	int					fs_start;
	int					fs_end;
	int					string_len;
	int					fs_len;
	int					counter;
	va_list				ap;
}						t_s_to_fs;

typedef struct			s_for_pdioux
{
	int					str_l;
	int					space;
	int					nb_zeros;
	int					base;
	int					di_n;
	intmax_t			s_n;
	uintmax_t			u_n;
	char				c;
	char				*str;
}						t_for_pdioux;

typedef struct			s_for_f
{
	int					neg;
	int					space;
	int					len;
	int					counter;
	long double			num;
	long double			copy;
	long double			next_m;
	unsigned long long	d;
	unsigned long long	d_c;
}						t_for_f;

int						calc_nb_zeros(t_parse *p, t_for_pdioux *ptr);
char					*pdioux_enlarge_str(t_parse *p, t_for_pdioux *ptr);
t_for_pdioux			*pdioux_modif_str(t_parse *p, t_for_pdioux *ptr);
int						pdioux_no_print(t_parse *p, t_for_pdioux *ptr);
t_parse					*pdioux_null_flags(t_parse *p, t_for_pdioux *ptr);
char					*pdioux_str_create(t_parse *p, t_for_pdioux *ptr);
int						pdioux_main(t_parse *p, t_s_to_fs *pointer,
		t_for_pdioux *ptr);
int						ft_oux_modifier(t_parse *p, t_s_to_fs *pointer, char c);
char					*di_add_c_before(t_parse *p, char *str);
int						di_calc_zeros(t_parse *p, int str_l, int neg);
t_for_pdioux			*di_enlarge_str(t_parse *p, t_for_pdioux *ptr);
int						ft_di_fs(t_parse*p, t_s_to_fs *pointer);
void					print_f(t_parse *p, t_s_to_fs *pointer, t_for_f *ptr);
void					printf_no_min(t_parse *p, t_s_to_fs *pointer,
		t_for_f *ptr);
t_for_f					*round_up(t_parse *p, t_for_f *ptr);
int						len(t_parse *p, unsigned long long d, int neg);
int						ft_f_fs(t_parse *p, t_s_to_fs *pointer);
int						ft_c_fs(t_parse *p, int chara, t_s_to_fs *pointer);
int						ft_s_fs(t_parse *p, char *string, t_s_to_fs *pointer);
int						ft_p_fs(t_parse *p, void *pt,
		t_s_to_fs *pointer);
t_parse					*length_modifier(t_parse *p, char *fs);
t_parse					*flags_zero(t_parse *p);
t_parse					*flags(char c, t_parse *p);
t_parse					*set_wp(t_parse *p, char *fs);
int						formatted_string(t_s_to_fs *ptr);
t_s_to_fs				*cutting(t_s_to_fs *ptr, char *str);
void					ft_print_space(t_parse *p, t_s_to_fs *pointer,
		int space, int c);
void					dioux_width_print(t_parse *p, t_s_to_fs *pointer,
		t_for_pdioux *ptr);
void					*ft_delete_double_array(char **str);
int						ft_printf(const char *str, ...);
int						main();
#endif
