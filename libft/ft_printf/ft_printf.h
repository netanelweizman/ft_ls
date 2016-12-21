/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:11:30 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/13 16:11:31 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define F format
# define F1 format + 1
# define SIGN obj->specifier
# define LENGTH obj->length
# define RES obj->result
# define FLAGS obj->flags
# define WIDTH obj->width
# define PRECISION obj->precision

# include <stdarg.h>
# include <wchar.h>

# include "../libft.h"

typedef struct	s_obj
{
	void	*value;
	char	flags;
	int		width;
	int		precision;
	char	length;
	char	specifier;
	char	*result;

}				t_object;

int				ft_printf(const char *format, ...);
int				args_count(char *format);
int				create_args_list(void *arg, t_list **args_list);
int				check_flags(char **format, t_object *obj);
char			*get_next_char(char *str);
char			*get_char(char *str);
void			build_object(t_object *obj);
void			build_object_x(t_object *obj);
void			build_object_d(t_object *obj);
void			build_object_c(t_object *obj);
void			build_object_s(t_object *obj);
void			build_object_o(t_object *obj);
void			build_object_u(t_object *obj);
void			build_object_special(t_object *obj);
char			*pft_itoa_base(uintmax_t value, int base);
void			pft_putstr(char const *s, t_object *obj);
void			width_fill_offset(t_object *obj, char c, size_t offset);
int				count_digit(char *format);
int				object_management_bonus(char **format);
void			free_list(t_list **list);
void			free_func(t_object **obj);

#endif
