#include <stdio.h>

int binarySearch(int arr[],int n,int item){
    int low=0;
    int hi=n-1;
    while(low<=hi){
        int mid=low+(hi-low)/2;
        if(arr[mid]==item) return mid;
        else if(arr[mid]<item) low=mid+1;
        else hi=mid-1;
    }
    return -1;
}

/// Recursive Binary search start

//int binarySearch(int arr[],int low,int hi,int item){
//    if(low>hi) return -1;
//    int mid=low+(hi-low)/2;
//    if(arr[mid]==item) return mid;
//    else if(arr[mid]<item) return binarySearch(arr,mid+1,hi,item);
//    else return binarySearch(arr,low,mid-1,item);
//}

/// Recursive Binary search end

int main(){
    int n;
    printf("Input the number of element of array : ");
    scanf("%d",&n);
    int arr[n+5];

    printf("Input the element of array : ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    int item;
    printf("Input the number to be found : ");
    scanf("%d",&item);

    int flag = binarySearch(arr,n,item);
    if(flag==1) printf("Not found\n");
    else printf("Found at position %d\n",flag+1);

    return 0;
}
