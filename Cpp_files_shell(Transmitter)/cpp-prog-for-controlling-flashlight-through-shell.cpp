#include <stdio.h>
#include <stdlib.h>
int main()
{
//  system("su");
system("cd ~ | echo 100 > ~/sys/class/leds/flashlight/brightness");
 //system("sh script_for_testing_flashlight.sh");
 // system("echo 100 > ~/sys/class/leds/flashlight/brightness ");
  
  return 0;
}
