#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/input.h>

int main (int argc, char *argv[])
{
  struct input_event ev;
  int fd, rd, value, size = sizeof (struct input_event);
  char name[256] = "Unknown";
  char *device = NULL;

 
  if (argv[1] == NULL){
      printf("You forgot to specify your keyboard device on command line..eg : /dev/input/event1\nExiting..");
      exit (8);
    }

  if ((getuid ()) != 0)									//Not Root?
    printf ("If this doesnt work. Try as root.\n");

  if (argc > 1)
    device = argv[1];

  //Open Device
  if ((fd = open (device, O_RDONLY)) == -1)
    printf ("%s is not a vaild device.\n", device);

  //Print Device Name
  ioctl (fd, EVIOCGNAME (sizeof (name)), name);
  printf ("Reading From : %s (%s)\n", device, name);

  while (1){
      if ((rd = read (fd, &ev, size)) < size)
          perror("read()");      

           
	   if(ev.type==1)
	   printf ("Type:%d Code:%d value:%d\n", ev.type,ev.code,ev.value);
     
  }

  return 0;
}

