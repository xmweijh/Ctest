#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dynamicArray
{
    void **pAddr; //维护数据的指针
    int m_capacity;//数据容量
    int m_size;//数组大小
};
//初始化队列
seqQueue init_SeqQueue()
{
    struct dynamicArray * arr = init_DynamicArray(MAX);

    return arr;
}
//入队
void push_SeqQueue(seqQueue queue, void * data)
{
    //本质  尾插

    if (queue == NULL)
    {
        return;
    }
    if ( data == NULL)
    {
        return;
    }
    struct dynamicArray * myQueue = queue;
    if (myQueue->m_size == MAX)
    {
        return;
    }

    insert_DynamicArray(myQueue, myQueue->m_size, data);

}
//出队
void pop_SeqQueue(seqQueue queue)
{
    //本质  头删

    if (queue == NULL)
    {
        return;
    }

    struct dynamicArray * myQueue = queue;

    if (myQueue->m_size <= 0 )
    {
        return;
    }

    removeByPos_DynamicArray(myQueue, 0);

}
//返回队列大小
int size_SeqQueue(seqQueue queue)
{
    if (queue == NULL)
    {
        return -1;
    }

    struct dynamicArray * myQueue = queue;

    return myQueue->m_size;

}
//判断队列是否为空
int isEmpty_SeqQueue(seqQueue queue)
{
    if (queue == NULL)
    {
        return -1;
    }
    struct dynamicArray * myQueue = queue;

    if (myQueue->m_size == 0)
    {
        return 1;
    }
    return 0;


}
//返回队头元素
void * front_SeqQueue(seqQueue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    struct dynamicArray * myQueue = queue;

    return myQueue->pAddr[0];

}
//返回队尾元素
void * back_SeqQueue(seqQueue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    struct dynamicArray * myQueue = queue;

    return myQueue->pAddr[myQueue->m_size-1];
}
//销毁队列
void destroy_SeqQueue(seqQueue queue)
{
    if (queue == NULL)
    {
        return;
    }

    destroy_DynamicArray(queue);

}
