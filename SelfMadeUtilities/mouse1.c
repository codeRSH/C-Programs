#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/input.h>

int main (int argc, char *argv[])
{
  struct input_event ev;
  int fd, rd, value, size = sizeof (struct input_event);
  char *device = NULL;
  int running=0;

 
  if (argv[1] == NULL){
      printf("You forgot to specify your mouse device on command line. Eg: /dev/input/event3\nExiting..\n");
      exit (0);
    }

  if ((getuid ()) != 0)
    printf ("You should be root to get this to work. But Still let me try\n");

  if (argc > 1)
    device = argv[1];

  if ((fd = open (device, O_RDONLY)) == -1)
    printf ("%s is not a vaild device.\n", device);

  while (1){
      
      if ((rd = read (fd, &ev, size)) < size)
      {
          perror("read()");  
          exit(8);    
		}
     

      
	 // printf("value %d, type %d, code %d\n",ev.value,ev.type,ev.code);
	  
	  printf("\n");
	  /*1 thing I dont know why It wont run without "\n" how hard I try*/
	  	 
	 if(ev.type==1 && ev.value==1 && ev.code==272) 			//Left Click Event
	 	{
	 		printf("\nLEFT CLICK");
	 	}
	 else if(ev.type==1 && ev.value==1 && ev.code==273)		//Right Click Event
	 	{
	 		printf("\nRight CLICK");
	 	}
	 else if(ev.type==2 && ev.value==-1 && ev.code==8)		//Wheel down Event
	 	{
	 		printf("\nWheel down");
	 	}
	 else if(ev.type==2 && ev.value==1 && ev.code==8)		//Up up and away!
	 	{
	 		printf("\nWheel UP");
	 	}
	 else
	 	{
	 		printf("\nMoving!");
	 	}
	 	
	
  }

  return 0;
}

