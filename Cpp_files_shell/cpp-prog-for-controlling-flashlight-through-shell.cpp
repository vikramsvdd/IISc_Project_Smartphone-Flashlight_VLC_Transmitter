#include <stdio.h>
#include <stdlib.h>
int main()
{
//  system("su");
system("cd ~ | echo 100 > ~/sys/class/leds/flashlight/brightness");
 // system("echo 100 > ~/sys/class/leds/flashlight/brightness ");
  
  return 0;
}
