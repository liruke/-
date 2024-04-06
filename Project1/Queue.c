#include "Queue.h"

//队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

//销毁队列
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
//队尾入，队头出。

//进队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	//多个节点
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
//取队头
QDataType  QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//取队尾
QDataType  QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//队列大小
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}