#include <stdlib.h>
#include <ctype.h>
#include "list.h"
int main (int argc, char *argv[])
{
        FILE *inputf ;
        int i,j,k,seed,data;
        node matrix[5][5];
        int test2[25];
        if(argc != 3) {
                fprintf (stderr, "Usage: %s seed cardFile\n", argv[0]);
                exit(1);
        }
        for(i= 0 ; argv[1][i]!= '\0' ; i++){
                if(!(isdigit(argv[1][i]))) {
                        fprintf (stderr,"Expected integer seed, but got %s \n",argv[1]);
                        exit(2);
                }
        }
        if((inputf=fopen(argv[2],"r"))==NULL) {
                fprintf(stderr,"%s is nonexistent or unreadable \n",argv[2]);
                exit(3);
        }

        for(i=0;i<25;i++)
        {
                fscanf(inputf,"%d",&test2[i]);
        }
        for(int i=0;i<25; i += 5)
        {
                if(test2[i]>15)
                {
                        fprintf(stderr,"%s has bad format \n",argv[2]);
                        exit(4);
                }
        }
        for(int i=1;i<25; i += 5)
        {
                if(test2[i]<16 || test2[i]>30)
                {
                        fprintf(stderr,"%s has bad format \n",argv[2]);
                        exit(4);
                }
        }
        for(int i=2;i<25; i += 5)
        {
                if(i==12){
                        if(test2[i] != 0){
                                fprintf(stderr,"%s has bad format \n",argv[2]);
                                exit(4);
                        }
                }else{
                        if(test2[i]<31 || test2[i]>45)
                        {
                                fprintf(stderr,"%s has bad format \n",argv[2]);
                                exit(4);
                        }
                }
        }
        for(int i=3;i<25; i += 5)
        {
                if(test2[i]<46 || test2[i]>60)
                {
                        fprintf(stderr,"%s has bad format \n",argv[2]);
                        exit(4);
                }
        }
        for(int i=4;i<25; i += 5)
        {
                if(test2[i]<61 || test2[i]>75)
                {
                        fprintf(stderr,"%s has bad format \n",argv[2]);
                        exit(4);
                }
        }
        for(int i=0;i<24; i++)
        {
                for(int j=i+1;j<25;j++)
                {
                        if(test2[i] == test2[j])
                        {
                                fprintf(stderr,"%s has bad format \n",argv[2]);
                                exit(4);
                        }
                }
        }
        inputf = fopen(argv[2], "r");
        for (i=0 ; i<25; i++){
                fscanf(inputf,"%d",&data);
                addMatrix(matrix, data,i+1);
        }
        printMatrix(matrix);
        seed=atoi(argv[1]);
        addCallList(matrix,seed);
return 1;

}