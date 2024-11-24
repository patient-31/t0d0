/*
 * ________________________________________________________________________________
 * |  File: page.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

none	change_row_col_str(t_program *o, i_P cursorY, i_P cursorX)
{
	if (o->row_index)
		free(o->row_index);
	o->win_row = (o->cursorY - ROW_OFFSET);
	o->row_index = dc_itoa(o->win_row);
	if (!o->row_index)
		ERROR_MEM(o);

	if (o->row_str)
		free(o->row_str);
	o->row_str = dc_strjoin_e(_B, o->row, o->row_index);
	if (!o->row_str)
		ERROR_MEM(o);



	if (o->column_index)
		free(o->column_index);
	o->win_col = (o->cursorX - COLUMN_OFFSET);
	o->column_index = dc_itoa(o->win_col);
	if (!o->row_index)
		ERROR_MEM(o);

	if (o->column_str)
		free(o->column_str);
	o->column_str = dc_strjoin_e(_B, o->column, o->column_index);
	if (!o->column_str)
		ERROR_MEM(o);
}

none	turn_page(t_program *o, i_H lr)
{
	if (o->page_index < BOOK_SIZE && lr == '>')
		o->page_index += _A;
	else if (o->page_index > _A && lr == '<' )
		o->page_index -= _A;
	else return ;
	if (o->page_str_index)
		free(o->page_str_index);
	o->page_str_index = dc_itoa(o->page_index);
	if (!o->page_str_index)
		ERROR_MEM(o);
	if (o->page_str)
		free(o->page_str);
	o->page_str = dc_strjoin_e(_B, o->page, o->page_str_index);
	if(!o->page_str)
		ERROR_MEM(o);
	if (lr == '>')
		o->md_qset += _B;
	
	if (lr == '<')	
		o->md_qset -= _B;
	if (o->md_qset_str)
		free(o->md_qset_str);
	o->md_qset_str = dc_itoa(o->md_qset);
	if (!o->md_qset_str)
		ERROR_MEM(o);
	if (o->verse_no)
		free(o->verse_no);
	o->verse_no = dc_strjoin_e(_C, o->verse_str, o->md_pattern_descriptor[o->pattern_d], o->md_qset_str);
	if (!o->verse_no)
		ERROR_MEM(o);
	o->cursorX = FIRST_COLUMN;
	o->cursorY = FIRST_ROW;

}

none	next_verse(t_program *o)
{
	if (o->pattern_d == P_ && o->md_qset == END_PAGESET)
		return ;
	if (o->pattern_d == P_)
	{
		o->pattern_d = STARTSET;
		while (o->pattern_d)
		{ ERROR_MEM(o); }
		o->md_qset++;
		if (o->md_qset_str)
			free(o->md_qset_str);
		o->md_qset_str = dc_itoa(o->md_qset);
		if (!o->md_qset_str)
			ERROR_MEM(o);
	}
	if (o->verse_no)
		free(o->verse_no);
	o->verse_no = dc_strjoin_e(_C, o->verse_str, o->md_pattern_descriptor[++o->pattern_d], o->md_qset_str);
	if (!o->verse_no)
		ERROR_MEM(o);
	iterate_line_no('+', o);

	if (o->pattern_d == _A && (o->md_qset % _B) == _A)
	{
		o->page_index += _A;
		if (o->page_str_index)
			free(o->page_str_index);
		o->page_str_index = dc_itoa(o->page_index);
		if (!o->page_str_index)
			ERROR_MEM(o);
		if (o->page_str)
			free(o->page_str);
		o->page_str = dc_strjoin_e(_B, o->page, o->page_str_index);
		if(!o->page_str)
			ERROR_MEM(o);
		reset_line_no('>',o);
	}
	o->cursorX = FIRST_COLUMN;
	o->cursorY = FIRST_ROW;

}

none	previous_verse(t_program *o)
{
	if (o->pattern_d == _A && o->md_qset == _A)
		return ;
  	if (o->pattern_d == _A)
	{
		o->pattern_d = ENDSET;
		while (o->pattern_d != ENDSET)
		{ ERROR_MEM(o); }
		if (o->md_qset > _A)
		{
			o->md_qset--;
			if (o->md_qset_str)
				free(o->md_qset_str);
			o->md_qset_str = dc_itoa(o->md_qset);
			if (!o->md_qset_str)
				ERROR_MEM(o);
		}	
	}
	if (o->verse_no)
		free(o->verse_no);
	o->verse_no = dc_strjoin_e(_C, o->verse_str, o->md_pattern_descriptor[--o->pattern_d], o->md_qset_str);
	if (!o->verse_no)
		ERROR_MEM(o);
	iterate_line_no('-', o);

	if (o->pattern_d == P_ && (o->md_qset % _B) == STARTSET)
	{
		o->page_index -= _A;
		if (o->page_str_index)
			free(o->page_str_index);
		o->page_str_index = dc_itoa(o->page_index);
		if (!o->page_str_index)
			ERROR_MEM(o);
		if (o->page_str)
			free(o->page_str);
		o->page_str = dc_strjoin_e(_B, o->page, o->page_str_index);
		if (!o->page_str)
			ERROR_MEM(o);
		reset_line_no('<',o);
	}
	o->cursorX = FIRST_COLUMN;
	o->cursorY = FIRST_ROW;

}

none	iterate_line_no(i_H mm, t_program *o)
{
	i_P	i;

	i = STARTSET;
	while (i < P_)
	{
		if (mm == '+')
			o->line_no[i] += P_;
			
		if (mm == '-')
			o->line_no[i] -= P_;
				
		i++;
	}
}

none	reset_line_no(i_H lr, t_program *o)
{
	i_P	i;
	i_P	q;

	i = O_;
	q = STARTSET;
	while (i != -_A)
	{
		if (lr == '<')
			o->line_no[i] = (P_ * _B * P_) - q;
		if (lr == '>')
			o->line_no[i] = (P_ - q);	
		i--;
		q++;
	}
}


