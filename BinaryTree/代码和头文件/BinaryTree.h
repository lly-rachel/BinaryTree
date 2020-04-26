#include "AQueue.h"
typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
	TElemType      data;     // ������
	struct BiTNode* lchild, * rchild;  // ���Һ���ָ��
} BiTNode, * BiTree;   // ��������

typedef enum {
	SUCEESS,
	ERROR
}Status;


Status InitBiTree(BiTree* T);
//�������������ն�����T
Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T
BiTree CreateBiTree(char* definition);



//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e));	//�������


//���ʽ��������ֵ
double Value(BiTree T);

//��׺���ʽ���������
BiTree CRTree(char *s, int i, int j);

//ǰ׺���ʽ���������
void Create(BiTree *T,char *s);

/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
