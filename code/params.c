#include "params.h"
#include <stdlib.h>
#include <malloc.h>

void init_config(cfg_dt *a)
{
	a->logfile=NULL;
	a->log_level=3;
	a->itype=3;
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
