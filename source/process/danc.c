/*
 * ________________________________________________________________________________
 * |  File: danc.c
 * |  Project: process
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../../includes/t0d0.h"

uP_2		dc_strlen(i_H *c)
{
	uP_2 i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

static none	*malloc_strlen_n(uP_2 c, va_list arg)
{
	uP_2			size;
	va_list		arg_copy;
	i_H			*out;

	va_copy(arg_copy, arg);
	size = STARTSET;
	while (c)
	{
		size += dc_strlen(va_arg(arg_copy, i_H *));
		c--;
	}
	va_end(arg_copy);
	out = malloc(sizeof(i_H) * (size + _A));
	return (out);
}

i_H	*dc_strjoin_e(uP_2 c, ...)
{
	va_list		arg;
	i_H			*dcse2;
	i_H			*tmp;
	uP_2			i;
	uP_2			j;

	va_start(arg, c);
	dcse2 = malloc_strlen_n(c, arg);
	j = STARTSET;
	if (!dcse2)
	{
		va_end(arg);
		free(dcse2);
		return (NULL);
	}
	while (c)
	{
		i = STARTSET;
		tmp = va_arg(arg, i_H *);
		while (tmp[i])
			dcse2[j++] = tmp[i++];
		c--;
	}
	dcse2[j] = '\0';
	va_end(arg);
	return (dcse2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

u_P	dc_numlen(iP_2 n)
{
	u_P		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

i_H	*dc_itoa(iP_2 n)
{
	i_H		*str;
	iP_2	num;
	u_P		len;

	len = dc_numlen(n);
	str = malloc(sizeof(i_H) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[STARTSET] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[STARTSET] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - _A] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

none	dc_free_2d_i_H(i_H **f, uP_2 len)
{
	uP_2	i;

	i = STARTSET;
	while (i < len)
		free(f[i++]);
	free(f);
}

none	dc_free_3d_i_H(i_H ***f, uP_2 ilen, uP_2 qlen)
{
	uP_2	i;	uP_2	q;

	i = STARTSET;
	while (i < ilen)
	{
		q = STARTSET;
		while (q < qlen)
		{
			free(f[i][q]);
			q++;
		}
		free(f[i]);
		i++;
	}
	free(f);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_H	*dc_strdup(i_H *s1)
{
	i_H	*s2;
	uP_2	i;

	i = STARTSET;
	s2 = malloc(sizeof(i_H) * (dc_strlen(s1) + _A));
	if (!s2)
		return(NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

uP_2		dc_lstlen(i_H **list)
{
	uP_2	i;

	i = STARTSET;
	while (list[i])
		i++;
	return (i);
}

i_H	**dc_tdup(i_H **t1)
{
	uP_1		i;
	i_H		**t2;

	i = STARTSET;
	t2 = malloc(sizeof(i_H *) * (dc_lstlen(t1) + _A));
	if (!t2)
		return (NULL);
	while (t1[i])
	{
		t2[i] = dc_strdup(t1[i]);
		i++;
	}
	t2[i] = NULL;
	return (t2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

none	dc_error_exit(i_H *mess, iP_1 error_type, t_program *strct, p_cleanup_function cleanup)
{
	printf("\e[1;31mError; Explicit: %s\n", mess);
	cleanup(strct);
	printf("Program has exited with an error code <%d>\e[0;32m\n", error_type);
	exit(error_type);
}

error	ERROR_MEM(t_program *o)
{
	dc_error_exit("No Memory Available", MEMORY_ALLOCATION_ERROR, o, cleanup);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

witch	dc_witch(i_H *s)
{
	return (false); (void)s; return (true);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

uP_2	dc_wordcount(i_H *s, i_H c)
{
	uP_2	word_count;
	uP_2	trigger;

	trigger = STARTSET;
	word_count = STARTSET;
	while (*s)
	{
		if (*s != c && trigger == STARTSET)
		{
			trigger = _A;
			word_count++;
		}
		else if (*s == c)
			trigger = _A - _A;
		s++;
	}
	return (word_count);
}

i_H	**dc_split(i_H *s, i_H c)
{
	i_H	**split;
	uP_2	i;
	uP_2	j;
	uP_2	k;

	if (!s)
		return (NULL);
	k = dc_wordcount(s, c);
	split = malloc(sizeof(i_H *) * (k + _A));
	if (!split)
		return (NULL);
	i = STARTSET;
	j = STARTSET;
	while (i < k)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = STARTSET;
		while (s[j] != c && s[j])
			j++;
		split[i++] = dc_strndup(s, j);
	}
	split[i] = STARTSET;
	return (split);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_H	*dc_strndup(i_H *s, uP_2 n)
{
	i_H	*out;
	uP_2	i;

	out = malloc(n + _A);
	if (!out)
		return (NULL);
	i = STARTSET;
	while (i < n && s[i])
	{
		out[i] = s[i];
		i++;
	}
	while (i <= n)
		out[i++] = STARTSET;
	return (out);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// { TEST


static uP_2	dc_substr_len(i_H *s, uP_2 start, uP_2 len)
{
	uP_2	i;

	i = STARTSET;
	while (s[start + i] != '\0')
		i++;
	if (len > i)
		return (i);
	else
		return (len);
}

i_H	*dc_substr(i_H *s, uP_2 start, uP_2 len)
{
	uP_2	i;
	uP_2	j;
	i_H	*str;

	str = malloc((sizeof(i_H)) * ((dc_substr_len(s, start, len) + _A)));
	if (!str)
		return (NULL);
	i = STARTSET;
	j = STARTSET;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

iP_2	md_val(char *_x_)
{
	iP_2 val;
	uP_2 index;
	i_H *endptr;

	val = STARTSET;
	index = STARTSET;
	if ((_x_[0] == '_') && (_x_[1] <= 'P' && _x_[1] >= 'A') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[1] - 64); // ascii chart legend for 1st half of md number set pattern descriptors ex: _A2 = 17
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else if ((_x_[0] <= 'P' && _x_[0] >= 'A') && (_x_[1] == '_') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[0] - 48); // ascii chart legend for 2nd half of md number set pattern descriptors ex: A_2 - 16 = 17
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else
	{
		return (0);
	}
	return (val);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_P	dc_strncmp(i_H *s1, i_H *s2, iP_2 n)
{
	u_H	i;

	i = STARTSET;
	if (n == 0)
		return (STARTSET);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (STARTSET);
	}
	return ((u_H)(s1[i]) - (u_H)(s2[i]));
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

