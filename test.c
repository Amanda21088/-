#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strcpy函数的头文件
#include <assert.h>//保证合法性的头文件
#include <windows.h>

#define MAXLEN 256
#define BUFF_LEN 2

typedef struct MottoTable
{
	int ID;       //名字 
	char writer[MAXLEN];//作者 
	char sentence[MAXLEN];//句子
	struct MottoTable *motto_next;
}Motto, *PMotto;

int Add_Motto(PMotto, PMotto);

void ShowDesk() //菜单函数
{
	system("cls");//清屏

	printf("-----------------------------名言警句管理系统--------------------------------\n");//菜单的打印

	printf("\n\t1.添加信息\t2.删除信息\t3.修改信息\n");

	printf("\t4.查询信息\t5.显示所有信息\n");

	printf("\t6.保存所有信息至文件\n");

	printf("\t0.退出系统\n");

	printf("\n-------------------------------------------------------------------------\n");
}

void InitHead(PMotto motto_head)
{
	assert(motto_head != NULL); //保证motto_head的合法性 
	motto_head->motto_next = NULL;
}

void InitList(PMotto motto_head)
{
	assert(motto_head != NULL);
	FILE *fp = fopen("Motto.txt", "rb");//以只读的形式打开文件
	if (fp == NULL)
	{
		fp = fopen("Motto.txt", "w");
		fclose(fp);//关闭文件
		return;
	}
	char Buff[BUFF_LEN] = { 0 };//初始化
	char tmp_writer[MAXLEN] = { 0 };
	char tmp_sentence[MAXLEN] = { 0 };
	int count = 0;
	int sign_writer = 1;
	int sign_sentence = 0;
	int number = 1;
	while (fread(Buff, 1, 1, fp) != 0)
	{
		if (strncmp(Buff, "-", 1) == 0 || strncmp(Buff, "\n", 1) == 0 || count >= MAXLEN)
		{
			if (strncmp(Buff, "-", 1) == 0)
			{
				sign_writer = 0;
				sign_sentence = 1;
				count = 0;
				continue;
			}
			else if (strncmp(Buff, "\n", 1) == 0)
			{
				PMotto ptmp = (PMotto)malloc(sizeof(Motto));
				memset(ptmp, 0, sizeof(Motto));
				ptmp->ID = number;
				number++;
				strncpy(ptmp->writer, tmp_writer, strlen(tmp_writer));
				strncpy(ptmp->sentence, tmp_sentence, strlen(tmp_sentence));
				Add_Motto(motto_head, ptmp);
				memset(tmp_writer, 0, MAXLEN);
				memset(tmp_sentence, 0, MAXLEN);
				count = 0;
				sign_writer = 1;
				sign_sentence = 0;
				continue;
			}
			else if (count >= MAXLEN)
			{
				printf("error:字符数过多\n");
				return;
			}
		}
		else if (sign_writer)
		{
			strcat(tmp_writer, Buff);
			count++;
			continue;
		}
		else if (sign_sentence)
		{
			strcat(tmp_sentence, Buff);
			count++;
			continue;
		}
	}
	fclose(fp);
}

PMotto GetPrevAddrMotto(PMotto motto_head, int num)
{
	assert(motto_head != NULL);
	PMotto pmotto = motto_head;

	while (pmotto->motto_next)
	{
		if (pmotto->motto_next->ID == num)
			return pmotto;

		pmotto = pmotto->motto_next;
	}

	return NULL;
}

int GetMessageW()//菜单选择函数
{
	int num;
	printf("请选择菜单(0 ~ 6):");//输入1—6

	while (1 != scanf("%d", &num) || num < 0 || num > 6)//判断输入是否正确
	{
		printf("选择菜单错误，请重新选择(0 ~ 6):");
		fflush(stdin);
	}

	return num;
}

int GetInputNum()
{
	int num;

	printf("请输入编号：");

	while (1 != scanf("%d", &num))
	{
		printf("编号输入错误！请重新输入编号(整型)：");
		fflush(stdin);
	}

	return num;
}

PMotto Create_Motto(PMotto motto_head)//输入警句编号
{
	assert(motto_head != NULL);
	PMotto pmotto = (PMotto)malloc(sizeof(Motto));

	while (!pmotto)
		pmotto = (PMotto)malloc(sizeof(Motto));

	memset(pmotto, 0, sizeof(Motto));
	printf("请输入警句编号：");

	while (1 != scanf("%d", &pmotto->ID) || GetPrevAddrMotto(motto_head, pmotto->ID))//判断警句编号是否合法
	{
		printf("编号输入错误或已经存在，请重新输入警句的编号：");
		fflush(stdin);
	}

	char tmp_writer[MAXLEN] = { 0 };//初始化
	char tmp_sentence[MAXLEN] = { 0 };
	fflush(stdin);
	printf("请输入作者姓名：");//输入对应的信息
	fgets(tmp_writer, MAXLEN - 1, stdin);
	strncpy(pmotto->writer, tmp_writer, strlen(tmp_writer) - 1);
	printf("请输入名言警句文段：");
	fgets(tmp_sentence, MAXLEN - 1, stdin);
	strncpy(pmotto->sentence, tmp_sentence, strlen(tmp_sentence) - 1);//添加警句
	printf("\n添加完毕！\n");
	int sign;
	printf("输入0退出:");
	while (1 != scanf("%d", &sign) || sign != 0)//判断输入是否正确
	{
		printf("选择菜单错误，请重新输入:");
		fflush(stdin);
	}
	return pmotto;
}

