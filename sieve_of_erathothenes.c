#include <stdio.h>
#include <math.h>
#define MAX 100000000

void sieve();
char arr[MAX];

int main(){
    int n;
    printf("Input the number: ");
    scanf("%d",&n);
    sieve();
    if(arr[n]=='0') printf("not prime");
    else printf("prime");
    return 0;

}

void sieve(){
    int i,j,k;
    arr[0]='0';
    arr[1]='0';
    for(i=2;i<=MAX;i++) arr[i]='1';
    k=sqrt(MAX);
    for(i=2;i<=k;i++){
        if(arr[i]=='1'){
            for(j=i;i*j<=MAX;j++){
                arr[i*j]='0';
            }
        }
    }
}
