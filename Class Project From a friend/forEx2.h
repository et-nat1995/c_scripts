#ifndef forEx2
#define forEx2


#define N 3      //����� ���� �� ������ 1 ������ 2
#define M 2     //����� ������ ������� 1
#define W 2     //����� ������ �� ������ 2
#define T 1    //����� ������ �� ������ 2

void fullmatrixA(int matrix[N][M]);
void fullmatrixB(int matrix[M][T]);
void print_matrixB(int matrix[M][T]);
void print_matrixA(int matrix[N][M]);
int ** multimatrix(int matrixA[N][M],int matrixB[M][T]);
void printMatrix(int **arr,int n, int m);
void freematrix(int **matrix ,int row);

#endif