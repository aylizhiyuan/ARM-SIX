#include <stdio.h>
#include <stdlib.h>
#define TElemType char

typedef enum {
    Link,
    Thread
}PointerTag;

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode* lchild,*rchild;
    PointerTag Ltag,Rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre=NULL;

void CreateTree(BiThrTree * tree){
    char data;
    scanf("%c",&data);
    if (data!='#'){
        if (!((*tree)=(BiThrNode*)malloc(sizeof(BiThrNode)))){
            printf("申请节点空间失败");
            return;
        }else{
            (*tree)->data=data;
            CreateTree(&((*tree)->lchild));
            CreateTree(&((*tree)->rchild));
        }
    }else{
        *tree=NULL;
    }
}

void InThreading(BiThrTree p){
    
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->Ltag=Thread;
            p->lchild=pre;
        }
       
        if (pre&&!pre->rchild) {
            pre->Rtag=Thread;
            pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild);
    }
}

void InOrderThraverse_Thr(BiThrTree p)
{
    while(p)
    {
        
        while(p->Ltag == Link){
            p = p->lchild;
        }
        printf("%c ", p->data);  
        
        while(p->Rtag == Thread && p->rchild !=NULL)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
       
        p = p->rchild;
    }
}

int main() {
    BiThrTree t;
    printf("输入前序二叉树:\n");
    CreateTree(&t);
    InThreading(t);
    printf("输出中序序列:\n");
    InOrderThraverse_Thr(t);
    return 0;
}
