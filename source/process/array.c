/*
 * ________________________________________________________________________________
 * |  File: array.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

none	print_array(t_program *o)
{
	i_P i = _A;
	i_P q = _A;

	while (i <= P_)
	{
		mvprintw( (i + ROW_OFFSET) , _A, "__%04d_|", o->line_no[i - _A]);
		q = _A;
		while (q <= LINE_SIZE)
		{
			mvprintw( i + ROW_OFFSET, q + COLUMN_OFFSET, "%c", o->_line_[o->page_index - _A][o->line_no[i - _A] - _A][q - _A]);
			q++;
		}
		mvprintw( i + ROW_OFFSET, BORDER_RIGHT - _B, "|");
		mvprintw( i + ROW_OFFSET, BORDER_RIGHT - _A, "0");
		i++;
	}
}



none	add_4sp_i_H_to__line_(t_program *o)
{
	i_P	x = o->cursorX - FIRST_COLUMN;
	i_P	y = o->cursorY - FIRST_ROW;
	if (x >= (P_ * _D) - _D)
		return ;
	o->_line_[o->page_index - _A][o->line_no[y] - _A][x + STARTSET] = ' ';
	o->_line_[o->page_index - _A][o->line_no[y] - _A][x + _A] = ' ';
	o->_line_[o->page_index - _A][o->line_no[y] - _A][x + _B] = ' ';
	o->_line_[o->page_index - _A][o->line_no[y] - _A][x + _C] = ' ';
	o->cursorX += _D;

	if (o->cursorX == COLUMN_LIM_X + _A)
	{
		o->cursorX = FIRST_COLUMN;
		if (o->cursorY < (COLUMN_LIM_Y))
			o->cursorY += _A;
		else
		{
			o->cursorY = FIRST_ROW;
			o->cursorX = FIRST_COLUMN;
			next_verse(o);
		}
	}
}



none	rm_i_H_from__line_on_location(t_program *o)
{
	i_P	x = o->cursorX - FIRST_COLUMN;
	i_P	y = o->cursorY - FIRST_ROW;
	if (o->cursorX >= FIRST_COLUMN)
		o->_line_[o->page_index - _A][o->line_no[y] - _A][x] = '\b';
}

none	add_nl_to__line_go_to_next_line(t_program *o)
{
		i_P	x = o->cursorX - FIRST_COLUMN;
		i_P	y = o->cursorY - FIRST_ROW;
		o->_line_[o->page_index - _A][o->line_no[y] - _A][x] = '\n';
		if (o->cursorY < COLUMN_LIM_Y)
		{
			o->cursorY += _A;
			o->cursorX = FIRST_COLUMN;		
		}		
}

none	add_i_H_to__line_(t_program *o)
{
	i_P	x = o->cursorX - FIRST_COLUMN;
	i_P	y = o->cursorY - FIRST_ROW;
	o->_line_[o->page_index - _A][o->line_no[y] - _A][x] = o->in;
	o->cursorX += _A;
	if (o->cursorX == COLUMN_LIM_X + _A)
	{
		o->cursorX = FIRST_COLUMN;
		if (o->cursorY < (COLUMN_LIM_Y))
			o->cursorY += _A;
		// else
		// {
		// 	o->cursorY = FIRST_ROW;
		// 	o->cursorX = FIRST_COLUMN;
		// 	next_verse(o);
		// }
	}	
}

none	move_line_back(t_program *o, i_P x, i_P y)
{
	i_P i;
	i_H c;

	i = x;
	while (i < LINE_SIZE)
	{
		c = o->_line_[o->page_index - _A][o->line_no[y] - _A][i + 1];
		o->_line_[o->page_index - _A][o->line_no[y] - _A][i] = c;
		
		i += _A;
	}
	o->_line_[o->page_index - _A][o->line_no[y] - _A][LINE_SIZE - _A] = ' ';
}

none	rm_i_H_from__line_(t_program *o)
{
	i_P	x = o->cursorX - FIRST_COLUMN;
	i_P	y = o->cursorY - FIRST_ROW;
	if (o->cursorX == FIRST_COLUMN && o->cursorY != FIRST_ROW)
	{
		o->_line_[o->page_index - _A][o->line_no[y] - _A][x] = '\b';
		o->cursorX = COLUMN_LIM_X + _A;
		x = o->cursorX - FIRST_COLUMN;
		o->cursorY -= _A;
		y = o->cursorY - FIRST_ROW;
	}
	if (o->cursorX > FIRST_COLUMN)
	{
		o->_line_[o->page_index - _A][o->line_no[y] - _A][x] = '\b';
		o->cursorX -= _A;
		move_line_back(o, x, y);
	}
}

