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

}
void display(line * head){
    
}