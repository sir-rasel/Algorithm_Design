#include <stdio.h>
#define inf 1000

void shortest(int n,int arr[][n]);
void takeinput(int n,int arr[][n]);
void printpath(int n,int arr[][n]);
int min(int a,int b);

int main(){
    int n,i,j;
    printf("Give Number of nodes: ");
    scanf("%d",&n);
    int arr[n][n];
    printf("Give the weight of edges: ");
    takeinput(n,arr);
    printf("All shortest path from each other is : \n");
    shortest(n,arr);
    printpath(n,arr);
    return 0;
}

void shortest(int n,int arr[][n]){
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                arr[i][j]=min(arr[i][j],(arr[i][k]+arr[k][j]));
            }
}

void takeinput(int n,int arr[][n]){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0) arr[i][j]=inf;
        }
}

void printpath(int n,int arr[][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int min(int a,int b){
    if(a<b) return a;
    else return b;
}
