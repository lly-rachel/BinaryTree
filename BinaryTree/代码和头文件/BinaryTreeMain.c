#include "BinaryTree.h"
#include "AQueue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

Status visit(TElemType e) {

	if (sizeof(e) == 1) {
		printf(" %c ", e);
		return SUCEESS;
	}else if (sizeof(e) == 4) {
		printf("--%d--", e);
		return SUCEESS;
	}	
	else { return ERROR; }

}

int main() {

	BiTree bt=NULL;
	char* definition = "ABC##D##E#FG###";
	printf("��������Ϊ��%s\n", definition);

	bt=CreateBiTree(definition);
	
	printf("���������");
	PreOrderTraverse(bt, visit);
	printf("\n���������");
	InOrderTraverse(bt, visit);

	printf("\n���������");
	PostOrderTraverse(bt, visit);

	printf("\n��α�����");
	LevelOrderTraverse(bt, visit);

	DestroyBiTree(bt);
	printf("\n-----------------------------------------------------------\n");

	printf("\n��ʵ����׺��ǰ׺���ʽ�ļ�������\n");
	printf("\n-----------------------------------------------------------\n");

	printf("������ʵ����׺���ʽ��������\n");
	BiTree btcul = NULL;
	char* str = "2+3*4";
	printf("������������Ϊ��%s\n", str);		

	btcul = CRTree(str, 0, strlen(str) - 1);
	printf("result=%.2lf\n\n", Value(btcul));	
	DestroyBiTree(btcul);

	BiTree btcul1 = NULL;
	char* str1 = "1+2*3-4/5";
	printf("������������Ϊ��%s\n", str1);

	btcul1 = CRTree(str1, 0, strlen(str1) - 1);
	printf("result=%.2lf\n\n", Value(btcul1));
	DestroyBiTree(btcul1);

	BiTree btcul2 = NULL;
	char* str2 = "9+2*3/5";
	printf("������������Ϊ��%s\n", str2);

	btcul2 = CRTree(str2, 0, strlen(str2) - 1);
	printf("result=%.2lf\n\n", Value(btcul2));
	DestroyBiTree(btcul2);

	BiTree btcul5 = NULL;
	char* str5;
	char a[MAX];
	str5 = a;
	printf("����������С��%d������Ϊ0-9����׺���ʽ\n", MAX);
	scanf("%s", str5);
	printf("��������Ϊ��%s\n", str5);

	btcul5 = CRTree(str5, 0, strlen(str5) - 1);
	printf("\n��α�����");
	LevelOrderTraverse(btcul5, visit);
	printf("\nresult=%.2lf\n\n", Value(btcul5));
	DestroyBiTree(btcul5);

	printf("\n-----------------------------------------------------------\n");
	printf("������ʵ��ǰ׺���ʽ��������\n");
	
	BiTree btcul4 = NULL;
	char* str4 = "-*+123/42\nresult=7.00";
	printf("������������Ϊ��%s\n", str4);
	char* str6;
	char b[MAX];
	str6 = b;
	printf("\n����������С��%d������Ϊ0-9��ǰ׺׺���ʽ\n", MAX);
	scanf("%s", str6);
	printf("��������Ϊ��%s\n", str6);
	Create(&btcul4, str6);
	fflush(stdin);
	printf("\n��α�����");
	LevelOrderTraverse(btcul4, visit);
	printf("\nresult=%.2lf\n\n", Value(btcul4));
	DestroyBiTree(btcul4);

	system("PAUSE");
	return 0;
}