/*
 * ________________________________________________________________________________
 * |  File: t0d0_types.h
 * |  Project: includes
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#ifndef  T0D0_TYPES_H
# define T0D0_TYPES_H

typedef unsigned char			u_H;
typedef unsigned short			u_P;
typedef unsigned int			uP_1;
typedef unsigned long			uP_2;

typedef char					i_H;
typedef short					i_P;
typedef int						iP_1;
typedef long					iP_2;

typedef	void					t_cleanup_function;
typedef	void					error;
typedef void					none;
typedef bool					witch;


typedef struct 	s_t0d0 
{
	// Arrays for each line
	i_H		***_line_;

	// Strings
	i_H 	*title;
	i_H		*creator;
	i_H 	*quit;
	i_H		*next_verse;
	i_H		*prev_verse;
	i_H		*next_page;
	i_H		*prev_page;
	i_H		*save_file;
	i_H		*refresh;
	i_H		*constraint;
	i_H		*filename;
	i_H		*row;
	i_H		*row_str;
	i_H		*row_index;
	i_H		*verse_no;
	i_H		*column;
	i_H		*column_str;
	i_H		*column_index;
	i_H		*verse_str;
	i_H		*md_qset_str;
	i_H		*page;
	i_H		*page_str;
	i_H		*filename_s;
	i_H		*page_str_index;
	i_H		*output;

	// enviroment
	i_P		rows;
	i_P		cols;
	i_P		cursorX;
	i_P		cursorY;
	i_P		md_qset;
	i_P		pattern_d;
	i_P		page_index;
	i_P		verse_no_len;
	i_P		*line_no;
	iP_1 	f;
	i_P		win_row;
	i_P 	win_col;


	// keyboard controls
	iP_1	in; 
	i_H		confirm;

	// Pattern Descriptors
	i_H	**md_pattern_descriptor;

} t_program;

typedef	void		(*p_cleanup_function)(t_program *);

# endif