#include <stdio.h>
#include <math.h>

int nod(int n);

int main(){
    int n,m;
    printf("Input number n: ");
    scanf("%d",&n);
    m=nod(n);
    printf("Number of divisor is: %d",m);
    return 0;
}

int nod(int n){
    int i,j,k,count,nod=1;
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
            nod*=(count+1);
        }
    }
    if(n!=1){
        nod*=2;
    }
    return nod;
}
