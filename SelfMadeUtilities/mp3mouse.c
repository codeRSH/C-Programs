#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/input.h>
#include <signal.h>




int main (int argc, char *argv[])
{
  struct input_event ev;									//Predefined strcuture (linux/input.h)
  int fd, rd, value, size = sizeof (struct input_event);
  char *device = NULL;										//The mouse device
  int running=0;
  int pause=1;
  int mpg_id;												//Will contain PID of mpg321
 
  if (argv[1] == NULL){
      printf("You forgot to specify your mouse device on command line. Eg: /dev/input/event3\nExiting..\n");
      exit (0);
    }

  if ((getuid ()) != 0)										//Not ROOT?
    printf ("If this does not work. Try again as root.\n");

  if (argc > 1)
    device = argv[1];

  if ((fd = open (device, O_RDONLY)) == -1)
    printf ("%s is not a vaild device.\n", device);

  while (1)
  {
      
      if ((rd = read (fd, &ev, size)) < size)				//read device for events
      	{
          perror("read()");  
          exit(8);    
		}
     

      
	 // printf("value %d, type %d, code %d\n",ev.value,ev.type,ev.code);//Use this if you want to check 
	 																	//codes for various events
	  
	  
	  /*One thing I dont know why, It wont run without "\n"s how hard I try*/
	  	 
	 if(ev.type==1 && ev.value==1 && ev.code==272) 		//Left Click Event
	 	{
	 		printf("\nLEFT CLICK");
	 		if(pause==0)
	 		{
	 			if(kill(mpg_id,SIGINT)<0)				//Send SIGINT to mpg321. It plays the next track
	 			{
	 				perror("kill");
	 			}
	 			sleep(1);								//sleep for 1 second to  avoid sending
														//double click because it will terminate mpg321
	 		}
	 	}
	 else if(ev.type==1 && ev.value==1 && ev.code==273)		//Right Click Event
	 	{
	 		printf("\nRight CLICK");
	 		
	 		if(running==0)								//If mpg321 is not already executed
	 		{
	 			running=1;			
	 			pause=0;
	 			switch(mpg_id=fork())					//fork this process
	 			{
	 				case 0:								//Child executes mpg321 in random mode with
	 													//playlist "playme.lst" in . directory
	 					printf("\nmpgid=%d",mpg_id);	
	 					if(execlp("/usr/local/bin/mpg321","mpg321","-z","-@","playme.lst",(char*)0)<0)
   									{
   										perror("exec:");
   										exit(8);
   									}
   						break;
   					
   					case -1:							// Jhand
   						perror("fork:");
   						exit(9);
   						break;
   								
   					
   					default:
   						sleep(1);						// Parent sleeps for 1 second for no reason.
	 			}
	 		}
	 		else if(pause==0)					//If mpg321 is already executed and is NOT paused
	 		{
	 			pause=1;						
	 			if(kill(mpg_id,SIGSTOP)<0)		//Send SIGSTOP it will suspend mpg321 (pause)
	 			{
	 				pause=0;
	 				perror("kill");
	 			}
	 			
	 		}
	 		else if(pause==1)					//If mpg321 is already executed and is paused
	 		{
	 			pause=0;
	 			if(kill(mpg_id,SIGCONT)<0)		//Send SIGCONT to mpg321 it will resume it 
	 			{	pause=1;
	 				perror("kill");
	 			}
	 		}
	 		

	 		
	 		
	 	}
	 else if(ev.type==2 && ev.value==-1 && ev.code==8)		//Wheel down Event
	 	{
	 		printf("\nWheel down");
	 	}
	 else if(ev.type==2 && ev.value==1 && ev.code==8)		//Up up and away!
	 	{
	 		printf("\nWheel UP");
	 	}
	 
	 	
	
  }

  return 0;
}

