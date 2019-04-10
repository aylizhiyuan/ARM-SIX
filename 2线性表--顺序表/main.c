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
        
    }
}
