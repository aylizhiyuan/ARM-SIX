#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    struct line * prior;
    int data;
    struct line *next;
}line;
//双链表的创建函数
line * initLine(line * head);
//输出双链表的函数
void display(line * head);
int main(){
    //创建一个头指针
    line * head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的链表
    display(head);
    //显示双链表的优点
    printf("链表中的第4个节点的直接前驱是%d",head->next->next->next->prior->data);
    return 0;
}
line *initLine(line *head){
    //创建一个首元节点，链表的头指针为head
    head = (line*)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    //晟敏一个指向首元节点的指针，方便后期添加节点
    line * list = head;
    for(int i=2;i<=5;i++){
        //创建新的节点并初始化
        line * body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = 1;

        //新的节点与链表最后一个节点建立关系
        

    }

}
void display(line * head){
    
}