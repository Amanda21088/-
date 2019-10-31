#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strcpy������ͷ�ļ�
#include <assert.h>//��֤�Ϸ��Ե�ͷ�ļ�
#include <windows.h>

#define MAXLEN 256
#define BUFF_LEN 2

typedef struct MottoTable
{
	int ID;       //���� 
	char writer[MAXLEN];//���� 
	char sentence[MAXLEN];//����
	struct MottoTable *motto_next;
}Motto, *PMotto;

int Add_Motto(PMotto, PMotto);

void ShowDesk() //�˵�����
{
	system("cls");//����

	printf("-----------------------------���Ծ������ϵͳ--------------------------------\n");//�˵��Ĵ�ӡ

	printf("\n\t1.�����Ϣ\t2.ɾ����Ϣ\t3.�޸���Ϣ\n");

	printf("\t4.��ѯ��Ϣ\t5.��ʾ������Ϣ\n");

	printf("\t6.����������Ϣ���ļ�\n");

	printf("\t0.�˳�ϵͳ\n");

	printf("\n-------------------------------------------------------------------------\n");
}

void InitHead(PMotto motto_head)
{
	assert(motto_head != NULL); //��֤motto_head�ĺϷ��� 
	motto_head->motto_next = NULL;
}

void InitList(PMotto motto_head)
{
	assert(motto_head != NULL);
	FILE *fp = fopen("Motto.txt", "rb");//��ֻ������ʽ���ļ�
	if (fp == NULL)
	{
		fp = fopen("Motto.txt", "w");
		fclose(fp);//�ر��ļ�
		return;
	}
	char Buff[BUFF_LEN] = { 0 };//��ʼ��
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
				printf("error:�ַ�������\n");
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

int GetMessageW()//�˵�ѡ����
{
	int num;
	printf("��ѡ��˵�(0 ~ 6):");//����1��6

	while (1 != scanf("%d", &num) || num < 0 || num > 6)//�ж������Ƿ���ȷ
	{
		printf("ѡ��˵�����������ѡ��(0 ~ 6):");
		fflush(stdin);
	}

	return num;
}

int GetInputNum()
{
	int num;

	printf("�������ţ�");

	while (1 != scanf("%d", &num))
	{
		printf("����������������������(����)��");
		fflush(stdin);
	}

	return num;
}

PMotto Create_Motto(PMotto motto_head)//���뾯����
{
	assert(motto_head != NULL);
	PMotto pmotto = (PMotto)malloc(sizeof(Motto));

	while (!pmotto)
		pmotto = (PMotto)malloc(sizeof(Motto));

	memset(pmotto, 0, sizeof(Motto));
	printf("�����뾯���ţ�");

	while (1 != scanf("%d", &pmotto->ID) || GetPrevAddrMotto(motto_head, pmotto->ID))//�жϾ������Ƿ�Ϸ�
	{
		printf("������������Ѿ����ڣ����������뾯��ı�ţ�");
		fflush(stdin);
	}

	char tmp_writer[MAXLEN] = { 0 };//��ʼ��
	char tmp_sentence[MAXLEN] = { 0 };
	fflush(stdin);
	printf("����������������");//�����Ӧ����Ϣ
	fgets(tmp_writer, MAXLEN - 1, stdin);
	strncpy(pmotto->writer, tmp_writer, strlen(tmp_writer) - 1);
	printf("���������Ծ����ĶΣ�");
	fgets(tmp_sentence, MAXLEN - 1, stdin);
	strncpy(pmotto->sentence, tmp_sentence, strlen(tmp_sentence) - 1);//��Ӿ���
	printf("\n�����ϣ�\n");
	int sign;
	printf("����0�˳�:");
	while (1 != scanf("%d", &sign) || sign != 0)//�ж������Ƿ���ȷ
	{
		printf("ѡ��˵���������������:");
		fflush(stdin);
	}
	return pmotto;
}

int Add_Motto(PMotto motto_head, PMotto padd)//��Ӿ���ĺ���
{
	assert(motto_head != NULL);
	PMotto ps = motto_head;

	if (!padd || GetPrevAddrMotto(motto_head, padd->ID))//�жϾ����Ƿ�Ϸ���������û���ظ�
	{
		printf("���ʧ�ܣ����Ϊ%d����Ϣ�Ѿ����ڻ���ִ���\n", padd->ID);
		free(padd);
		return 0;
	}

	while (ps->motto_next)
		ps = ps->motto_next;

	ps->motto_next = padd;
	return 1;
}

void Delete_Motto(PMotto motto_head, int num)//ɾ������ĺ���
{
	PMotto p_motto, p_tmp;

	if (p_motto = GetPrevAddrMotto(motto_head, num))//�Զ�Ӧ�ľ����Ų���
	{
		p_tmp = p_motto->motto_next;
		p_motto->motto_next = p_tmp->motto_next;//�ж�����ı���Ƿ�Ϸ�
		free(p_tmp);
		printf("ɾ���˱��Ϊ%d����Ϣ��\n", num);
	}
	else
	{
		printf("û���ҵ����Ϊ%d����Ϣ��\n", num);
	}

	int sign;
	printf("����0�˳�:");
	while (1 != scanf("%d", &sign) || sign != 0)
	{
		printf("ѡ��˵���������������:");
		fflush(stdin);
	}
}

void Modity_Motto(PMotto motto_head, int num)//���Ҷ�Ӧ�ľ���
{
	PMotto pmotto = GetPrevAddrMotto(motto_head, num);

	if (!pmotto)                //�жϾ����Ƿ����
	{
		printf("û�б��Ϊ%d����Ϣ��\n", num);
	}
	else
	{
		pmotto = pmotto->motto_next;

		char tmp_writer[MAXLEN] = { 0 };
		char tmp_sentence[MAXLEN] = { 0 };

		printf("��ǰ����Ϊ��%s\n", pmotto->writer);//������ڣ��������Ӧ����Ϣ���ҵ���Ӧ�ı��
		printf("��������ĵ�����������");
		fgets(tmp_writer, MAXLEN - 1, stdin);
		strncpy(pmotto->writer, tmp_writer, strlen(tmp_writer) - 1);

		printf("��ǰ���֣�%s\n", pmotto->sentence);
		printf("��������ĵ����Ծ����ĶΣ�");
		fgets(tmp_sentence, MAXLEN - 1, stdin);
		strncpy(pmotto->sentence, tmp_sentence, strlen(tmp_sentence) - 1);//�����޸�

		printf("�޸���ϣ�\n");
	}

	int sign;
	printf("����0�˳�:");
	while (1 != scanf("%d", &sign) || sign != 0)
	{
		printf("ѡ��˵���������������:");
		fflush(stdin);
	}
}

void Select_Motto(PMotto motto_head, int num)//ѡ������Ӧ�ĺ���
{
	PMotto pmotto = GetPrevAddrMotto(motto_head, num);

	if (!pmotto)
	{
		printf("û�б��Ϊ%d����Ϣ��\n", num);
		return;
	}
	pmotto = pmotto->motto_next;//ָ����һ��

	printf("���ߣ�%s\n", pmotto->writer);
	printf("���Ծ��䣺%s\n", pmotto->sentence);
	int sign;
	printf("����0�˳�:");
	while (1 != scanf("%d", &sign) || sign != 0)
	{
		printf("ѡ��˵���������������:");
		fflush(stdin);
	}
}

void SelectAllStudent(PMotto motto_head) //���������������Ծ���
{
	PMotto pmotto = motto_head->motto_next;

	printf("--------------------------------------------------------------------\n");
	printf("\t���\t����\t���Ծ���\n");
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
	printf("����0�˳�:");
	while (1 != scanf("%d", &num) || num != 0)
	{
		printf("ѡ��˵���������������:");
		fflush(stdin);
	}
}

void SaveMottoToFile(PMotto motto_head)//������������Ծ���
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
	printf("����ɹ���\n");
	int sign;
	printf("����0�˳�:");
	while (1 != scanf("%d", &sign) || sign != 0)//�ж�����ı���Ƿ����
	{
		printf("ѡ��˵���������������:");
		fflush(stdin);
	}
	fclose(fp);

}

int main()//�������������Ϻ����ۺ���һ��
{
	int sign = 1;
	Motto head;
	InitHead(&head);
	InitList(&head);
	while (sign)
	{
		ShowDesk();
		switch (GetMessageW())//����switch�����ϱ��õ������к���
		{
		case 0: sign = 0; break;
		case 1: Add_Motto(&head, Create_Motto(&head)); break;
		case 2: Delete_Motto(&head, GetInputNum()); break;
		case 3: Modity_Motto(&head, GetInputNum()); break;
		case 4: Select_Motto(&head, GetInputNum()); break;
		case 5: SelectAllStudent(&head); break;
		case 6: SaveMottoToFile(&head); break;
		default:printf("ѡ��˵�����������ѡ��\n"); break;
		}
	}
	return 0;
}