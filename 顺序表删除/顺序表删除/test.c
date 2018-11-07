#define _CRT_SECURE_NO_WARNINGS 1
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# define MAXSIZE 1000                        //��󳤶�Ϊ1000 
typedef int elemtype;
typedef struct student
{
	elemtype data[MAXSIZE];
	int last;
}SequenList;


SequenList *Init_InformationTable()               //��ʼ������
{
	SequenList *L;
	L = (SequenList *)malloc(sizeof(SequenList));
	if (L != NULL)
	{
		L->last = -1;
	}
	return L;
}


int deleteList(SequenList *L, int pos/*,elemtype *elem*/) //ɾ��ָ��λ��Ԫ��
{
	int i;
	if (pos<1 || pos>L->last + 1)
	{
		printf("ɾ����λ�������޷��Ӹ�λ��ɾ������\n");
		return 0;
	}
	for (i = pos; i<L->last + 1; i++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->last--;
	printf("ɾ�����ݳɹ���\n");
	return 1;
}



SequenList *creatInformationTable(SequenList *L)  //�������ݱ�
{
	elemtype x;
	printf("������Ԫ��(��ֹ����������0����)��\n");
	scanf("%d", &x);
	while (x != 0)
	{
		L->last += 1;
		L->data[L->last] = x;
		scanf("%d", &x);
	}
	printf("˳������ɹ���\n");
	return L;
}

int printTable(SequenList *L)             //��ӡ
{
	if (L->last + 1 == 0)
	{
		printf("����Ϊ��\n");
		return 0;
	}
	int i;
	for (i = 0; i<L->last + 1; i++)
	{
		printf("�� %d �������� %d\n", i + 1, L->data[i]);
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
		"**                      ��ӭʹ����Ϣ����ϵͳ                        **\n"
		"**                                                                  **\n"
		"**                       1.��Ϣ���ʼ��                             **\n"
		"**                       2.������Ϣ��                               **\n"
		"**                                                                  **\n"
		"**                       4.��ѯ��n����Ϣ                            **\n"
		"**                       5.��ѯ��Ϣλ��                             **\n"
		"**                       6.����ָ����Ϣ                             **\n"
		"**                       7.ɾ��ָ��λ����Ϣ                         **\n"
		"**                       8.��ӡ��Ϣ��                               **\n"
		"**                       0.�˳�ϵͳ                                 **\n"
		"**                                                                  **\n"
		"**                                                                  **\n"
		"**********************************************************************\n"
		);
	printf("��������Ӧ������ѡ�����Ӧ�Ĺ���\n");
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
		Head();			//�����Ӻ���
		scanf("%d", &s);

		switch (s)
		{
		case 1:{
				   L = Init_InformationTable();
				   if (L == NULL)
				   {
					   printf("����˳����ڴ�ռ�ʧ�ܣ����������\n");
					   return 0;
				   }
				   else
					   printf("��Ϣ���ʼ���ɹ���\n");
		}; break;
		case 2: {
					*creatInformationTable(L);
		}; break;

		case 3: {
					printf("��������Ҫɾ����Ԫ�أ�");
					scanf("%d", &i);
					deleteList(L, i);
		}; break;
		case 4: printTable(L); break;
		case 0: quit = 1; break;
		default:printf("������0~4֮�������\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		system("pause");
		printf("���������\n");
	}
	return 0;
}

