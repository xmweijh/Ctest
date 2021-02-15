#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X ){
// 函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
    if(BST==NULL){
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
        return BST;
    }
    BinTree BT=(BinTree)malloc(sizeof(struct TNode));
    BT=BST;
    int flag=0;
    while(BT!=NULL){
        if(X>BT->Data){
            if(BT->Right!=NULL){
                BT=BT->Right;
            }else{
                flag=1;
                break;
            }
        }else{
            if(BT->Left!=NULL){
                BT=BT->Left;
            }else{
                flag=2;
                break;
            }
        }
    }
    if(flag==2){
        BT->Left=(BinTree)malloc(sizeof(struct TNode));
        BT->Left->Data=X;
        BT->Left->Left=NULL;
        BT->Left->Right=NULL;
    }else if(flag==1){
        BT->Right=(BinTree)malloc(sizeof(struct TNode));
        BT->Right->Data=X;
        BT->Right->Left=NULL;
        BT->Right->Right=NULL;
    }
    return BST;
}
Position Find( BinTree BST, ElementType X ){
// 函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
    while(BST!=NULL){
        if(X>BST->Data){
            BST=BST->Right;
        }else if(X<BST->Data){
            BST=BST->Left;
        }else{
            break;
        }
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X ){
// 函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
    if(BST==NULL){
        printf("Not Found\n");
        return BST;
    }
    if(BST->Data==X){
        if(BST->Left!=NULL && BST->Right!=NULL){
            BinTree insert=(BinTree)malloc(sizeof(struct TNode));
            insert=BST->Right;
            BinTree father=(BinTree)malloc(sizeof(struct TNode));
            father=BST->Left;
            BST=BST->Left;
            while(father->Right!=NULL){
                father=father->Right;
            }
            father->Right=insert;
            return BST;
        }else if(BST->Left!=NULL && BST->Right==NULL){
            return BST->Left;
        }else if(BST->Left==NULL && BST->Right!=NULL){
            return BST->Right;
        }else{
            return NULL;
        }
    }
    int flag=0;
    BinTree father=(BinTree)malloc(sizeof(struct TNode));
    father=BST;
    while(father!=NULL){
        if(father->Left!=NULL && father->Left->Data==X){
            flag=1;
            break;
        }
        if(father->Right!=NULL && father->Right->Data==X){
            flag=2;
            break;
        }
        if(father->Data<X){
            father=father->Right;
        }else{
            father=father->Left;
        }
    }
    if(father==NULL){
        printf("Not Found\n");
        return BST;
    }
    if(flag==1){
        if(father->Left->Left!=NULL && father->Left->Right!=NULL){
            BinTree insert=(BinTree)malloc(sizeof(struct TNode));
            insert=father->Left->Right;
            BinTree move=(BinTree)malloc(sizeof(struct TNode));
            move=father->Left->Left;
            father->Left=move;
            while(move->Right!=NULL){
                move=move->Right;
            }
            move->Right=insert;
            return BST;
        }else if(father->Left->Left==NULL && father->Left->Right!=NULL){
            father->Left=father->Left->Right;
            return BST;
        }else if(father->Left->Left!=NULL && father->Left->Right==NULL){
            father->Left=father->Left->Left;
            return BST;
        }else{
            father->Left=NULL;
            return BST;
        }
    }else{
        if(father->Right->Left!=NULL && father->Right->Right!=NULL){
            BinTree insert=(BinTree)malloc(sizeof(struct TNode));
            insert=father->Right->Right;
            BinTree move=(BinTree)malloc(sizeof(struct TNode));
            move=father->Right->Left;
            father->Right=move;
            while(move->Right!=NULL){
                move=move->Right;
            }
            move->Right=insert;
            return BST;
        }else if(father->Right->Left==NULL && father->Right->Right!=NULL){
            father->Right=father->Right->Right;
            return BST;
        }else if(father->Right->Left!=NULL && father->Right->Right==NULL){
            father->Right=father->Right->Left;
            return BST;
        }else{
            father->Right=NULL;
            return BST;
        }
    }
}
Position FindMin( BinTree BST ){
// 函数FindMin返回二叉搜索树BST中最小元结点的指针；
    if(BST==NULL){
        return NULL;
    }
    while(BST->Left!=NULL){
        BST=BST->Left;
    }
    return BST;
}
Position FindMax( BinTree BST ){
// 函数FindMax返回二叉搜索树BST中最大元结点的指针。
    if(BST==NULL){
        return NULL;
    }
    while(BST->Right!=NULL){
        BST=BST->Right;
    }
    return BST;
}
