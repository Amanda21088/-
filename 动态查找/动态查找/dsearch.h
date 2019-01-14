#include<stdio.h>
#pragma once

#define?EQ(a, b)?((a) == (b))
#define?LT(a, b)?((a)?<?(b))
#define?LQ(a, b)?((a) <= (b))

typedef?int?KeyType;

typedef?struct?{
	KeyType?key;
}ElemType;

//binary?tree?node
typedef?struct?BNode{
	ElemType?data;
	struct?BNode?*left;
	struct?BNode?*right;
}BNode, *BTree;

