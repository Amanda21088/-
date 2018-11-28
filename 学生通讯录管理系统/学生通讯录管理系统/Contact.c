#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
void InitContact(Contact* pcon)
{
	pcon->sz = 0;
	assert(pcon != NULL);
	pcon->sz = 0;
	pcon->capacity = DEFAULT_SIZE;
	pcon->data = (PeoInfo*)malloc(pcon->capacity*sizeof(PeoInfo));
	memset(pcon->data, 0, pcon->capacity*sizeof(PeoInfo));
}
void DestoryContact(Contact* pcon)
{
	assert(pcon);
	free(pcon->data);
	pcon->data = NULL;
	pcon->sz = 0;
	pcon->capacity = 0;
}
//���ݺ���
int CheckCapacity(Contact* pcon)
{
	assert(pcon);
	if (pcon->sz == pcon->capacity)
	{
		PeoInfo *ptr = realloc(pcon->data,(pcon->capacity+2)*sizeof(PeoInfo*));
		if (ptr != NULL)
		{
			pcon->data = ptr;
			pcon->capacity += 2;
			return 1;
		}
		else
		{

			return 0;
		}
	}
	return 1;
}
void AddContact(Contact* pcon)
{
	assert(pcon != NULL);
	if (CheckCapacity(pcon) == 0)
	{
		printf("����ʧ��");
		return;
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("���������䣺>");
		scanf("%d", &(pcon->data[pcon->sz].age));
		printf("�������Ա�>");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("������绰��>");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("�������ַ��>");
		scanf("%s", pcon->data[pcon->sz].addr);

		pcon->sz++;
		printf("��ӳɹ�\n");
	}
}
void ShowContact(const Contact*pcon)
{
	int i = 0;
	assert(pcon != NULL);
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n"
			, pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}
static int FindEntry(Contact*pcon, char name[])//ֻ���ڵ�ǰԴ�ļ����ܿ�������ֹ��¶
{
	int i = 0;
	assert(pcon != NULL);
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
		{
			return i;//�ҵ���
		}
	}
	return -1;//û�ҵ�
}
void DelContact(Contact* pcon)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	assert(pcon != NULL);
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�ɾ��\n");
	}
	else
	{
		printf("������ɾ���˵�����:>");
		scanf("%s", name);
		pos = FindEntry(pcon, name);
		if (pos == -1)
		{
			printf("Ҫɾ�����˲�����\n");
		}
		else
		{
			//ɾ��
			int i = 0;
			for (i = pos; i < pcon->sz - 1; i++)
			{
				pcon->data[i] = pcon->data[i + 1];
			}
			pcon->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}
void SearchContact( Contact* pcon)
{
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	assert(pcon != NULL);
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�����\n");
	}
	else
	{
		printf("��������Ҫ�����˵�����:>");
		scanf("%s", name);
		pos = FindEntry(pcon, name);
		if (pos == -1)
		{
			printf("Ҫ���ҵ��˲�����\n");
		}
		else
		{
			//��ӡ
			int i = pos;
			while (i)
			{
				printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n"
					, pcon->data[i].name,
					pcon->data[i].age,
					pcon->data[i].sex,
					pcon->data[i].tele,
					pcon->data[i].addr);

			}

		}
	}
}
void ModifyContact(Contact* pcon)
{
	assert(pcon != NULL);
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	assert(pcon != NULL);
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷��޸�\n");
	}
	else
	{
		printf("��������Ҫ�޸��˵�����:>");
		scanf("%s", name);
		pos = FindEntry(pcon, name);
		if (pos == -1)
		{
			printf("Ҫ���ҵ��˲�����\n");
		}
		else
		{
			int tmp = pos;
			printf("����������Ϣ:>\n");
			scanf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n"
				, pcon->data[tmp].name,
				pcon->data[tmp].age,
				pcon->data[tmp].sex,
				pcon->data[tmp].tele,
				pcon->data[tmp].addr);
			printf("�޸ĳɹ�");

		}
	}

}
void EmptyContact(Contact *pcon)
{
	int i = 0;
	for (i = 0; i < pcon->sz - 1; i++)
	{
		memset(pcon->data[i].name, 0, sizeof(pcon->data[0]));
		memset(pcon->data[i].age, 0, sizeof(pcon->data[0]));
		memset(pcon->data[i].sex, 0, sizeof(pcon->data[0]));
		memset(pcon->data[i].tele, 0, sizeof(pcon->data[0]));
		memset(pcon->data[i].addr, 0, sizeof(pcon->data[0]));
	}
	printf("��ճɹ�");
}
void Sortcontact(Contact* pcon)  //������������ϵ��
{
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i<pcon->sz - 1; i++)
	{
		flag = 0;
		for (j = 0; j<pcon->sz - 1 - i; j++)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)

			break;

	}
}

