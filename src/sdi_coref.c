/*
 * sdi_coref.c
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

#include "sdi_coref.h"


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include <semaphore.h>

#define TRUE 1
#define FALSE 0


pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond;

char n[1024];

int globalwork=TRUE;

int string_read=FALSE;

void * thread1()
{
        while(globalwork){
                while(string_read);
                pthread_mutex_lock(&lock);
                printf("Enter a string: ");
                scanf("%s",n);
                string_read=TRUE;
                pthread_mutex_unlock(&lock);
                pthread_cond_signal(&cond);
        }
}

void * thread2()
{
        while(globalwork){
               
                pthread_mutex_lock(&lock);
                printf("pthread_cond_wait2\n");
                while(!string_read)
                 pthread_cond_wait(&cond,&lock);
                  if(strlen(n)>0){
                  printf("The string entered is %s\n",n);
                 if(strstr(n,"exit")==0){
					  globalwork=FALSE;
                 }
                  string_read=FALSE;}
                  pthread_mutex_unlock(&lock);
        }
}

void * thread3()
{
	 while(globalwork){
		 sleep(5);
		 }
	}
	


int coref_start(int argc, char **argv)
{

 pthread_t tr, tw,tw3;

        pthread_create(&tr,NULL,thread1,NULL);
        pthread_create(&tw,NULL,thread2,NULL);
        pthread_create(&tw3,NULL,thread3,NULL);
         
        

        pthread_join(tr,NULL);
        pthread_join(tw,NULL);
        pthread_join(tw3,NULL);
        
 return 0;
}
