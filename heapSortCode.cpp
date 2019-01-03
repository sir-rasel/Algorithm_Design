#include<bits/stdc++.h>
using namespace std;

int arr[100000000];

void buildMaxHeap(int arr[],int n,int index){
    int largeNumberIndex = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n and arr[left]>arr[largeNumberIndex]) largeNumberIndex = left;
    if(right<n and arr[right]>arr[largeNumberIndex]) largeNumberIndex = right;

    if(largeNumberIndex != index){
        swap(arr[index],arr[largeNumberIndex]);
        buildMaxHeap(arr,n,largeNumberIndex);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--) buildMaxHeap(arr,n,i);

    for(int i=n-1;i>=0;i--) {
        swap(arr[0],arr[i]);
        buildMaxHeap(arr,i,0);
    }
}

void printArray(int arr[],int n){
    printf("Element of array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int n;
    printf("Give the number of element : ");
    scanf("%d",&n);
    printf("Enter number of array : ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printArray(arr,n);
    heapSort(arr,n);
    printArray(arr,n);

    return 0;
}
