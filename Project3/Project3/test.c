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

bool LT(int a, int b)  //LessThan小于
{
	if (a<b)
		return true;
	else
		return false;
}
/*
在根指针root所指向的二叉排序树中递归地查找其关键字等于data的数据元素，若查找成功，则指针p指向该数据元素结点，并返回true，
否则指针p指向查找路径上访问的最后一个结点并返回false指针，指针f指向root的双亲，其初始调用值NULL
*/
bool SearchBST(BiTree root, int data, BiTree f, BiTree &p)
{
	if (!root)
	{
		p = f;
		return false;
	}
	else if (data == root->value)   //查找成功
	{
		p = root;
		return true;
	}
	else if (data < root->value)  //在左子树继续查找
		return SearchBST(root->lchild, data, root, p);
	else if (data > root->value)  //在右子树继续查找
		return SearchBST(root->rchild, data, root, p);
}

//当二叉排序树root中不存在关键字等于data的数据元素时，插入data
inline void InsertBST(BiTree &root, int data)     //root为传引用指针
{
	BiTree p, s;
	if (!SearchBST(root, data, NULL, p))    //查找不成功
	{
		s = (struct BiTNode *)malloc(sizeof(BiTNode));
		s->value = data;
		s->lchild = s->rchild = NULL;
		if (p == NULL)    //二叉排序树为空的时候，被插入结点*s为新的根结点
			root = s;
		else if (LT(data, p->value))           //被插结点*s为左孩子
			p->lchild = s;
		else           //被插结点*s为右孩子
			p->rchild = s;
	}
	return;
}
void PreOrderTraverse(BiTree root)    //先序遍历
{
	if (root)
	{
		printf("%d ", root->value);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}
}
void InOrderTraverse(BiTree root)    //中序遍历
{
	if (root)
	{
		InOrderTraverse(root->lchild);
		printf("%d ", root->value);
		InOrderTraverse(root->rchild);
	}
}
void PostOrderTraverse(BiTree root)    //后序遍历
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
	if (!p->rchild){ //右子树空的话只需重接它的左 
		q = p; p = p->lchild; free(q);
	}
	else if (!p->lchild){   //左子树为空的话，只需重接它的右子树
		q = p; p = p->rchild; free(q);
	}
	else{  //左右子树均不为空
		q = p;  s = p->lchild;
		while (s->rchild) {   //转左。然后向右走到尽头
			q = s; s = s->rchild;
		}
		p->value = s->value;  //s指向被删除结点的前驱
		if (q != p) { q->rchild = s->lchild; } //重接*q的右子树
		else { q->lchild = s->lchild; } //重接*q的左子树
		delete s;
	}
	return true;
}
int DeleteBST(BiTree &T, int key)
{
	if (!T) return false;
	else{
		if (key == T->value) return Delete(T);  //找到关键字为key的数据元素
		else if (key < T->value) return DeleteBST(T->lchild, key);//关键字小于结点的话，即在左子树
		else return DeleteBST(T->rchild, key); //关键字大于结点的话，即在右子树
	}
}

int main(void)
{
	int i, a[101], n, data, findkey, menu, insertkey;
	BiTree root, pp;
	printf("二叉排序树的操作:\n");
	printf("                1:创建二叉排序树!\n");
	printf("                2:查找关键字!\n");
	printf("                3:插入关键字!\n");
	printf("                4:删除关键字!\n");
	printf("                0:退出!\n");
	//输入结点的个数
	printf("请输入相应操作:");
	scanf("%d", &menu);
	while (!(menu >= 0 && menu <= 4)){
		printf("您的输入有问题，请重新输入:");
		scanf("%d", &menu);
	}
	while (menu != 0){/////////////////////////////////////
		switch (menu){ ///////////////////////
		case 1:{ ///////////////////
				   printf("输入初始化结点的个数:");
				   scanf("%d", &n);
				   root = NULL;
				   printf("输入各个结点的值:");
				   for (i = 1; i <= n; i++)
				   {
					   scanf("%d", &a[i]);
					   InsertBST(root, a[i]);
				   }
				   printf("输出先序遍历结果:");
				   PreOrderTraverse(root);
				   printf("\n");
				   printf("输出中序遍历结果:");
				   InOrderTraverse(root);
				   printf("\n");
				   printf("输出后序遍历结果:");
				   PostOrderTraverse(root);
				   printf("\n");
				   break;
		}//////////////////////////////case
		case 2:{
				   printf("输入你要查找的关键字:");
				   scanf("%d", &findkey);
				   if (SearchBST(root, findkey, NULL, pp)){
					   printf("查找成功！\n");
				   }
				   else{
					   printf("查找失败！\n");
				   }
				   break;
		}
		case 3:{
				   printf("请输入你插入的关键字:");
				   scanf("%d", &insertkey);
				   InsertBST(root, insertkey);
				   printf("\n");
				   printf("输出中序遍历结果:");
				   InOrderTraverse(root);
				   printf("\n");
				   break;
		}
		case 4:{
				   printf("输入你想删除的关键字:");
				   scanf("%d", &data);
				   DeleteBST(root, data);
				   printf("\n");
				   printf("输出中序遍历结果:");
				   InOrderTraverse(root);
				   printf("\n");
				   break;
		}
			/*
			while(scanf("%d",&n)!=EOF)
			{
			root=NULL;
			printf("输入各个结点的值:");
			for(i=1;i<=n;i++)
			{
			scanf("%d",&a[i]);
			InsertBST(root,a[i]);
			}
			printf("输出先序遍历结果:");
			PreOrderTraverse(root);
			printf("\n");
			printf("输出中序遍历结果:");
			InOrderTraverse(root);
			printf("\n");
			printf("输出后序遍历结果:");
			PostOrderTraverse(root);
			printf("\n");
			printf("输入你要查找的关键字:");
			scanf("%d",&findkey);
			if(SearchBST(root,findkey,NULL,pp)){
			printf("查找成功！\n");
			}else{
			printf("查找失败！\n");
			}

			printf("输入你想删除的关键字:");
			scanf("%d",&data);
			DeleteBST(root,data);
			printf("\n");
			printf("输出中序遍历结果:");
			InOrderTraverse(root);
			}*/
		} //////switch
		printf("请继续输入相应操作:");
		scanf("%d", &menu);
	}//while
	return 0;
}
