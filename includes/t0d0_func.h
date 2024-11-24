/*
 * ________________________________________________________________________________
 * |  File: t0d0_func.h
 * |  Project: includes
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#ifndef  T0D0_FUNC_H
# define T0D0_FUNC_H

// PROCESS/ARRAY_C
none				print_array(t_program *o);						// custom function -- prints i_H ***o->_line_ across T0D0 book 1
none				add_i_H_to__line_(t_program *o);				// adds i_H to specfic 1 byte location in ***o->_line_ according to cursor location
none				add_4sp_i_H_to__line_(t_program *o);			// adds 4 spaces inline and moves cursor +4
none				rm_i_H_from__line_(t_program *o);				// backspaces i_H from ***o->_line_ according to cursor location and moves cursor -1
none				rm_i_H_from__line_on_location(t_program *o);	// deletes i_H from ***o->_line_ according to cursor location does not move cursor
none				add_nl_to__line_go_to_next_line(t_program *o);
none				move_line_back(t_program *o, i_P x, i_P y);		// moves a single line from program back when using backspace key

// PROCESS/DANC_C
iP_2				md_val(char *_x_);
i_H					*dc_strjoin_e(uP_2 c, ...);						// variable number string joiner
i_H					*dc_itoa(iP_2 n);								// integer to ascii
uP_2				dc_strlen(i_H *c); 								// counts string
i_H					*dc_strdup(i_H *s1); 							// creates pointer and replicates the reference
i_H					**dc_tdup(i_H **t1);							// creates pointer to pointer array and replicates all references
none				dc_free_2d_i_H(i_H **f, uP_2 len);				// frees 2d i_H array
none				dc_free_3d_i_H(i_H ***f, uP_2 ilen, uP_2 qlen);	// frees 3d i_H array 
uP_2				dc_lstlen(i_H **list);							// returns length of 2d list
witch				dc_witch(i_H *s);								// checks if witch returns false -> returns true
i_H					*dc_substr(i_H *s, uP_2 start, uP_2 len);		// grabs a section of a string from start to (start + len)
i_H					*dc_strndup(i_H *s, uP_2 n);					// creates a pointer and replicates the reference up to size n
uP_2				dc_wordcount(i_H *s, i_H c);					// for dc_split, counts words.
i_H					**dc_split(i_H *s, i_H c);						// takes string as input and splits into tokens based on delimiter c
i_P					dc_strncmp(i_H *s1, i_H *s2, iP_2 n);			// compares two strings up to n and returns comparison.															
none				dc_error_exit(i_H *mess, 						// Assign verbose message for clear error determination
						iP_1 error_type,							// Assign error code for terminal output on error
							t_program *strct, 						// Assign custom cleanup for strct {o - in this program} with type 
								p_cleanup_function cleanup);		// t_cleanup_function (none) for technical presentation and debugging
error				ERROR_MEM(t_program *o);

// PROCESS/FILE_C
iP_1				load_file(t_program *o);
none				save_file(t_program *o);
none				grab_filename(t_program *o, i_H *parameter);	// takes cmd argument for parameter adds ".BEEP" and checks invalid character choices

// PROCESS/FREE_C
t_cleanup_function	cleanup(t_program *o);							// program specific function for use with dc_error_exit

// PROCESS/INIT_C
none				init_(t_program *o, i_H * title);							// initialisation
none				init_line_no(t_program *o);						// init line numbers for verses
none				init__line_(t_program *o);						// init book for '64 verse' pages (8)

// PROCESS/PAGE_C
none				change_row_col_str(t_program *o, i_P cursorY, i_P cursorX); // takes cursor location and updates win_col and row_col variables for string creation
none				turn_page(t_program *o, i_H lr);				// proceeds md_qset by 2 (64 verse) (lr == '<' || lr == '>')
none				next_verse(t_program *o);						// proceeds to next verse, pattern_d +1
none				previous_verse(t_program *o);					// proceeds to previous verse, pattern_d -1
none				reset_line_no(i_H lr, t_program *o);			// resets line numbers to start or end of page (lr == '<' || lr == '>')
none				iterate_line_no(i_H mm, t_program *o);			// iterates line numbers on verse change by 32 (mm == '-' || mm == '+')

// PROCESS/RUN_C
witch 				END_of_ENDVERSE(t_program *o);					// finds the end of the universe
none				run_(t_program *o);								// draws window in ncurses utility, switch statement for input casing
																	// uses goto statement and label here: for redraw after input, FLASHES
																	// my computer could be slow... ?


# endif