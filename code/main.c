/*
 * untitled.c
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


#include <stdio.h>

#include "params.h"

#include "sdisys.h"

#include "aaa.h"

#include <wiringPi.h>
#include <mcp23017.h>

#define BASE_I2C        456


PI_THREAD (matrixUpdater)
{
  int i ;

  printf("PI_THREAD enter\n");
  piHiPri (50) ;

  for (i=0;i<1000;i++)
  {
   
           printf("PI_THREAD work\n");
          delayMicroseconds (50) ;
       
  }

  return NULL ;
}

int main(int argc, char **argv)
{
	printf("hello\n");
	
	cfg_dt cfg=load_config(argc,argv);
	printf("config loaded==>loglevel=%d\t\nlogfile=%s\n",cfg.log_level,cfg.logfile);
	
	f(argc, argv);
	
	
	if(1!=f_sysinit(cfg.itype,cfg.use_exit_critical_function))
	{ 
		release_config(&cfg);
		return 1;
     }
     else if(cfg.itype!=3)
     {
	
	  mcp23017Setup (BASE_I2C, 0x20) ;
	  
	
	// For the push button to stop it...

  pinMode         (BASE_I2C + 15, INPUT) ;
  pullUpDnControl (BASE_I2C + 15, PUD_UP) ;
  
  while (digitalRead (BASE_I2C + 15) == 0)
        delay (1) ;
  }
  
    piThreadCreate (matrixUpdater) ;
     while(getchar()!=32);
	release_config(&cfg);
	return 0;
}

