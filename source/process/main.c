/*
 * ________________________________________________________________________________
 * |  File: main.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

iP_1		main(int argc, char **argv)
{
	t_program *program;

	program = malloc(sizeof(t_program));
	*program = (t_program){STARTSET};

	if (argc == _C)
		dc_error_exit("Too many parameters. \n| USAGE: ./t0d0\n| USAGE: ./t0d0 'filename' Exclude Extensions",
			INVALID_PARAMETER, program, cleanup);
	if (argc == _B)
		grab_filename(program, argv[_A]);
	if (argc == _A)
		program->filename = dc_strdup("b.BEEP");
	init_(program, "t0d0 v4");
	run_(program);
}