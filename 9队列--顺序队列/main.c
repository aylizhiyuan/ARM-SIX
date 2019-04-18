#include <stdio.h>
#define max 5 //表示存储空间的大小
int enQueue(int *a,int front,int rear,int data){
    //添加判断语句，如果rear超过Max,则直接将其从a[0]重新开始存储
    //如果rear+1和front重合，说明数组已满
    if((rear+1)%max == front){
        printf("空间已满");
        return rear;
    }
    a[rear%max] = data;
    rear++;
    return rear;
}
int deQueue(int *a,int front ,int rear){
    if(front == rear%max){
        printf("队列为空");
        return front;
    }
    printf("%d",a[front]);
    front = (front+1)%max;
    return front;
}
int main(){
    int a[max];
    int front,rear;
    //设置队头指针和队尾指针，当队列中没有元素的时候，队头和队尾重合
    front = rear = 0;
    //入队
    rear = enQueue(a,front,rear,1);
    rear=enQueue(a,front,rear, 2);
    rear=enQueue(a,front,rear, 3);
    rear=enQueue(a,front,rear, 4);
    //出队
    front=deQueue(a, front, rear);
    //再入队
    rear=enQueue(a,front,rear, 5);
    //再出队
    front=deQueue(a, front, rear);
    //再入队
    rear=enQueue(a,front,rear, 6);
    //再出队
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    return 0;
}