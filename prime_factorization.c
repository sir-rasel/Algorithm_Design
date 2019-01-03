#include <stdio.h>
#include <math.h>

void prime_factorized(int n);

int main(){
    int n;
    printf("Input number n: ");
    scanf("%d",&n);
    prime_factorized(n);
    return 0;
}

void prime_factorized(int n){
    int i,j;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            while(n%i==0){
                printf("%d ",i);
                n/=i;
            }
        }
    }
    if(n!=1) printf("%d",n);
}
