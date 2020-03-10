#include<bits/stdc++.h>
using namespace std;

int rotationNumberCalculate(int arr[],int n){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        if(arr[low]<=arr[high]) return low;
        else if(arr[mid]<=arr[prev] and arr[mid]<=arr[next])
            return mid;
        else if(arr[mid]<=arr[high]) high = mid-1;
        else if(arr[mid]>=arr[low]) low = mid+1;
    }
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+5];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int rotationNumber = rotationNumberCalculate(arr,n);
    printf("Number of rotation : %d\n",rotationNumber);

    return 0;
}
