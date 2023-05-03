#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Our struct is used for both matrix and CallList. */

void init(node M[][5])
{
        char marked= ' ';
}

/*adds elem from input file to a 5x5 matrix (uses struct)*/
void addMatrix(node M[][5], int item, int n)
{
        int i,j;
        n = n - 1;
        i = n/5;  /* assign row index from nth item  */
        j = n%5;  /* assing col index from nth item */
        char temp[4]; 
        if(item < 10) /*append 0 for single digit nums from 1-9*/
        {
                snprintf(temp,10,"%d",item);
                strcpy(M[i][j].data,"0");
                strcat(M[i][j].data,temp);
                M[i][j].marked = ' ';
        }
        else
        {
                snprintf(temp,10,"%d",item);
                strcpy(M[i][j].data, temp);
                M[i][j].marked = ' ';
        }
}

int checkWin(node M[][5])
{
        int i,j,count,win=0;
        /* row wise count marked check */
        for(i=0; i<5; i++)
        {
                count = 0;
                for(j=0; j<5; j++)
                {
                        if(M[i][j].marked == 'm')
                        {
                                count++;
                        }
                }
                if(count==5)
                {
                        win=1; 
                        return win;
                }
        }

        /* column wise count marked check */
        for(j=0; j<5; j++)
        {
                count = 0;
                for(i=0; i<5; i++)
                {
                        if(M[i][j].marked == 'm')
                        {
                                count++;
                        }
                }
                if(count == 5)
                {
                        win=1;
                        return win;
                }
        }

        /* All four corners marked check */
        if(M[0][0].marked=='m' && M[0][4].marked =='m' && M[4][0].marked=='m' && M[4][4].marked=='m')
        {
                return 1;
        }
        return win;
}

void printMatrix(node M[][5])
{
        int i,j;
        printf("L   I   N   U   X  \n");
        for(i=0; i<5; i++)
        {
                for(j=0; j<5; j++)
                {
                        if(i==2 && j==2){
                                printf("00m ");
                        }else{
                                printf("%s%c ",M[i][j].data,M[i][j].marked);
                        }
                }
                printf("\n");
        }
}

/* marks and returns 1 for win 
data members .marked and .data to store mark and num*/
int Marked(node M[][5],  int N)
{
        int i,j,A;
        for(i=0; i<5; i++)
        {
                for(j=0; j<5; j++)
                {
                        A = atoi(M[i][j].data);
                        if(i==2 && j==2){
                                M[i][j].marked = 'm';
                                system("clear");
                                printMatrix(M);
                        }
                        if(A == N)
                        {
                                M[i][j].marked = 'm';
                                system("clear");
                                printMatrix(M);
                                if(checkWin(M))
                                {
                                        return 1;
                                }
                        }
                }
        }
        return 0;
}

void printCallList(node L[], int size)
{
        int i;
        system("clear");
        printf("Call List : \n");
        for(i=0; i<size; i++)
        {
                printf("%c%s ", L[i].marked,L[i].data);
        }
        printf("\n");


}

void addCallList(node M[][5],int seed)
{
        node callList[75],List[75]; /* List = list of 1-75 num with idx, callList= randomly generated list */
        char temp[4];
        int i,j,N=75,R,item,size=0;
        char key;
        for(i=0; i<75; i++)
        {
                j = i+1;
                snprintf(temp,10,"%d",j);
                strcpy(List[i].data, temp);
                if(i < 10) /* append 0 for single digit nums from 1-9*/
                {
                        strcpy(List[i].data, "0");
                        strcat(List[i].data,temp);
                }
                if(i>=1 && i<=15)
                {
                        List[i].marked = 'L';
                }
                else if(i>=16 && i<=30)
                {
                        List[i].marked = 'I';
                }
                else if(i>=31 && i<= 45)
                {
                        List[i].marked = 'N';
                }
                else if(i>=46 && i<=60)
                {
                        List[i].marked = 'U';
                }
                else if(i>=61 && i<=75)
                {
                        List[i].marked = 'X';
                }
        }
        srand((unsigned) seed);
        for(i=0; i<75; i++)
        {
                R =rand()%N;
                callList[size] = List[R]; /* Random index(R) from List */
                size++; /* increase size of callList as rand generated num are added */
                item = atoi(List[R].data);
                printCallList(callList, size);
                printMatrix(M);
                printf("Enter any non-enter key to call/q to exit: ");
                scanf(" %c", &key);
                if(key =='q') {
                        break;
                }

                if(Marked(M, item)==1)
                {
                        system("clear");
                        printCallList(callList, size);
                        printMatrix(M);
                        printf("Winner!\n");
                        break;
                }
                for(j=R; j<N-1; j++) /* remove the list item when matched and decrease the size of list by shifting index to left */
                {
                        List[j] = List[j+1];
                }
                N--; /* decrease size of list*/

        }
}