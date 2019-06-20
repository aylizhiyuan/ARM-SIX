#include <stdio.h>
#include <string.h>
void Next(char*T,int *next){
    //next数组里面的数据是{a,b,c,a,c}
    int i=1;
    next[1]=0;
    int j=0; 
    while (i<strlen(T)) {
        //当j=0的时候，我们先j++,i++
        //这时候i=2,j=1,next[1]=0,next[2] = 1;
        //接下来判断字符串中第一个元素和第二个元素是否相等
        //1.如果不相等，j的值依然是0，i的值是2
        //接下来，依然i++,j++ 
        //这时候i=3,j=1,next[3] = 1;
        //接下来，拿第一个元素和第三个元素判断是否相等
        //如果不相等的话，j的值依然是0，i的值变成了3
        //继续i++,j++
        //这时候i=4,j=1,next[4] = 1;
        //接下来拿第一个元素和第四个元素判断是否相等
        //结果相等了,这时候i++ ,j++ ,i=5,j=2,next[5] = 2;
        //结束循环
        if (j==0||T[i-1]==T[j-1]) {
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}
int KMP(char * S,char * T){
    int next[10];
    //得到模式串的next数组，当匹配到模式串的某个位置的时候，应该指向那个位置是由这个数组里面的值决定的
    Next(T,next);
    for(int s=0;s<10;s++){
        printf("next[%d]=%d, ",s,next[s]);
    }
    printf("\n");
    int i=1;
    int j=1;
    while (i<=strlen(S)&&j<=strlen(T)) {
       
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j]; //如果没有匹配成功，那么根据next数组调整模式串的位置从哪儿开始.....
        }
    }
    if (j>strlen(T)) {
        return i-(int)strlen(T);
    }
    return -1;
}
int main() {
    int i=KMP("ababcabcacbab","abcac");
    printf("%d",i);
    return 0;
}
