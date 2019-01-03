#include <stdio.h>
int main(){
    int arr[100],n,i,mid=0,low,hi,item,flag=0;
    printf("Input the number of element of array : ");
    scanf("%d",&n);
    printf("Input the element of array : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Input the number to be found : ");
    scanf("%d",&item);
    low=0;
    hi=n-1;
    while(low<hi && mid<n-1){
        mid= low + ( (hi-low)/(arr[hi]-arr[low]) ) * (item-arr[low]);
        if(arr[mid]==item){
            flag++;
            break;
        }
        else if(arr[mid]<item){
            low=mid+1;
        }
        else {
            hi=mid-1;
        }
    }
    if(flag==0) printf("Item not found");
    else printf("Item found");
    return 0;
}
