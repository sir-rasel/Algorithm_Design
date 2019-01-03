#include <stdio.h>

void merge(int a[],int b[],int c[],int n,int m,int sum);

int main(){
    int a[10],b[10],c[20],i,j,k,n,m,sum;
    printf("Please input the size of A : ");
    scanf("%d",&n);
    printf("Please input the element of A : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Please input the size of B : ");
    scanf("%d",&m);
    sum=n+m;
    printf("Please input the element of B : ");
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    merge(a,b,c,n,m,sum);
    printf("Array C is : ");
    for(i=0;i<sum;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
void merge(int a[],int b[],int c[],int n,int m,int sum){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
        }
        else {
            c[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        j++;
        k++;
    }
}
