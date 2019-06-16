#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//每一个指令，在具体的计算机cpu运行的时间是固定的
//通过具体的步骤的多少我们就可以推导出算法的复杂度
long sum1(int n){
    long ret = 0; //1步
    int* array = (int*)malloc(n * sizeof(int)); //1
    int i = 0; //1
    for(i=0;i<n;i++){
        array[i] = i + 1; //n
    }
    for(i=0;i<n;i++){
        ret += array[i]; //n
    }
    free(array);
    return ret;
}
//执行完sum1需要2n+3
long sum2(int n){
    long ret = 0; //1
    int i = 0; //1
    for(i=1;i<=n;i++){ //n
        ret += i;
    }
    return ret;
}
//执行完sum2需要n+2
long sum3(int n){
    long ret = 0; //1
    if(n > 0){
        ret = (1+n)*n/2; //1
    }
    return ret;
}
//执行完sum3需要2步
int main(){
    printf("%ld\n",sum1(100));
    printf("%ld\n",sum2(100));
    printf("%ld\n",sum3(100));
    return 0;
}

//这就是大O表示法
//如果是2n+3的话，如果n是无穷大的话，那么乘以2也是无穷大，那么它算法的复杂度就是O(n)
//如果是n+2的话，如果n是无穷大的话，那么加2也是无穷大，那么它的算法的复杂度也是O(n)
//如果是2的话，那么是O(1)

//时间复杂度的度量