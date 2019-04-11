#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    int elem;
    struct Link *next;
}link;
//初始化链表的函数
link * initLink();
//用于输出链表的函数
void display(link *p);
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link * insertElem(link * p,int elem,int add);
int main(){
    //初始化链表（1，2，3，4）
    printf("初始化链表为:\n");
    link *p = initLink();
    display(p);
    printf("在第四个位置插入元素5:\n");
    p = insertElem(p,5,4);
    display(p);
    return 0;
}
link *initLink(){
    link *p = NULL;//创建头指针
    link *temp = (link*)malloc(sizeof(link));//创建首元节点
    //首元节点初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//头指针指向首元节点
    for(int i=2;i<5;i++){
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
void display(link *p){
    link *temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是NULL，就执行输出语句
    while(temp){
        printf("%d",temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
//插入的话，只需要考虑插入位置的上一个节点，让上一个节点的指针指向新节点
//再让新的节点指向上一个节点的指针即可
link * insertElem(link * p,int elem,int add){
    link * temp = p;//创建一个临时的结点
    //首先找到要插入位置的上一个节点
    for(int i=1;i<add;i++){
        //i=1,2,3
        if(temp == NULL){
            printf("插入位置无效\n");
            return p;
        }
        //将插入的位置的前面所有的节点删除，循环下来，链表中只剩下插入位置的4的节点了
        temp = temp->next;
    }
    //创建插入结点5
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    //将4的指针的原来的值赋值给5的指针
    c->next = temp->next;
    //将4的指针指向新节点5
    temp->next = c;
    return p;
}