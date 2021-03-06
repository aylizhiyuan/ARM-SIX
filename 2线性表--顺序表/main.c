#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table {
    int * head;//顺序表中的数据
    int length;//当前顺序表的长度
    int size;//记录顺序表分配的存储容量
}table;
//初始化顺序表
table initTable(){
    table t;
    t.head = (int *)malloc(Size * sizeof(int));
    if(!t.head){
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}
//往顺序表中添加元素
table addTable(table t,int elem,int add){
    //elem添加的元素，add添加的位置
    if(add > t.length +1 || add < 1){
        //如果要添加的位置大于当前顺序表的最大长度+1
        //或者位置取值不合法的话
        printf("插入位置有问题");
        return t;
    }
    if(t.length >= t.size){
        //如果顺序表的长度超出了顺序表的容量
        //添加一个位置
        t.head = (int *)realloc(t.head,(t.size+1)*sizeof(int));
        if(!t.head){
            printf("存储分配失败");
        }
        t.size+=1;
    }
    //将要添加的位置后的所有元素都移动一位，腾出添加的位置
    for(int i=t.length-1;i>=add-1;i--){
        t.head[i+1] = t.head[i];
    }
    t.head[add-1] = elem;
    t.length ++;
    return t;
}
//从顺序表中删除元素
table delTable(table t,int add){
    if(add > t.length||add <1){
        printf("被删除的元素位置有误");
        exit(0);
    }
    for(int i=add;i<t.length;i++){
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;
}
//从顺序表中选择某个元素
int selectTable(table t,int elem){
    for(int i=0;i<t.length;i++){
        if(t.head[i] == elem){
            return i+1;
        }
    }
    return -1;
}
//修改某个顺序表中的元素
table amendTable(table t,int elem,int newElem){
    int add = selectTable(t,elem);
    t.head[add-1] = newElem;
    return t;
}
//显示我们顺序表中的元素
void displayTable(table t){
    for(int i=0;i<t.length;i++){
        printf("%d",t.head[i]);
    }
    printf("\n");
}
int main(){
    table t1=initTable();
    for(int i=1;i<=Size;i++){
        t1.head[i-1] = i;
        t1.length++;
    }
    printf("原顺序表：\n");
    displayTable(t1);
  
    printf("删除元素1:\n");
    t1=delTable(t1, 1);
    displayTable(t1);
  
    printf("在第2的位置插入元素5:\n");
    t1=addTable(t1, 5, 2);
    displayTable(t1);
  
    printf("查找元素3的位置:\n");
    int add=selectTable(t1, 3);
    printf("%d\n",add);
  
    printf("将元素3改为6:\n");
    t1=amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}