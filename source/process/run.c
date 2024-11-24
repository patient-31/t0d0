/*
 * ________________________________________________________________________________
 * |  File: run.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

none	run_(t_program *o)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(_B, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(_B));

here:
	erase();
	refresh();
	getmaxyx(stdscr, o->rows, o->cols);
	if (o->rows < (BORDER_BOTTOM + _B ) || o->cols < (BORDER_RIGHT + _A))
		mvprintw( _A, _B, "%s", o->constraint); // RESIZE WINDOW
	i_P i;

	i = STARTSET;
	while (i < BORDER_RIGHT)
	{
		mvprintw( STARTSET, i, "_");  // Border-Top
		mvprintw( P_ + _C, i, "_"); // Border-Bottom
		mvprintw( BORDER_BOTTOM, i, "_"); // Border-Bottom-2
		mvprintw( _B, i, "_");  // Border-Top-2
		i++;
	}
	mvprintw( _A, (BORDER_RIGHT - dc_strlen(o->page_str) - _P), "%s", o->page_str);
	mvprintw( _A, (BORDER_RIGHT - dc_strlen(o->verse_no) - _A), "%s", o->verse_no);
	mvprintw( _A, ((BORDER_RIGHT - dc_strlen(o->title)) / _B), "%s", o->title);

	mvprintw( P_ + _D, _B, "%s", o->column_str); mvprintw( P_ + _D, (_E + dc_strlen(o->column_str)), "%s", o->row_str);
	mvprintw( P_ + _J, _B, "%s", o->creator);
	i = STARTSET;
	while (i <= P_ + _J)
	{
		mvprintw( i, STARTSET, "|" ); // border-Ledc
		mvprintw( i, BORDER_RIGHT, "|"); // border-Right
		i++;
	}
	mvprintw( STARTSET, BORDER_RIGHT, "0");  // Top-Right-Corner
	mvprintw( STARTSET, STARTSET, "O");   // Top-Left-Corner
	mvprintw( BORDER_BOTTOM, BORDER_RIGHT, "O"); // Bottom-Right-Corner
	mvprintw( BORDER_BOTTOM, STARTSET, "0");  // Bottom-Left-Corner
	
	

	mvprintw( P_ + _C, _H, "|"); // odd bity
	mvprintw( P_ + _C, BORDER_RIGHT - _B, "|"); // bity bity
	mvprintw( P_ + _E, _B, "    __      ");
    mvprintw( P_ + _F, _B, "   (  y--. ");
	mvprintw( P_ + _G, _B, "  ||_\\/_,'   ");   // BEEP-BEEP
	mvprintw( P_ + _H, _B, "  ('))))))=p");
	mvprintw( P_ + _I, _B, "   < > >    ");
	mvprintw( P_ + _D, (BORDER_RIGHT - dc_strlen(o->quit)) - E_, "%s", o->output);
	mvprintw( P_ + _D, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->next_page);
	mvprintw( P_ + _E, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->prev_page);
	mvprintw( P_ + _F, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->save_file);
	mvprintw( P_ + _G, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->refresh);
	mvprintw( P_ + _H, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->next_verse);
	mvprintw( P_ + _I, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->prev_verse);
	mvprintw( P_ + _J, (BORDER_RIGHT - dc_strlen(o->quit)) - _A, "%s", o->quit);
	mvprintw( P_ + _L, (BORDER_RIGHT - (P_ * _D) + _B), "%s", o->filename);
	
	print_array(o);
	move(o->cursorY, o->cursorX);
	
	refresh();

	switch (o->in = getch())
	{
		case (CTRL_s):
			save_file(o);
			goto here;
		
		case (CTRL_q): //quit
			erase();
			break;

		case (CTRL_r): // redraw
			erase();
			goto here;

		case (CTRL_n): // next verse
			next_verse(o);
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;

		case (CTRL_b): // previous verse
			previous_verse(o);
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;

		case (CTRL_o): // next page
			turn_page(o, '>');
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;

		case (CTRL_u): // previous page
			turn_page(o, '<');
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;

		case (CURSOR_RIGHT): // move cursor
			if (o->cursorX < COLUMN_LIM_X)
				change_row_col_str(o, o->cursorY, o->cursorX++);
			goto here;

		case (CURSOR_LEFT): // move cursor
			if (o->cursorX >= COLUMN_BEG_X)
				change_row_col_str(o, o->cursorY, o->cursorX--);
			goto here;

		case (CURSOR_UP): // move cursor
			if (o->cursorY > COLUMN_BEG_Y)
				change_row_col_str(o, o->cursorY--, o->cursorX);
			goto here;

		case (CURSOR_DOWN): // move cursor
			if (o->cursorY < COLUMN_LIM_Y)
				change_row_col_str(o, o->cursorY++, o->cursorX);
			goto here;

		case (TAB):
			add_4sp_i_H_to__line_(o);
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;

		case (BACKSPACE):
			rm_i_H_from__line_(o);
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;

		case (DELETE):
			rm_i_H_from__line_on_location(o);
			goto here;

		case (ENTER):
			add_nl_to__line_go_to_next_line(o);
			change_row_col_str(o, o->cursorY, o->cursorX);
			goto here;
		
		default:
			if(END_of_ENDVERSE(o) == false)
			{
				if (isprint(o->in))
				{
					add_i_H_to__line_(o);
					change_row_col_str(o, o->cursorY, o->cursorX);
				}
			}
			goto here;
	}

	mvprintw(_D, _E, "You have tried to quit, are you sure?");
	mvprintw(_E, _E, "__'y'__ to quit __'s'__ to save file.");
	switch (o->confirm = getch())
	{
		case (CONFIRM): // quitting
			break;
		case (SAVE):
			save_file(o);
			break;
		default:		// return
			erase();
			refresh();
			goto here;
	}


	cleanup(o); // endwin()
}

witch END_of_ENDVERSE(t_program *o)
{
	if(o->cursorY == COLUMN_LIM_Y)
	{
		if(o->cursorX == COLUMN_LIM_X)
		{
			return (true);
		}
	}
	return (dc_witch("false"));
}





