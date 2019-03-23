# 数据结构与算法的学习

1.  **数据结构的基本概念**  

数据：程序的操作对象，用于描述客观的事物
数据元素：组成数据的基本单位
数据项：一个数据元素由若干数据项组成
数据对象：性质相同的数据元素的集合（数组、链表）
数据结构：指数据对象中数据元素之间的关系

举例：

    //一种数据结构
    struct MyTeacher(){
        charname[32];
        chartitle[32];
        int age;
        char addr[128];
    }
    int main(){
        struct MyTeacher t1; //数据元素
        strcut MyTeacher tArray[30] //数据对象
        strcpy(t1.name,"name") // 数据项
    }

    
2.  **数据的逻辑结构**   

指的是元素之间的逻辑关系，即从逻辑关系上描述数据，它与数据的存储无关，是独立于计算机的，逻辑结构细分为四类：   

- 集合：数据元素间除了同属于一个集合外，无其他任何关系
- 线性结构：一个对一个，如线性表、栈、队列
- 树形结构：一个对多个，如树
- 图状结构：多个对多个，如图

3. **数据的物理结构**

指的是存储结构，是数据在计算机存储器内的表示

存储结构可分为4大类：
- 顺序：借助元素在存储器中的相对位置来表示数据元素间的逻辑关系
- 链式：借助指示元素存储地址的指针来表示数据元素之间的逻辑关系
- 索引
- 散列  

4. **数据的运算**

在数据的逻辑结构上定义的操作，它在数据的存储结构上实现。

最常用的数据运算有五种：
插入、删除、修改、查找、排序

5. **算法的概念**

算法是特定问题求解步骤的描述        
算法的特性： 
- 输入：算法具有0个或多个输入
- 输出：算法至少有1个或多个输出
- 有穷性：算法在有限的步骤之后自动结束而不会无限循环
- 确定性：算法中的每一步都有确定的含义，不会出现二义性
- 可行性：算法的每一步都是可行的

6. **算法效率的度量**