int Add_Motto(PMotto motto_head, PMotto padd)//添加警句的函数
{
	assert(motto_head != NULL);
	PMotto ps = motto_head;

	if (!padd || GetPrevAddrMotto(motto_head, padd->ID))//判断警句是否合法，或者有没有重复
	{
		printf("添加失败：编号为%d的信息已经存在或出现错误！\n", padd->ID);
		free(padd);
		return 0;
	}

	while (ps->motto_next)
		ps = ps->motto_next;

	ps->motto_next = padd;
	return 1;
}

void Delete_Motto(PMotto motto_head, int num)//删除警句的函数
{
	PMotto p_motto, p_tmp;

	if (p_motto = GetPrevAddrMotto(motto_head, num))//对对应的警句编号操作
	{
		p_tmp = p_motto->motto_next;
		p_motto->motto_next = p_tmp->motto_next;//判断输入的编号是否合法
		free(p_tmp);
		printf("删除了编号为%d的信息。\n", num);
	}
	else
	{
		printf("没有找到编号为%d的信息。\n", num);
	}

	int sign;
	printf("输入0退出:");
	while (1 != scanf("%d", &sign) || sign != 0)
	{
		printf("选择菜单错误，请重新输入:");
		fflush(stdin);
	}
}

void Modity_Motto(PMotto motto_head, int num)//查找对应的警句
{
	PMotto pmotto = GetPrevAddrMotto(motto_head, num);

	if (!pmotto)                //判断警句是否存在
	{
		printf("没有编号为%d的信息。\n", num);
	}
	else
	{
		pmotto = pmotto->motto_next;

		char tmp_writer[MAXLEN] = { 0 };
		char tmp_sentence[MAXLEN] = { 0 };

		printf("当前作者为：%s\n", pmotto->writer);//如果存在，就输入对应的信息，找到对应的编号
		printf("请输入更改的作者姓名：");
		fgets(tmp_writer, MAXLEN - 1, stdin);
		strncpy(pmotto->writer, tmp_writer, strlen(tmp_writer) - 1);

		printf("当前文字：%s\n", pmotto->sentence);
		printf("请输入更改的名言警句文段：");
		fgets(tmp_sentence, MAXLEN - 1, stdin);
		strncpy(pmotto->sentence, tmp_sentence, strlen(tmp_sentence) - 1);//进行修改

		printf("修改完毕！\n");
	}

	int sign;
	printf("输入0退出:");
	while (1 != scanf("%d", &sign) || sign != 0)
	{
		printf("选择菜单错误，请重新输入:");
		fflush(stdin);
	}
}

void Select_Motto(PMotto motto_head, int num)//选择所对应的函数
{
	PMotto pmotto = GetPrevAddrMotto(motto_head, num);

	if (!pmotto)
	{
		printf("没有编号为%d的信息。\n", num);
		return;
	}
	pmotto = pmotto->motto_next;//指向下一个

	printf("作者：%s\n", pmotto->writer);
	printf("名言警句：%s\n", pmotto->sentence);
	int sign;
	printf("输入0退出:");
	while (1 != scanf("%d", &sign) || sign != 0)
	{
		printf("选择菜单错误，请重新输入:");
		fflush(stdin);
	}
}

void SelectAllStudent(PMotto motto_head) //遍历存起来的名言警句
{
	PMotto pmotto = motto_head->motto_next;

	printf("--------------------------------------------------------------------\n");
	printf("\t编号\t作者\t名言警句\n");
	printf("--------------------------------------------------------------------\n");

	while (pmotto)
	{
		printf("\t%d", pmotto->ID);
		printf("\t%s", pmotto->writer);
		printf("\t%s\n", pmotto->sentence);
		pmotto = pmotto->motto_next;
	}

	printf("--------------------------------------------------------------------\n");
	int num;
	printf("输入0退出:");
	while (1 != scanf("%d", &num) || num != 0)
	{
		printf("选择菜单错误，请重新输入:");
		fflush(stdin);
	}
}

void SaveMottoToFile(PMotto motto_head)//保存输入的名言警句
{
	PMotto pmotto = motto_head->motto_next;
	FILE *fp = fopen("Motto.txt", "w");

	while (pmotto)
	{
		fwrite(pmotto->writer, strlen(pmotto->writer), 1, fp);
		fwrite("-", 1, 1, fp);
		fwrite(pmotto->sentence, strlen(pmotto->sentence), 1, fp);
		fwrite("\n", 1, 1, fp);
		pmotto = pmotto->motto_next;
	}
	printf("保存成功！\n");
	int sign;
	printf("输入0退出:");
	while (1 != scanf("%d", &sign) || sign != 0)//判断输入的编号是否存在
	{
		printf("选择菜单错误，请重新输入:");
		fflush(stdin);
	}
	fclose(fp);

}

int main()//主函数，将以上函数综合在一起
{
	int sign = 1;
	Motto head;
	InitHead(&head);
	InitList(&head);
	while (sign)
	{
		ShowDesk();
		switch (GetMessageW())//利用switch调用上边用到的所有函数
		{
		case 0: sign = 0; break;
		case 1: Add_Motto(&head, Create_Motto(&head)); break;
		case 2: Delete_Motto(&head, GetInputNum()); break;
		case 3: Modity_Motto(&head, GetInputNum()); break;
		case 4: Select_Motto(&head, GetInputNum()); break;
		case 5: SelectAllStudent(&head); break;
		case 6: SaveMottoToFile(&head); break;
		default:printf("选择菜单出错，请重新选择！\n"); break;
		}
	}
	return 0;
}