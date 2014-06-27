#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <assert.h>
#include "idx.h"

int fread_idx1_file( char *slabelfname, IDX1_DATA *idxdata){
   FILE *f = fopen(slabelfname, "r");
   if(!f){
      return 0;
   }
   
   fread(&(idxdata->header),4,1,f);
   if( idxdata->header[0] != 0 ) return 0;
   if( idxdata->header[1] != 0 ) return 0;
   if( idxdata->header[2] != 8 ) return 0; // the kind of data should be an unsigned byte
   if( idxdata->header[3] != 1 ) return 0; // there should be only 1 dimension

   fread(&(idxdata->length), 4,1,f);
   idxdata->length = ntohl( idxdata->length );
      
   idxdata->data = calloc( idxdata->length, 1);
   if( !idxdata->data ) return 0;
   fread(idxdata->data, idxdata->length, 1, f);
   return 1;
}

