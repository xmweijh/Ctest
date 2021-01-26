#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

struct Person
{
    char name[64];
    int age;
};

void test01()
{
    //初始化栈
    SeqStack myStack = init_SeqStack();

    //创建数据
    struct Person p1 = {  "aaa", 10 };
    struct Person p2 = {  "bbb", 20 };
    struct Person p3 = {  "ccc", 30 };
    struct Person p4 = {  "ddd", 40 };
    struct Person p5 = {  "eee", 50 };

    //入栈
    push_SeqStack(myStack, &p1);
    push_SeqStack(myStack, &p2);
    push_SeqStack(myStack, &p3);
    push_SeqStack(myStack, &p4);
    push_SeqStack(myStack, &p5);

    printf("栈的元素个数为：%d\n", size_SeqStack(myStack));

    while (isEmpty_SeqStack(myStack) == 0) //栈不为空，查看栈顶元素，出栈
    {
        struct Person * p = top_SeqStack(myStack);
        printf("姓名：%s 年龄：%d\n", p->name, p->age);

        //出栈
        pop_SeqStack(myStack);
    }

    printf("栈的元素个数为：%d\n", size_SeqStack(myStack));

    //销毁栈
    destroy_SeqStack(myStack);
}

int main(){
    test01();


    system("pause");
    return EXIT_SUCCESS;
}
