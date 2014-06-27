#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
   if(argc<2){
      printf("Usage: \n");
      printf("readlabels t10k-labels-idx1-ubyte \n");
      exit(1);
   }
   
   char *slabelfname = argv[1];
   
   printf("ARGV[1]: %s\n", slabelfname);
   return 0;
}