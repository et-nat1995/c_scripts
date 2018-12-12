#ifndef forEx4
#define forEx4

typedef struct data
{
	int data ;
	struct data *next;
}Data;


Data* creat_listData();
void insert_listData(Data *list,int num );
void full_list(Data *list,int num);
void print_listData(Data *list);
void insert_listData_item(Data *list,Data *item);
Data * odd_even(Data *list);
void list_untilminus1(Data* list);
void freelistData(Data *list);

#endif
