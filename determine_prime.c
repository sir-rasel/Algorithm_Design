#include <stdio.h>
#include <math.h>

int prime(long long int n);

int main(){
    long long int n;
    int a;
    printf("Please input n : ");
    scanf("%lld",&n);
    a=prime(n);
    if(a==1) printf("This is prime.");
    else printf("This is not prime.");
    return 0;
}

int prime(long long int n){
    int a=sqrt(n),i;
    if(n<2) return 0;
    if(n%2==0) return 0;
    for (i=3;i<=a;i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}
