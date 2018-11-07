#define _CRT_SECURE_NO_WARNINGS 1
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# define MAXSIZE 1000                        //最大长度为1000 
typedef int elemtype;
typedef struct student
{
	elemtype data[MAXSIZE];
	int last;
}SequenList;


SequenList *Init_InformationTable()               //初始化链表
{
	SequenList *L;
	L = (SequenList *)malloc(sizeof(SequenList));
	if (L != NULL)
	{
		L->last = -1;
	}
	return L;
}


int deleteList(SequenList *L, int pos/*,elemtype *elem*/) //删除指定位置元素
{
	int i;
	if (pos<1 || pos>L->last + 1)
	{
		printf("删除的位置有误，无法从该位置删除数据\n");
		return 0;
	}
	for (i = pos; i<L->last + 1; i++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->last--;
	printf("删除数据成功！\n");
	return 1;
}



SequenList *creatInformationTable(SequenList *L)  //输入数据表
{
	elemtype x;
	printf("请输入元素(终止输入请输入0即可)：\n");
	scanf("%d", &x);
	while (x != 0)
	{
		L->last += 1;
		L->data[L->last] = x;
		scanf("%d", &x);
	}
	printf("顺序表建立成功！\n");
	return L;
}

int printTable(SequenList *L)             //打印
{
	if (L->last + 1 == 0)
	{
		printf("链表为空\n");
		return 0;
	}
	int i;
	for (i = 0; i<L->last + 1; i++)
	{
		printf("第 %d 个数据是 %d\n", i + 1, L->data[i]);
	}
	printf("\n");
	return 1;
}


void Head()
{
	system("cls");
	printf(
		"**********************************************************************\n"
		"**                                                                  **\n"
		"**                                                                  **\n"
		"**                      欢迎使用信息管理系统                        **\n"
		"**                                                                  **\n"
		"**                       1.信息表初始化                             **\n"
		"**                       2.建立信息表                               **\n"
		"**                                                                  **\n"
		"**                       4.查询第n条信息                            **\n"
		"**                       5.查询信息位置                             **\n"
		"**                       6.插入指定信息                             **\n"
		"**                       7.删除指定位置信息                         **\n"
		"**                       8.打印信息表                               **\n"
		"**                       0.退出系统                                 **\n"
		"**                                                                  **\n"
		"**                                                                  **\n"
		"**********************************************************************\n"
		);
	printf("请输入相应的数字选择相对应的功能\n");
}

int main()
{
	SequenList *L;
	int  quit = 0;
	int len, key, x, i;
	elemtype *e = 0;
	int s;
	while (1)
	{
		Head();			//调用子函数
		scanf("%d", &s);

		switch (s)
		{
		case 1:{
				   L = Init_InformationTable();
				   if (L == NULL)
				   {
					   printf("申请顺序表内存空间失败，程序结束！\n");
					   return 0;
				   }
				   else
					   printf("信息表初始化成功！\n");
		}; break;
		case 2: {
					*creatInformationTable(L);
		}; break;

		case 3: {
					printf("请输入想要删除的元素：");
					scanf("%d", &i);
					deleteList(L, i);
		}; break;
		case 4: printTable(L); break;
		case 0: quit = 1; break;
		default:printf("请输入0~4之间的数字\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		system("pause");
		printf("程序结束！\n");
	}
	return 0;
}

