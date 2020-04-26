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
	printf("参照数据为：%s\n", definition);

	bt=CreateBiTree(definition);
	
	printf("先序遍历：");
	PreOrderTraverse(bt, visit);
	printf("\n中序遍历：");
	InOrderTraverse(bt, visit);

	printf("\n后序遍历：");
	PostOrderTraverse(bt, visit);

	printf("\n层次遍历：");
	LevelOrderTraverse(bt, visit);

	DestroyBiTree(bt);
	printf("\n-----------------------------------------------------------\n");

	printf("\n已实现中缀和前缀表达式的计算器↓\n");
	printf("\n-----------------------------------------------------------\n");

	printf("二叉树实现中缀表达式计算器：\n");
	BiTree btcul = NULL;
	char* str = "2+3*4";
	printf("参照输入数据为：%s\n", str);		

	btcul = CRTree(str, 0, strlen(str) - 1);
	printf("result=%.2lf\n\n", Value(btcul));	
	DestroyBiTree(btcul);

	BiTree btcul1 = NULL;
	char* str1 = "1+2*3-4/5";
	printf("参照输入数据为：%s\n", str1);

	btcul1 = CRTree(str1, 0, strlen(str1) - 1);
	printf("result=%.2lf\n\n", Value(btcul1));
	DestroyBiTree(btcul1);

	BiTree btcul2 = NULL;
	char* str2 = "9+2*3/5";
	printf("参照输入数据为：%s\n", str2);

	btcul2 = CRTree(str2, 0, strlen(str2) - 1);
	printf("result=%.2lf\n\n", Value(btcul2));
	DestroyBiTree(btcul2);

	BiTree btcul5 = NULL;
	char* str5;
	char a[MAX];
	str5 = a;
	printf("可输入容量小于%d且数字为0-9的中缀表达式\n", MAX);
	scanf("%s", str5);
	printf("输入数据为：%s\n", str5);

	btcul5 = CRTree(str5, 0, strlen(str5) - 1);
	printf("\n层次遍历：");
	LevelOrderTraverse(btcul5, visit);
	printf("\nresult=%.2lf\n\n", Value(btcul5));
	DestroyBiTree(btcul5);

	printf("\n-----------------------------------------------------------\n");
	printf("二叉树实现前缀表达式计算器：\n");
	
	BiTree btcul4 = NULL;
	char* str4 = "-*+123/42\nresult=7.00";
	printf("参照输入数据为：%s\n", str4);
	char* str6;
	char b[MAX];
	str6 = b;
	printf("\n可输入容量小于%d且数字为0-9的前缀缀表达式\n", MAX);
	scanf("%s", str6);
	printf("输入数据为：%s\n", str6);
	Create(&btcul4, str6);
	fflush(stdin);
	printf("\n层次遍历：");
	LevelOrderTraverse(btcul4, visit);
	printf("\nresult=%.2lf\n\n", Value(btcul4));
	DestroyBiTree(btcul4);

	system("PAUSE");
	return 0;
}