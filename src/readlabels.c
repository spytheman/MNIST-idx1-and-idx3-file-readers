#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <arpa/inet.h>


typedef struct {
   unsigned char header[4];
   int length;
   unsigned char *data;
} IDX_DATA_1 ;

int read_idx_file_1( char *slabelfname, IDX_DATA_1 *idxdata){
   FILE *f = fopen(slabelfname, "r+");
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


int main(int argc, char **argv){
   if(argc<2){
      printf("Usage: \n");
      printf("readlabels t10k-labels-idx1-ubyte \n");
      exit(1);
   }
   
   char *slabelfname = argv[1];
   
   IDX_DATA_1 idxdata;
   if(!read_idx_file_1( slabelfname, &idxdata)){
      printf("The datafile '%s' is not a valid IDX_1 file.\n", slabelfname);
      exit(2);
   }
   //printf("Length: %d\n", idxdata.length);
   int i;
   for(i=0;i<idxdata.length;i++){
//      printf("DATA[%05d] = %02d\n", i, idxdata.data[i]);
      printf("%d\n", idxdata.data[i]);
   }
   
   return 0;
}

