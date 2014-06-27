#include <stdio.h>
#include <stdlib.h>
#include "idx.h"

int main(int argc, char **argv){
   if(argc<2){
      printf("Usage: \n");
      printf("readlabels t10k-labels-idx1-ubyte \n");
      exit(1);
   }
   
   char *slabelfname = argv[1];
   
   IDX1_DATA idxdata;
   if(!fread_idx1_file( slabelfname, &idxdata)){
      printf("The datafile '%s' is not a valid IDX_1 file.\n", slabelfname);
      exit(2);
   }
   
   int i;
   for(i=0;i<idxdata.length;i++){
      printf("%d\n", idxdata.data[i]);
   }
   
   return 0;
}

