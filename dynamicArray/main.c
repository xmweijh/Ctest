#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"

struct Person
{
    char name[64];
    int age;
};
void myPrintPerson(void *data)
{
    struct Person * p = data;
    printf("姓名： %s 年龄：%d\n", p->name, p->age);

}

int myComparePerson(void * data1, void *data2)
{
    struct Person *  p1 = data1;
    struct Person *  p2 = data2;

    return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int main(){

    //初始化动态数组
    struct dynamicArray * array = init_DynamicArray(5);

    //准备数据
    struct Person p1 = { "亚瑟", 18 };
    struct Person p2 = { "妲己", 20 };
    struct Person p3 = { "安琪拉", 19 };
    struct Person p4 = { "凯", 21 };
    struct Person p5 = { "孙悟空", 999 };
    struct Person p6 = { "李白", 999};

    printf("插入数据前： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);

    //插入数据
    insert_DynamicArray(array, 0, &p1);
    insert_DynamicArray(array, 0, &p2);
    insert_DynamicArray(array, 1, &p3);
    insert_DynamicArray(array, 0, &p4);
    insert_DynamicArray(array, -1, &p5);
    insert_DynamicArray(array, 2, &p6);

    // 凯 妲己 李白 安琪拉  亚瑟  孙悟空

    //遍历数据
    foreach_DynamicArray(array, myPrintPerson);


    printf("插入数据后： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);


    //测试删除 按位置删除
    removeByPos_DynamicArray(array, 2);
    printf("---------------------\n");
    foreach_DynamicArray(array, myPrintPerson);
    printf("删除数据后： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);

    struct Person  p = { "亚瑟", 18 };
    removeByValue_DynamicArray(array, &p, myComparePerson);
    printf("---------------------\n");
    foreach_DynamicArray(array, myPrintPerson);
    printf("删除数据后： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);


    //array->pAddr = NULL;
    //array->m_capacity = 0;
    //array->m_size = 0;

    //销毁数组
    destroy_DynamicArray(array);
    array = NULL;

    system("pause");
    return EXIT_SUCCESS;
}
