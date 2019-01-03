#include <stdio.h>
#include <math.h>

int sod(int n);

int main(){
    int n,m;
    printf("Input number n: ");
    scanf("%d",&n);
    m=sod(n);
    printf("Sum of divisor is: %d",m);
    return 0;
}

int sod(int n){
    int i,j,k,count,sod=1;
    k=sqrt(n+1);
    int a[k];
    for(i=0;i<k;i++) a[i]=0;
    for(i=2;i<=sqrt(n+1);i++){
        if(n%i==0){
            count=0;
            while(n%i==0){
                count++;
                n/=i;
            }
            sod*=ceil((pow(i,count+1)-1))/(i-1);
        }
    }
    if(n!=1){
        sod*=ceil((pow(n,2)-1))/(n-1);
    }
    return sod;
}
