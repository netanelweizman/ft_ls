/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:26:39 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/07 12:26:41 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdbool.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>

# include "libft/ft_printf/ft_printf.h"

typedef struct	s_lsl
{
	int				mode_s;
	int				link_s;
	int				owner_s;
	int				group_s;
	int				bytes_s;
	int				date_s;
	int				major_s;
	int				minor_s;
	int				total;
	int				device;
	int				blocksize;

}				t_lsl;

typedef struct	s_file
{
	char			*f_name;
	char			*f_path;
	struct stat		*st;
	int				off;
	struct s_file	*next;
	struct s_file	*back;

}				t_file;

typedef struct	s_dir
{
	char			*name;
	char			*path;
	DIR				*dirp;
	struct s_file	*files;
	struct s_file	*last_file;
	struct s_dir	*back;

}				t_dir;

typedef struct	s_stg
{
	struct s_dir	*arg_dir;
	int				arg_index;
	int				total_dir;
	int				total_arg;
	bool			flag_l;
	bool			flag_a;
	bool			flag_t;
	bool			flag_r;
	bool			flag_rr;
	bool			flag_d;
	bool			flag_p;
	bool			flag_c;
	bool			flag_uu;
	bool			flag_u;
	bool			flag_ss;
	bool			flag_aa;
	bool			flag_f;
	bool			flag_g;
	bool			flag_o;
	bool			flag_ff;
	bool			flag_one;
	bool			nl;

}				t_stg;

/*
** Print Functions
*/
void			printd(t_stg *settings, t_file *files);
int				print_if_file(t_stg *settings);
void			file_pwgw(t_stg *settings, t_file *file, t_lsl *set);
void			file_mode(t_file *file, char *path);
void			print_flag_f(t_file *file);
void			init_lsl(t_lsl *set);
void			init_width_files(t_stg *settings, t_file *files, t_lsl *set,
	int res);
void			lprintd_l(t_stg *settings, t_lsl *set, t_file *files);
void			print_str(t_stg *settings, char *str, int type, t_lsl *set);
void			file_name(t_stg *settings, t_file *file,
	char **link_target, char *path);
int				entries_check(t_stg *settings, char *name);
void			file_bytes(t_stg *settings, t_file *file, t_lsl *set);
void			print_col(t_stg *settings, t_file *files);

/*
** Sorting Functions
*/
void			sorting(t_stg *settings, t_file *files, int revers);
int				timeuu_sorting(t_file *first, t_file *second, int revers);
int				timeuu_ascii_sorting(t_file *first, t_file *second, int revers);
int				timec_ascii_sorting(t_file *first, t_file *second, int revers);
int				timec_sorting(t_file *first, t_file *second, int revers);
int				sizess_ascii_sorting(t_file *first, t_file *second, int revers);
int				sizess_sorting(t_file *first, t_file *second, int revers);
int				time_ascii_sorting(t_file *first, t_file *second, int revers);
int				time_sorting(t_file *first, t_file *second, int revers);
int				timeu_ascii_sorting(t_file *first, t_file *second, int revers);
int				timeu_sorting(t_file *first, t_file *second, int revers);

void			flag_err(char c);
void			notes(t_stg *settings, int free, int note, int exit);
void			init_settings(t_stg *settings);
void			push_file(t_file **head, t_file *new);
t_file			*init_file_node(t_stg *settings);
void			file_time(t_stg *settings, t_file *file);
void			free_file_list(t_file **files);
void			free_dir(t_dir **dir);
size_t			list_size(t_file *files);

/*
** Step One:
*/
void			init_main_folders(t_stg *settings, int argc, char **argv);
void			flags_management(t_stg *settings, int argc, char **argv);
t_dir			*init_new_dir(t_stg *settings, char *name);

/*
** Step Two:
*/
void			open_read_print(t_stg *settings, t_dir *dir);
void			run_flag_full(t_stg *settings);

int				link_size(t_file *file);
int				owner_size(t_file *file);
int				group_size(t_file *file);
int				bytes_size(t_file *file);
int				date_size(t_file *file);
int				major_size(t_file *file);
int				minor_size(t_file *file);
void			bonus_d(t_stg *settings);

#endif
