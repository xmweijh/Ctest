#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//节点结构体
struct QueueNode
{
    struct QueueNode * next;
};

//队列结构体
struct LQueue
{
    struct QueueNode pHeader;
    int m_size;
    struct QueueNode * pTail;
};

typedef void * LinkQueue;

//初始化队列
LinkQueue init_LinkQueue()
{
     struct LQueue * myQueue = malloc(sizeof(struct  LQueue));

     if (myQueue == NULL)
     {
         return NULL;
     }

     myQueue->pHeader.next = NULL;

     myQueue->m_size = 0;

     myQueue->pTail = &myQueue->pHeader;

     return myQueue;
}
//入队
void push_LinkQueue(LinkQueue queue, void * data)
{
    if (queue == NULL)
    {
        return;
    }
    if ( data == NULL)
    {
        return;
    }

    //本质 尾插
    struct LQueue * myQueue = queue;


    struct QueueNode * myNode = data;

    //更改指针指向
    myQueue->pTail->next = myNode;
    myNode->next = NULL;

    //更新新的尾节点
    myQueue->pTail = myNode;

    myQueue->m_size++;

}
//出队
void pop_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return;
    }

    struct LQueue * myQueue = queue;

    //本质 头删

    if (myQueue->m_size == 0)
    {
        return;
    }

    if (myQueue->m_size == 1)
    {
        myQueue->pHeader.next = NULL;
        myQueue->pTail = &myQueue->pHeader;  //1个节点的时候，要将尾节点还原到头
        myQueue->m_size--;
        return;
    }

    //记录第一个有数据的节点
    struct QueueNode * pFirst = myQueue->pHeader.next;

    //更改指针指向
    myQueue->pHeader.next = pFirst->next;

    myQueue->m_size--;

}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return -1;
    }

    struct LQueue * myQueue = queue;
    return myQueue->m_size;


}
//判断是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return -1;
    }

    struct LQueue * myQueue = queue;
    if (myQueue->m_size == 0)
    {
        return 1;
    }
    return 0;

}
//返回队头
void * front_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }

    struct LQueue * myQueue = queue;

    return myQueue->pHeader.next;

}
//返回队尾
void * back_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }

    struct LQueue * myQueue = queue;
    return myQueue->pTail;
}
//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return;
    }

    free(queue);
    queue = NULL;

}
