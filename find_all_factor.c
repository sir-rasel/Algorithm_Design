#include <stdio.h>
#include <math.h>

void element(int n);

int main(){
    int n;
    printf("Input number n: ");
    scanf("%d",&n);
    element(n);
    return 0;
}

void element(int n){
    int i,j,k;
    k=sqrt(n);
    for(i=1;i<=k;i++){
        if(n%i==0) printf("%d ",i);
    }
    for(i=k-1;i>=1;i--){
        if(n%i==0) printf("%d ",n/i);
    }
}
