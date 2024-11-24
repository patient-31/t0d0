/*
 * ________________________________________________________________________________
 * |  File: t0d0_macro.h
 * |  Project: includes
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#ifndef  T0D0_MACRO_H
# define T0D0_MACRO_H

# define SUCCESS 	 				STARTSET
# define MEMORY_ALLOCATION_ERROR 	12 // POSIX ENOMEM
# define FILENAME_EINVAL  			22 // POSIX EINVAL
# define FILENAME_ENAMETOOLONG 		36 // POSIX ENAMETOOLONG
# define INVALID_PARAMETER			1
# define ERROR						-1



# define COLUMN_BEG_X				10
# define COLUMN_LIM_X				136
# define COLUMN_BEG_Y				3
# define COLUMN_LIM_Y				34
# define BORDER_RIGHT				139
# define BORDER_BOTTOM				43
# define END_PAGESET				16
# define BOOK_SIZE					8
# define PAGE_SIZE					2048
# define VERSE_PER_PAGE				64
# define VERSE_SIZE					32
# define LINE_SIZE					128
# define FIRST_ROW					3
# define FIRST_COLUMN				9
# define COLUMN_OFFSET				8
# define ROW_OFFSET					2


# define CONFIRM					('y')
# define SAVE						('s')
# define CTRL_s						('s' & 0x1f)
# define CTRL_q 					('q' & 0x1f)
# define CTRL_r						('r' & 0x1f)
# define CTRL_n						('n' & 0x1f)
# define CTRL_b						('b' & 0x1f)
# define CTRL_o						('o' & 0x1f)
# define CTRL_u						('u' & 0x1f)
# define CTRL_c						('c' & 0x1f)
# define CURSOR_RIGHT 				(KEY_RIGHT)
# define CURSOR_LEFT 				(KEY_LEFT)
# define CURSOR_UP 					(KEY_UP)
# define CURSOR_DOWN 				(KEY_DOWN)
# define TAB						('\t')
# define DELETE						(KEY_DC)
# define BACKSPACE					(KEY_BACKSPACE)
# define ENTER						('\n')


# define	STARTSET				 0
# define	_A						 1
# define	_B						 2
# define	_C						 3
# define	_D						 4
# define	_E						 5
# define	_F						 6
# define	_G						 7
# define	_H						 8
# define	_I						 9
# define	_J						10
# define	_K						11
# define	_L						12
# define	_M						13
# define	_N						14
# define	_O						15
# define	_P						16
# define	A_						17
# define	B_						18
# define	C_						19
# define	D_						20
# define	E_						21
# define	F_						22
# define	G_						23
# define	H_						24
# define	I_						25
# define	J_						26
# define	K_						27
# define	L_						28
# define	M_						29
# define	N_						30
# define	O_						31
# define	P_						32
# define   	ENDSET					33
# define	ENDARR					34

# define	P_1						32
# define	P_2						64
# define	P_3						96
# define	P_4						128
# define	P_64					2048			

# define	STARTRA					SUCCESS
# define	STARTKREA				STARTRA
# define   	STARTANU				STARTKREA

# endif