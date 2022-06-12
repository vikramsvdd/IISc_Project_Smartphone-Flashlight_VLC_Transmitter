#include<iostream.h>
#include<ctime>
#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>

using namespace std;

  int main() { 

      timespec ts;
double  t= clock_gettime(CLOCK_MONOTONIC_RAW,&ts);   //get system clock time
    //usleep(1); // sleeps for 1 us 
  cout<<t;
  }
