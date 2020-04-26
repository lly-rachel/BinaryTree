#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

/**************************************************************
 *    Macro Define Section
 **************************************************************/
#define MAXQUEUE 15
typedef unsigned int size_t;
/**************************************************************
 *    Struct Define Section
 **************************************************************/
 //ѭ�����нṹ
typedef struct Aqueue
{
	void* data[MAXQUEUE];      //������
	int front;
	int rear;
	size_t length;        //���г���
} AQueue;

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[MAXQUEUE];
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


void InitAQueue(AQueue* Q);
void DestoryAQueue(AQueue* Q);
void ClearAQueue(AQueue* Q);

Status IsFullAQueue(const AQueue* Q);
Status IsEmptyAQueue(const AQueue* Q);
Status GetHeadAQueue(AQueue* Q, void* e);
Status EnAQueue(AQueue* Q, void* data);
Status DeAQueue(AQueue* Q, void* data);
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q));
void APrint(void* q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED
