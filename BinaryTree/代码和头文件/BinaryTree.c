#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 15


//操作结果：构造空二叉树T
Status InitBiTree(BiTree *T) {

	*T= (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = NULL;
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	return SUCEESS;

}

//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status DestroyBiTree(BiTree T) {

	if (T) {
		if (T->lchild) {
			DestroyBiTree(T->lchild);
		}

		if (T->rchild) {
			DestroyBiTree(T->rchild);
		}

	}
	
	free(T);
	return SUCEESS;
}

BiTree CreateBiTree(char* definition) {
	
	BiTree T;
	char ch;
	static int i = 0;
	ch = definition[i++];
	if (ch == '#') {
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		T->lchild=CreateBiTree(definition);
		T->rchild=CreateBiTree(definition);
	}

	return T;
}



//以下部分函数定义未指定参数类型

//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败



//先序遍历
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {

	if (T){
		visit(T->data);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
	return SUCEESS;

}

//中序遍历
Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	if (T){
		
		InOrderTraverse(T->lchild, visit);
		visit(T->data);
		InOrderTraverse(T->rchild, visit);
	}
	return SUCEESS;
}

//后序遍历
Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	
	if (T){
		PostOrderTraverse(T->lchild, visit);		
		PostOrderTraverse(T->rchild, visit);
		visit(T->data);
	}
	return SUCEESS;
}

//层序遍历
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {

	AQueue Q;
	BiTree ch=NULL;
	InitAQueue(&Q);

	if (T) {
		EnAQueue(&Q, &T);
	}
	while (!IsEmptyAQueue(&Q)) {
		
		DeAQueue(&Q,&T);
		visit(T->data);
		if (T->lchild) {
			EnAQueue(&Q, &T->lchild);
		}
		if (T->rchild) {
			EnAQueue(&Q, &T->rchild);
		}
	}
	DestoryAQueue(&Q);
	return SUCEESS;

}



//表达式二叉树求值
double Value(BiTree T) {

	double v1, v2;
	
	if (T->lchild == NULL && T->rchild == NULL&& T->data>='0'&&T->data<='9') {
		return (double)(T->data - '0');
	}
		
	v1 = Value(T->lchild); //先计算左子树
	v2 = Value(T->rchild); //再计算右子树

	switch (T->data){

	case '+':
		return v1 + v2;

	case '-':
		return v1 - v2;

	case '*':
		return v1 * v2;

	case '/':
		if (v2 != 0)
			return v1 / v2;
		else
			abort();
	}

}

BiTree CRTree(char* s, int i, int j) {

	BiTree p;
	int k, plus = 0, posi;
	if (i == j){
		p = (BiTree)malloc(sizeof(BiTNode));   
		p->data = s[i];                       
		p->lchild = NULL;
		p->rchild = NULL;
		return p;
	}
	
	for (k = i; k <= j; k++)
		if (s[k] == '+' || s[k] == '-')
		{
			plus++;//若有+/-号
			posi = k; //最后一个+或-的位置
		}

	if (plus == 0) {
		for (k = i; k <= j; k++) {
			if (s[k] == '*' || s[k] == '/') {
				plus++;
				posi = k;
			}
		}			
	}
		
	//将+、-放到二叉树较高的层次上
	//后序遍历
	//处于较低层的乘除会优先运算

	//创建一个分支节点，用检测到的运算符作为节点值
	if (plus != 0)
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		p->data = s[posi]; //节点值是s[posi]
		p->lchild = CRTree(s, i, posi - 1); 
		p->rchild = CRTree(s, posi + 1, j); 
		return p;
	}

	else  return NULL;
}

void Create(BiTree *T,char *s)
{
	BiTree now;
	char c;
	static int j = 0;
	c = s[j++];
	
	if (c>='0' && c <= '9') {
		InitBiTree(&now);
		now->data = c;
		*T = now;
	
	}
	else{	
		InitBiTree(&now);
		now->data = c;
		*T = now;
		Create(&((*T)->lchild),s);
		Create(&((*T)->rchild), s);	
	}	
	
}


