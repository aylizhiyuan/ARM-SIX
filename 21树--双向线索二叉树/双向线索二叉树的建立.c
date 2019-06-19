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

void InOrderThread_Head(BiThrTree *h, BiThrTree t)
{
    
    (*h) = (BiThrTree)malloc(sizeof(BiThrNode));
    if((*h) == NULL){
        printf("申请内存失败");
        return ;
    }
    (*h)->rchild = *h;
    (*h)->Rtag = Link;
    
    if(!t){
        (*h)->lchild = *h;
        (*h)->Ltag = Link;
    }
    else{
        pre = *h;
        (*h)->lchild = t;
        (*h)->Ltag = Link;
        InThreading(t);
        pre->rchild = *h;
        pre->Rtag = Thread;
        (*h)->rchild = pre;
    }
}

void InOrderThraverse_Thr(BiThrTree h)
{
    BiThrTree p;
    p = h->lchild;           
    while(p != h)
    {
        while(p->Ltag == Link)  
        {
            p = p->lchild;
        }
        printf("%c ", p->data);  
        while(p->Rtag == Thread && p->rchild != h)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }

        p = p->rchild;          
    }
}
int main() {
    BiThrTree t;
    BiThrTree h;
    printf("输入前序二叉树:\n");
    CreateTree(&t);
    InOrderThread_Head(&h, t);
    printf("输出中序序列:\n");
    InOrderThraverse_Thr(h);
    return 0;
}
