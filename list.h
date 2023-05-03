struct Matrix
{
     char data[3]; /* stores num */
     char marked;  /* stores mark 'm' or 'L,I,N,U,X' */
};
typedef struct Matrix node;

void init(node M[][5]);
void addMatrix(node M[][5], int item, int n);
int checkWin(node M[][5]);
void printMatrix(node M[][5]);
int Marked(node M[][5],  int N);
void printCallList(node L[], int size);
void addCallList(node M[][5],int seed);