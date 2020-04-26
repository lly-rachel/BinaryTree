#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 15


//�������������ն�����T
Status InitBiTree(BiTree *T) {

	*T= (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = NULL;
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	return SUCEESS;

}

//��ʼ������������T����
//����������ݻٶ�����T
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



//���²��ֺ�������δָ����������

//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��



//�������
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {

	if (T){
		visit(T->data);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
	return SUCEESS;

}

//�������
Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	if (T){
		
		InOrderTraverse(T->lchild, visit);
		visit(T->data);
		InOrderTraverse(T->rchild, visit);
	}
	return SUCEESS;
}

//�������
Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	
	if (T){
		PostOrderTraverse(T->lchild, visit);		
		PostOrderTraverse(T->rchild, visit);
		visit(T->data);
	}
	return SUCEESS;
}

//�������
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



//���ʽ��������ֵ
double Value(BiTree T) {

	double v1, v2;
	
	if (T->lchild == NULL && T->rchild == NULL&& T->data>='0'&&T->data<='9') {
		return (double)(T->data - '0');
	}
		
	v1 = Value(T->lchild); //�ȼ���������
	v2 = Value(T->rchild); //�ټ���������

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
			plus++;//����+/-��
			posi = k; //���һ��+��-��λ��
		}

	if (plus == 0) {
		for (k = i; k <= j; k++) {
			if (s[k] == '*' || s[k] == '/') {
				plus++;
				posi = k;
			}
		}			
	}
		
	//��+��-�ŵ��������ϸߵĲ����
	//�������
	//���ڽϵͲ�ĳ˳�����������

	//����һ����֧�ڵ㣬�ü�⵽���������Ϊ�ڵ�ֵ
	if (plus != 0)
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		p->data = s[posi]; //�ڵ�ֵ��s[posi]
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


