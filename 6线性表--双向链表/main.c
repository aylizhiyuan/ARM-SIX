#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    struct line * prior;
    int data;
    struct line *next;
}line;
//双链表的创建函数
line * initLine(line * head);
//双线链表插入元素，add表示插入位置
line * insertLine(line * head,int data,int add);
//双向链表删除指定元素
line * delLine(line * head,int data);
//双向链表查找指定元素
int selectElem(line * head,int elem);
//双向链表中更改指定位置节点中存储的数据,add 表示顺序
line * amendElem(line * p,int add,int newElem);

//输出双链表的函数
void display(line * head);
int main(){
    //创建一个头指针
    line * head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的链表
    display(head);
    //在表中第3的位置插入元素7
    head = insertLine(head,7,3);
    display(head);
    //表中删除元素2
    head = delLine(head,2);
    display(head);
    printf("元素3的位置是:%d\n",selectElem(head,3));
    //表中第三个节点中的数据改为存储6
    head = amendElem(head,3,6);
    display(head);
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
        list->next = body;
        body->prior = list;
        //list永远指向链表中的最后一个节点
        list = list->next;
    }
    return head;
}
//插入一个链表节点
line * insertLine(line *head,int data,int add){
    //新建数据域为data的节点
    line * temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //如果是插入到链表头部的话
    if(add == 1){
        temp->next = head;
        head->prior = temp;
        head = temp;
    }else{
        line * body =head;
        //找到要输入位置的前一个节点
        for(int i=1;i<add-1;i++){
            body = body->next;
        }
        //判断条件为真，说明插入的位置为链表尾部
        if(body->next == NULL){
            body->next = temp;
            temp->prior = body;
        }else{
            //body为插入位置的上一个节点
            //temp为新要插入的节点
            body->next->prior = temp;
            temp->next = body->next;
            body->next =temp;
            temp->prior = body;
        }
    }
    return head;
}
//删除一个链表节点
line * delLine(line *head,int data){
    line * temp = head;
    //遍历链表
    while(temp){
        //判断当前节点中的数据和data是否相同，若相同，则摘除该节点
        if(temp->data == data){
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中没有该数据元素");
    return head;
}
//查看一个链表节点
int selectElem(line * head,int elem){
    //新建一个指针t,初始化为头指针head
    line * t= head;
    int i = 1;
    while(t){
        if(t->data == elem){
            return i;
        }
        i++;
        t = t->next;
    }
    return -1;
}
//修改一个链表节点
line * amendElem(line * p ,int add,int newElem){
    line * temp = p;
    //遍历到被删除节点
    for(int i=1;i<add;i++){
        temp = temp->next;
    }
    temp->data = newElem;
    return p;
}
void display(line * head){
    line *temp = head;
    while(temp){
        //如果该节点无后续节点，说明此节点是最后一个节点
        if(temp->next == NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d <-> ",temp->data);
        }
        temp = temp->next;
    }   
}