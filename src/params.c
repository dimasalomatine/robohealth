/*
 * params.c
 * 
 * Copyright 2014 dima <dima@debian>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include "params.h"
#include <stdlib.h>
#include <malloc.h>

void init_config(cfg_dt *a)
{
	a->logfile=NULL;
	a->log_level=3;
	a->itype=1;
	a->use_exit_critical_function=0;
	}

cfg_dt load_config(int argc, char **argv)
{
	cfg_dt ret;
	init_config(&ret);
	printf ( "<enter>load_config\n") ;
	ret.logfile=(char*)malloc(512);
	if(ret.logfile!=NULL)
	{
		sprintf(ret.logfile,"%s","log.txt");
		}
	printf ( "<exit>load_config\n") ;
	return ret;
	}
	
	void release_config(cfg_dt *a)
	{
		printf ( "<enter>release_config\n") ;
		if(a->logfile!=NULL)
		{
			free(a->logfile);
			a->logfile=NULL;
			}
		printf ( "<exit>release_config\n") ;
		}
