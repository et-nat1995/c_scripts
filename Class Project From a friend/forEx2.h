#ifndef forEx2
#define forEx2


#define N 3      //בשביל שורת של מטריצה 1 מתרגיל 2
#define M 2     //בשביל עמודות למטריצה 1
#define W 2     //בשביל שוררות של מטריצה 2
#define T 1    //בשביל עמודות של מטריצה 2

void fullmatrixA(int matrix[N][M]);
void fullmatrixB(int matrix[M][T]);
void print_matrixB(int matrix[M][T]);
void print_matrixA(int matrix[N][M]);
int ** multimatrix(int matrixA[N][M],int matrixB[M][T]);
void printMatrix(int **arr,int n, int m);
void freematrix(int **matrix ,int row);

#endif