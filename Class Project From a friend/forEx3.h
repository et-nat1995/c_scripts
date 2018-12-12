#ifndef forEx3
#define forEx3


#define F 3    //בשביל שורות למטריצה מתרגיל 3
#define R 4    //בשביל עמודות למטריצה מתרגיל 3
typedef struct 
{
	
	int i;
	int j;
	int value;
}three;

typedef struct threeNode
{
	three data;
	struct threeNode *next;
}threenode;


threenode* creat_list();
threenode* made_item(int i,int j ,int value);
void insert_item(threenode (*list),threenode (*item));
void insertlisttoarr(threenode *list,three **arr,int count);
int matchmatrix(int **matrix,int row,int cal,threenode (*list),three **arr);
int** full_madematrix(int n,int m);
//void printMatrix(int **arr,int row,int cal);
void print_threelist(threenode *list);
void print_arrthree(three *arr,int size);
void freelistthree(threenode *list);


#endif