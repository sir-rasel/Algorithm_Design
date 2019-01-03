#include <stdio.h>
void merge_sort(int a[],int n);
void merge(int a[],int b[],int c[],int n,int m,int sum);
int main(){
    int arr[100],i,n;
    printf("Input the size of Array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,n);
    printf("Array after sorting : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void merge_sort(int a[],int n){
    if(n<2) return;
    int mid,i;
    mid=n/2;
    int left[mid],right[n-mid];
    for(i=0;i<mid;i++){
        left[i]=a[i];
    }
    for(i;i<n;i++){
        right[i-mid]=a[i];
    }
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    merge(left,right,a,mid,n-mid,n);
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

