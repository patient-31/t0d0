/*
 * ________________________________________________________________________________
 * |  File: free.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

t_cleanup_function cleanup(t_program *o)
{
if (o->title)
	free(o->title);
if (o->creator)
	free(o->creator);
if (o->quit)
	free(o->quit);
if (o->next_verse)
	free(o->next_verse);
if (o->prev_verse)
	free(o->prev_verse);
if (o->next_page)
	free(o->next_page);
if (o->prev_page)
	free(o->prev_page);
if (o->save_file)
	free(o->save_file);
if (o->refresh)
	free(o->refresh);
if (o->constraint)
	free(o->constraint);
if (o->verse_no)
	free(o->verse_no);
if (o->md_qset_str)
	free(o->md_qset_str);
if (o->verse_str)
	free(o->verse_str);
if (o->row)
	free(o->row);
if (o->row_index)
	free(o->row_index);
if (o->row_str)
	free(o->row_str);
if (o->page)
	free(o->page);
if (o->page_str)
	free(o->page_str);
if (o->page_str_index)
	free(o->page_str_index);
if (o->column_index)
	free(o->column_index);
if (o->column_str)
	free(o->column_str);
if (o->column)
	free(o->column);
if (o->filename)
	free(o->filename);
if (o->filename_s)
	free(o->filename_s);
if (o->md_pattern_descriptor)
	dc_free_2d_i_H(o->md_pattern_descriptor, ENDARR);
if (o->_line_)
	dc_free_3d_i_H(o->_line_, BOOK_SIZE, PAGE_SIZE);
if (o->line_no)
	free(o->line_no);
if (o->output)
	free(o->output);
if (o)
	free(o);
endwin();
}


