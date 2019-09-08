#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define N 5000
//int father[N];
//int rank1[N];
//int v, l;
//typedef struct Kruskal{
//	int a, b, value;
//} Kruskal;
//
//bool cmp(const Kruskal & a, const Kruskal & b)
//{
//	return a.value < b.value;
//}
//
//void ini(int size1){
//	for (int i = 1; i <= size1; i++)
//	{
//		father[i] = i;
//		rank1[i] = 0;
//	}
//}
//
//int find1(int x){
//	if (x != father[x])
//		father[x] = find1(father[x]);
//	return father[x];
//}
//
//bool unions(int x, int y){
//	int fx, fy;
//	fx = find1(x), fy = find1(y);   
//	if (fx == fy) return false;   
//	else if (rank1[fx] >= rank1[fy])
//	{   
//		father[fy] = fx;
//		rank1[fx] += rank1[fy];
//	}
//	else{
//		father[fx] = fy;
//		rank1[fy] += rank1[fx];
//	}
//	return true;
//}
//int main()
//{
//	int ltotal, sum, flag;
//	while (cin >> l >> v && l){
//		Kruskal G[N];
//		ltotal = 0, sum = 0, flag = 0;
//		ini(v);
//		for (int i = 1; i <= l; i++)
//			cin >> G[i].a >> G[i].b >> G[i].value;
//		//排序
//		sort(G + 1, G + 1 + l, cmp);
//		for (int i = 1; i <= l; i++){
//			if (unions(G[i].a, G[i].b)){
//				ltotal++;
//				sum += G[i].value;
//			}
//			if (ltotal == v - 1){
//				flag = 1;
//				break;
//			}
//		}
//		if (flag)
//			cout << sum << endl;
//		else
//			cout << "?" << endl;
//	}
//	return 0;
//}
//猜数字游戏
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void menu()
//{
//	printf("###################################\n");
//	printf("############ 1.play ###############\n");
//	printf("############ 0.exit ###############\n");
//	printf("###################################\n");
//}
//
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("请输入猜的数字>:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("猜大了");
//		}
//		else if (input < random_num)
//		{
//			printf("猜小了");
//		}
//		else
//		{
//			printf("恭喜你，猜对了!\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("选择错误，请重新输入！\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char input[10] = { 0 };
	system("shutdown - s - t 60 ");
	scanf("%s", input);
	if (0 == strcmp(input, "我是猪")
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	system("pause")
	return 0;
}