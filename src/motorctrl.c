
#include <stdio.h>
#include <wiringPi.h>

#include "motorctrl.h"

static int s_baseaddr=0x20, 
           s_ctrlA=1, 
           s_Actrl1=2,
           s_Actrl2=3,
           s_ctrlB=1,
           s_Bctrl1=2,
           s_Bctrl2=3;
void motor_setup_default(int baseaddr)
{
	       s_baseaddr=baseaddr; 
           s_ctrlA=1;
           s_Actrl1=2;
           s_Actrl2=3;
           s_ctrlB=4;
           s_Bctrl1=5;
           s_Bctrl2=6;
	}
void motor_setup(int baseaddr,int ctrlA,int Actrl1,int Actrl2,int ctrlB,int Bctrl1,int Bctrl2)
{ 
	s_baseaddr=baseaddr;
	s_ctrlA=ctrlA;
	s_Actrl1=Actrl1;
	s_Actrl2=Actrl2;
	s_ctrlB=ctrlB;
	s_Bctrl1=Bctrl1;
	s_Bctrl2=Bctrl2;
	if(s_ctrlA>=0){
		pinMode         (s_baseaddr + s_ctrlA, OUTPUT) ;
		if(s_Actrl1>=0){
			pinMode         (s_baseaddr + s_Actrl1, OUTPUT) ;
		}
		if(s_Actrl2>=0){
			pinMode         (s_baseaddr + s_Actrl2, OUTPUT) ;
		}
	}

	if(s_ctrlB>=0){
		pinMode         (s_baseaddr + s_ctrlB, OUTPUT) ;
		if(s_Bctrl1>=0){
		   pinMode         (s_baseaddr + s_Bctrl1, OUTPUT) ;
	    }
	    if(s_Bctrl2>=0){
		   pinMode         (s_baseaddr + s_Bctrl2, OUTPUT) ;
	    }
	}
	
	} 
void motor_order(int mtype,int ctrl,int param1,int param2)
{
    switch(mtype)
    {
		case 0:
		motor_stop(ctrl);
		break;
		case 1:
		motor_start(ctrl);
		break;
		case 2:
		motor_forward(ctrl);
		break;
		case 3:
		motor_back(ctrl);
		break;
		default:
		motor_stop(0);
		motor_stop(1);
		break;
		};	
	}
void motor_stop(int ctrl)
{
	
	}
void motor_start(int ctrl)
{
	
	}
void motor_forward(int ctrl)
{
	
	
	}
void motor_back(int ctrl)
{
	
	}
