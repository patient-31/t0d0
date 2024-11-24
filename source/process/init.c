/*
 * ________________________________________________________________________________
 * |  File: init.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

none	init_(t_program *o, i_H * title)
{
	i_P	i;

	o->verse_no_len = _J;
	o->page_index	= _A; 
	o->md_qset		= _A;
	o->pattern_d	= _A;
	o->cursorX = FIRST_COLUMN; o->cursorY = FIRST_ROW;
	
	// init page numbers pattern
	o->md_pattern_descriptor			= (char **)malloc(sizeof(char *) * ENDARR + _A);
	if (!o->md_pattern_descriptor)
		ERROR_MEM(o);

	o->md_pattern_descriptor[STARTSET]	= dc_strdup("STARTSET");
	o->md_pattern_descriptor[_A]		= dc_strdup("_A");		   
	o->md_pattern_descriptor[_B]		= dc_strdup("_B");		
	o->md_pattern_descriptor[_C]		= dc_strdup("_C");		
	o->md_pattern_descriptor[_D]		= dc_strdup("_D");		
	o->md_pattern_descriptor[_E]		= dc_strdup("_E");		
	o->md_pattern_descriptor[_F]		= dc_strdup("_F");		
	o->md_pattern_descriptor[_G]		= dc_strdup("_G");		
	o->md_pattern_descriptor[_H]		= dc_strdup("_H");		
	o->md_pattern_descriptor[_I]		= dc_strdup("_I");		
	o->md_pattern_descriptor[_J]		= dc_strdup("_J");		
	o->md_pattern_descriptor[_K]		= dc_strdup("_K");		
	o->md_pattern_descriptor[_L]		= dc_strdup("_L");		
	o->md_pattern_descriptor[_M]		= dc_strdup("_M");		
	o->md_pattern_descriptor[_N]		= dc_strdup("_N");		
	o->md_pattern_descriptor[_O]		= dc_strdup("_O");		
	o->md_pattern_descriptor[_P]		= dc_strdup("_P");		
	o->md_pattern_descriptor[A_]		= dc_strdup("A_");		
	o->md_pattern_descriptor[B_]		= dc_strdup("B_");		
	o->md_pattern_descriptor[C_]		= dc_strdup("C_");		
	o->md_pattern_descriptor[D_]		= dc_strdup("D_");		
	o->md_pattern_descriptor[E_]		= dc_strdup("E_");		
	o->md_pattern_descriptor[F_]		= dc_strdup("F_");		
	o->md_pattern_descriptor[G_]		= dc_strdup("G_");		
	o->md_pattern_descriptor[H_]		= dc_strdup("H_");		
	o->md_pattern_descriptor[I_]		= dc_strdup("I_");		
	o->md_pattern_descriptor[J_]		= dc_strdup("J_");		
	o->md_pattern_descriptor[K_]		= dc_strdup("K_");		
	o->md_pattern_descriptor[L_]		= dc_strdup("L_");		
	o->md_pattern_descriptor[M_]		= dc_strdup("M_");		
	o->md_pattern_descriptor[N_]		= dc_strdup("N_");		
	o->md_pattern_descriptor[O_]		= dc_strdup("O_");		
	o->md_pattern_descriptor[P_]		= dc_strdup("P_");
	o->md_pattern_descriptor[ENDSET]	= dc_strdup("ENDSET");
	o->md_pattern_descriptor[ENDARR]	= NULL;


	i = STARTSET;
	while (o->md_pattern_descriptor[i])
	{
		i++;
	} if (i != ENDARR) {	ERROR_MEM(o);	}

	o->title 			= dc_strdup(title);
	o->creator 			= dc_strdup("Created by Danielle [pippin-29]");
	o->quit 			= dc_strdup("QUITT -- __ctrl_q__");
	o->next_verse 		= dc_strdup("NVERS -- __ctrl_n__");
	o->prev_verse 		= dc_strdup("PVERS -- __ctrl_b__");
	o->save_file 		= dc_strdup("SAVEF -- __ctrl_s__");
	o->refresh 			= dc_strdup("RFRSH -- __ctrl_r__");
	o->next_page		= dc_strdup("NPAGE -- __ctrl_o__");
	o->prev_page		= dc_strdup("PPAGE -- __ctrl_u__");
	o->output			= dc_strdup("OUTPT -- __ctrl_c__");
	o->row				= dc_strdup("ROW: ");
	o->win_row			= (o->cursorY - ROW_OFFSET);
	o->row_index		= dc_itoa(o->win_row);
	o->row_str			= dc_strjoin_e(_B, o->row, o->row_index);
	o->column			= dc_strdup("COLUMN: ");
	o->win_col			= (o->cursorX - COLUMN_OFFSET);
	o->column_index		= dc_itoa(o->win_col);
	o->column_str		= dc_strjoin_e(_B, o->column, o->column_index);
	o->filename_s		= dc_strdup("FILENAME -- ");
	o->constraint 		= dc_strdup("++RESIZEWINDOW++");
	o->page				= dc_strdup("PAGE: ");
	o->page_str_index	= dc_itoa(o->page_index);
	o->page_str			= dc_strjoin_e(_B, o->page, o->page_str_index);
	o->verse_str		= dc_strdup("VERSE: ");
	o->md_qset_str		= dc_itoa(o->md_qset);
	o->verse_no			= dc_strjoin_e(_C, o->verse_str, o->md_pattern_descriptor[o->pattern_d] ,o->md_qset_str);
	
	if ( 	!o->title 		|| !o->creator 		|| !o->quit 		||	!o->column_str		|| !o->column_index	||	!o->row_index	||
			!o->next_verse 	|| !o->prev_verse 	|| !o->save_file 	||	!o->next_page		|| !o->column		||	!o->row_str		||
			!o->refresh 	|| !o->constraint 	|| !o->verse_no		||	!o->prev_page		|| !o->row			||
			!o->verse_str	|| !o->md_qset_str	|| !o->page_str		||	!o->page_str_index	)
	{
		ERROR_MEM(o);
	}

	if (!load_file(o))
		init__line_(o);

	init_line_no(o);

}

none	init_line_no(t_program *o)
{
	i_P	ra;

	ra = _A;
	o->line_no = malloc(sizeof(int) * P_);
	if (!o->line_no)
		ERROR_MEM(o);
	while (ra < ENDSET)
	{
		o->line_no[ra - _A] = ra;
		ra++;
	}
	ra = STARTSET;
}

none	init__line_(t_program *o)
{
	o->_line_ = malloc(sizeof(char**) * (BOOK_SIZE));
	if (!o->_line_)
		ERROR_MEM(o);
	i_P	i;
	i_P	q;
	i_P	b;

	i = STARTSET;
	q = STARTSET;
	b = STARTSET;
	while (i < BOOK_SIZE)
	{
		o->_line_[i] = malloc(sizeof(char *) * (PAGE_SIZE));
		if (!o->_line_[i])
			ERROR_MEM(o);

		q = STARTSET;
		while (q < PAGE_SIZE)
		{
			o->_line_[i][q] = malloc(sizeof(char) * (LINE_SIZE));
			if (!o->_line_[i][q])
				ERROR_MEM(o);
				
			b = STARTSET;
			while(b < LINE_SIZE)
			{
				// printf("%d", b);
				o->_line_[i][q][b] = ' ';
				b++;
			}
			q++;
		}
		i++;
	}
}
