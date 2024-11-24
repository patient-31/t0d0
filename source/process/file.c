/*
 * ________________________________________________________________________________
 * |  File: file.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

none	grab_filename(t_program *o, char *parameter)
{
	i_P	i;
	i_H	*new_filename;
	new_filename = dc_strjoin_e(_B, parameter, ".BEEP");
	i = STARTSET;
	while (parameter[i])
	{
		if (parameter[i] == ':' ||
			parameter[i] == ';' ||
			parameter[i] == '<' ||
			parameter[i] == '>' || 
			parameter[i] == '|' || 
			parameter[i] == '/' ||
			parameter[i] == '*' ||
			parameter[i] == '^' ||
			parameter[i] == '%' ||
			parameter[i] == '{' ||
			parameter[i] == '}' ||
			parameter[i] == '\\' ||
			parameter[i] == '~' ||
			parameter[i] == '$')
			{
				dc_error_exit(" Characters [ ';' ':' '<' '>' '/' '\' '$' '~' '{' '}' '%%' '^' '*' ] disallowed.", 
								FILENAME_EINVAL, o, cleanup);						 
			}
		i++;
		if (i == LINE_SIZE)
			dc_error_exit("Filename 2 Long... please describe your filenames with less than 128 characters.", 
							FILENAME_ENAMETOOLONG, o, cleanup); 											  
	}
	o->filename = dc_strdup(new_filename);
	free(new_filename);
}

none	save_file(t_program *o)
{
	o->f = open(o->filename, O_WRONLY | O_CREAT, 0644);

	i_P	i;
	i_P	q;
	i_P	b;

	i = STARTSET;
	q = STARTSET;
	b = STARTSET;

	while (i < BOOK_SIZE)
	{
		q = STARTSET;
		while (q < PAGE_SIZE)
		{
			b = STARTSET;
			while(b < LINE_SIZE)
			{
				write(o->f, &o->_line_[i][q][b], _A);
				b++;
			}
			q++;
		}
		i++;
	}
	close(o->f);
}

iP_1	load_file(t_program *o)
{
	o->_line_ = malloc(sizeof(char**) * (BOOK_SIZE));
	if (access(o->filename, F_OK) == -_A)
		return dc_witch("nothing");
		
	
	o->f = open(o->filename, O_RDWR);
	if (o->f == -_A)
        dc_error_exit("Failed to open file", FILENAME_EINVAL, o, cleanup);

	i_P	i;
	i_P	q;
	i_P b;

	
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
			while (b < LINE_SIZE)
			{
				// printf("%d", b);
				read(o->f, &o->_line_[i][q][b], _A);
				b++;
			}
			q++;
		}
		i++;
	}
	close(o->f);
	return _A;
}
