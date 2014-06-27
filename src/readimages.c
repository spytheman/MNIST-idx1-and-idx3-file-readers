#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <arpa/inet.h>
#include "idx.h"

int main(int argc, char **argv){
   if(argc<2){
      printf("Usage: \n");
      printf("readimages t10k-images-idx3-ubyte \n");
      exit(1);
   }
   
   char *slabelfname = argv[1];
   
   IDX3_DATA idxdata;
   if(!fread_idx3_file( slabelfname, &idxdata)){
      printf("The datafile '%s' is not a valid IDX3 file.\n", slabelfname);
      exit(2);
   }
   //printf("Length: %d\n", idxdata.length);
   
   int i;
   int x;
   int y;
   int ibase;
   int rbase;
   unsigned char pxl;
   for(i=0;i<idxdata.nimages;i++){
      ibase = i * idxdata.nrows * idxdata.ncols;
      printf("Image %05d ( %010d ):\n", i + 1, ibase);
      for(y=0;y<idxdata.nrows;y++){
         rbase = ibase + y*idxdata.ncols;
         for(x=0;x<idxdata.ncols;x++){
            //      printf("DATA[%05d] = %02d\n", i, idxdata.data[i]);
            pxl = idxdata.data[ rbase + x ];
            if(pxl){
               printf("%02X", pxl);
            }else{
               printf("  ");
            }
         }
         printf("\n");
      }
      printf("========================================================\n");
   }
   
   return 0;
}

