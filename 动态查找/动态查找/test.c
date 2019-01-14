#include?"dsearch.h"
#include?"stdio.h"
#include?"stdlib.h"

/**
?*?search?the?binary?search?tree
 ?*?if?find?it,?p?point?to?it,
  ?*?if?not?find,?p?point?to?the?last?of?the?path.
   ?*?f?is?the?parent?of?tree.
	?*/
bool?searchBST(BTree?tree, KeyType?key, BTree?f, BTree?&p){
	if (!tree){
		p? = f;
		return?0;
	}
	else{
		if (EQ(tree->data.key, key)){
			p? = tree;
			printf("find?%d ", key);
			return?1;
		}
		else{
			if (LT(key, tree->data.key)){
				return?searchBST(tree->left, key, tree, p);
			}
			else{
				return?searchBST(tree->right, key, tree, p);
			}
		}
	}
}

//insert?the?node
bool?insertBST(BTree?&T, ElemType?e){
	BTree?p;
	if (!searchBST(T, e.key, NULL, p)){
		BTree?s? = (BTree)malloc(sizeof(BNode));
		s->data? = e;
		s->left? = s->right? = NULL;
		if (!p){
			T? = s;
		}
		else{
			if (LT(e.key, p->data.key)){
				p->left? = s;
			}
			else{
				p->right? = s;
			}
		}
		printf("insert?%d ", e.key);
		return?1;
	}
	else{
		return?0;
	}
}

int?deleteNode(BTree?&p){
	BTree?q, s;
	if (!p->right){
		printf("%d's?right?is?null,?delete?%d ", p->data, p->data);
		q? = p;
		p? = p->left;
		free(q);
	}
	else{
		if (!p->left){
			printf("%d's?left?is?null,?delete?%d ", p->data, p->data);
			q? = p;
			p? = p->right;
			free(q);
		}
		else{
			//both?the?left?and?right?are?not?null
			printf("%d's?left?and?right?are?not?null,?delete?%d ", p->data, p->data);
			q? = p;
			s? = p->left;
			while (s->right){
				q? = s;
				s? = s->right;
			}
			p->data? = s->data;

			if (q? != p){
				q->right? = s->left;
			}
			else{
				q->left? = s->left;
			}

			free(s);

		}
	}
	return?1;
}

//delete?a?node
int?deleteBST(BTree?&T, KeyType?key){
	if (!T){
		return?0;
	}
	else{
		if (EQ(key, T->data.key)){
			return?deleteNode(T);
		}
		else{
			if (LT(key, T->data.key)){
				return?deleteBST(T->left, key);
			}
			else{
				return?deleteBST(T->right, key);
			}
		}
		return?1;
	}
}

void?main(){
	????/**
		?????*?when?use?this?stmt:?BTree?tree;
			 ?????*?program?will?run?error,?why?
				  ?????*?see?the?first?stmt?of?searchBST.
					   ?????*/
	BTree?tree? = NULL;
	ElemType?e;
	int?w[] = { 45, 24, 53, 45, 12, 24, 90 };

	for (int?i? = 0; i?< 7; i++){
		e.key? = w[i];
		insertBST(tree, e);
	}

	deleteBST(tree, 24);
	deleteBST(tree, 53);
	deleteBST(tree, 45);
}
-------------------- -
作者：nomad2
来源：CSDN
原文：https ://blog.csdn.net/nomad2/article/details/1561144 
版权声明：本文为博主原创文章，转载请附上博文链接！