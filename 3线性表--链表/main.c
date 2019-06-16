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
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link * delElem(link * p,int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p,int elem);
//更新结点的函数，newElem为新的数据域的值
link *amendElem(link * p,int add,int newElem);
int main(){
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p=initLink();
    display(p);
  
    printf("在第4的位置插入元素5：\n");
    p=insertElem(p, 5, 4);
    display(p);
  
    printf("删除元素3:\n");
    p=delElem(p, 3);
    display(p);
  
    printf("查找元素2的位置为：\n");
    int address=selectElem(p, 2);
    if (address==-1) {
        printf("没有该元素");
    }else{
        printf("元素2的位置为：%d\n",address);
    }
    printf("更改第3的位置上的数据为7:\n");
    p=amendElem(p, 3, 7);
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
//删除链表的节点
link *delElem(link *p,int add){
    link *temp = p;
    //依然是找到被删除节点的上一个节点
    for(int i=1;i<add;i++){
        temp = temp->next;
    }
    //单独设置一个指针指向被删除的节点，以防止丢失
    link *del = temp->next;
    //删除某个节点的方法就是更改前一个节点的指针
    temp->next = temp->next->next;
    free(del);//手动释放该节点，防止内存泄漏
    return p;
}
//选择节点中的某个
int selectElem(link *p,int elem){
    link *t = p;
    int i = 1;
    while(t->next){
        t = t->next;
        if(t->elem == elem){
            return i;
        }
        i++;  
    }
    return -1;
}
//修改某个节点
link *amendElem(link *p,int add,int newElem){
    link *temp = p;
    temp = temp->next;//temp指向首元节点
    //temp指向被删除的结点
    for(int i=1;i<add;i++){
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
