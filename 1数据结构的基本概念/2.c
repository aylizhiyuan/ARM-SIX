#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//空间复杂度的度量
long sum1(int n){
    long ret = 0; //4个字节
    int* array = (int*)malloc(n * sizeof(int));  //4*n个字节
    int i = 0; 
    for(i=0;i<n;i++){
        array[i] = i + 1; //没有分配空间
    }
    for(i=0;i<n;i++){
        ret += array[i]; //没有分配空间
    }
    free(array);
    return ret;
}
//sum1的空间复杂度是4n+8,O(n)
long sum2(int n){
    long ret = 0;  //4
    int i = 0; //4
    for(i=1;i<=n;i++){ 
        ret += i;
    }
    return ret;
}
//sum2的空间复杂度是8,O(1)
long sum3(int n){
    long ret = 0; //4
    if(n > 0){
        ret = (1+n)*n/2; 
    }
    return ret;
}
//sum3的空间复杂度是4,O(1)
int main(){
    printf("%ld\n",sum1(100));
    printf("%ld\n",sum2(100));
    printf("%ld\n",sum3(100));
    return 0;
}
