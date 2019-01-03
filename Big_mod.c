#include <stdio.h>

int bigmod(int a,int b,int m);

int main(){
    int a,b,m,x;
    printf("Input value a,b, and m : ");
    scanf("%d %d %d",&a,&b,&m);
    x=bigmod(a,b,m);
    printf("Result is : %d",x);
    return 0;
}

int bigmod(int a,int b,int m){
    int x;
    if(b==0) return 1%m;
    x=bigmod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1) x=(x*a)%m;
    return x;
}
