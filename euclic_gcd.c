#include <stdio.h>

int gcd(int a,int b);

int main(){
    int a,b,n;
    printf("Input a and b : ");
    scanf("%d %d",&a,&b);
    n=gcd(a,b);
    printf("GCD is : %d",n);
    return 0;
}

int gcd(int a,int b){
    if(a==0) return b;
    gcd(b%a,a);
}
