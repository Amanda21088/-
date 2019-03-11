#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct BiTNode
{
	int value;
	struct BiTNode *lchild, *rchild;
}*BiTree;

bool LT(int a, int b)  //LessThanС��
{
	if (a<b)
		return true;
	else
		return false;
}
/*
�ڸ�ָ��root��ָ��Ķ����������еݹ�ز�����ؼ��ֵ���data������Ԫ�أ������ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������true��
����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����falseָ�룬ָ��fָ��root��˫�ף����ʼ����ֵNULL
*/
bool SearchBST(BiTree root, int data, BiTree f, BiTree &p)
{
	if (!root)
	{
		p = f;
		return false;
	}
	else if (data == root->value)   //���ҳɹ�
	{
		p = root;
		return true;
	}
	else if (data < root->value)  //����������������
		return SearchBST(root->lchild, data, root, p);
	else if (data > root->value)  //����������������
		return SearchBST(root->rchild, data, root, p);
}

//������������root�в����ڹؼ��ֵ���data������Ԫ��ʱ������data
inline void InsertBST(BiTree &root, int data)     //rootΪ������ָ��
{
	BiTree p, s;
	if (!SearchBST(root, data, NULL, p))    //���Ҳ��ɹ�
	{
		s = (struct BiTNode *)malloc(sizeof(BiTNode));
		s->value = data;
		s->lchild = s->rchild = NULL;
		if (p == NULL)    //����������Ϊ�յ�ʱ�򣬱�������*sΪ�µĸ����
			root = s;
		else if (LT(data, p->value))           //������*sΪ����
			p->lchild = s;
		else           //������*sΪ�Һ���
			p->rchild = s;
	}
	return;
}
void PreOrderTraverse(BiTree root)    //�������
{
	if (root)
	{
		printf("%d ", root->value);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}
}
void InOrderTraverse(BiTree root)    //�������
{
	if (root)
	{
		InOrderTraverse(root->lchild);
		printf("%d ", root->value);
		InOrderTraverse(root->rchild);
	}
}
void PostOrderTraverse(BiTree root)    //�������
{
	if (root)
	{
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%d ", root->value);
	}
}
int Delete(BiTree &p){
	BiTree q, s;
	if (!p->rchild){ //�������յĻ�ֻ���ؽ������� 
		q = p; p = p->lchild; free(q);
	}
	else if (!p->lchild){   //������Ϊ�յĻ���ֻ���ؽ�����������
		q = p; p = p->rchild; free(q);
	}
	else{  //������������Ϊ��
		q = p;  s = p->lchild;
		while (s->rchild) {   //ת��Ȼ�������ߵ���ͷ
			q = s; s = s->rchild;
		}
		p->value = s->value;  //sָ��ɾ������ǰ��
		if (q != p) { q->rchild = s->lchild; } //�ؽ�*q��������
		else { q->lchild = s->lchild; } //�ؽ�*q��������
		delete s;
	}
	return true;
}
int DeleteBST(BiTree &T, int key)
{
	if (!T) return false;
	else{
		if (key == T->value) return Delete(T);  //�ҵ��ؼ���Ϊkey������Ԫ��
		else if (key < T->value) return DeleteBST(T->lchild, key);//�ؼ���С�ڽ��Ļ�������������
		else return DeleteBST(T->rchild, key); //�ؼ��ִ��ڽ��Ļ�������������
	}
}

int main(void)
{
	int i, a[101], n, data, findkey, menu, insertkey;
	BiTree root, pp;
	printf("�����������Ĳ���:\n");
	printf("                1:��������������!\n");
	printf("                2:���ҹؼ���!\n");
	printf("                3:����ؼ���!\n");
	printf("                4:ɾ���ؼ���!\n");
	printf("                0:�˳�!\n");
	//������ĸ���
	printf("��������Ӧ����:");
	scanf("%d", &menu);
	while (!(menu >= 0 && menu <= 4)){
		printf("�������������⣬����������:");
		scanf("%d", &menu);
	}
	while (menu != 0){/////////////////////////////////////
		switch (menu){ ///////////////////////
		case 1:{ ///////////////////
				   printf("�����ʼ�����ĸ���:");
				   scanf("%d", &n);
				   root = NULL;
				   printf("�����������ֵ:");
				   for (i = 1; i <= n; i++)
				   {
					   scanf("%d", &a[i]);
					   InsertBST(root, a[i]);
				   }
				   printf("�������������:");
				   PreOrderTraverse(root);
				   printf("\n");
				   printf("�������������:");
				   InOrderTraverse(root);
				   printf("\n");
				   printf("�������������:");
				   PostOrderTraverse(root);
				   printf("\n");
				   break;
		}//////////////////////////////case
		case 2:{
				   printf("������Ҫ���ҵĹؼ���:");
				   scanf("%d", &findkey);
				   if (SearchBST(root, findkey, NULL, pp)){
					   printf("���ҳɹ���\n");
				   }
				   else{
					   printf("����ʧ�ܣ�\n");
				   }
				   break;
		}
		case 3:{
				   printf("�����������Ĺؼ���:");
				   scanf("%d", &insertkey);
				   InsertBST(root, insertkey);
				   printf("\n");
				   printf("�������������:");
				   InOrderTraverse(root);
				   printf("\n");
				   break;
		}
		case 4:{
				   printf("��������ɾ���Ĺؼ���:");
				   scanf("%d", &data);
				   DeleteBST(root, data);
				   printf("\n");
				   printf("�������������:");
				   InOrderTraverse(root);
				   printf("\n");
				   break;
		}
			/*
			while(scanf("%d",&n)!=EOF)
			{
			root=NULL;
			printf("�����������ֵ:");
			for(i=1;i<=n;i++)
			{
			scanf("%d",&a[i]);
			InsertBST(root,a[i]);
			}
			printf("�������������:");
			PreOrderTraverse(root);
			printf("\n");
			printf("�������������:");
			InOrderTraverse(root);
			printf("\n");
			printf("�������������:");
			PostOrderTraverse(root);
			printf("\n");
			printf("������Ҫ���ҵĹؼ���:");
			scanf("%d",&findkey);
			if(SearchBST(root,findkey,NULL,pp)){
			printf("���ҳɹ���\n");
			}else{
			printf("����ʧ�ܣ�\n");
			}

			printf("��������ɾ���Ĺؼ���:");
			scanf("%d",&data);
			DeleteBST(root,data);
			printf("\n");
			printf("�������������:");
			InOrderTraverse(root);
			}*/
		} //////switch
		printf("�����������Ӧ����:");
		scanf("%d", &menu);
	}//while
	return 0;
}
