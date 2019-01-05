#include <bits/stdc++.h>
using namespace std;

void permutation(int arr[],int index,int n){
    if(index==n-1){
        for(int i=0;i<n;i++) printf("%d ",arr[i]);
        cout<<endl;
    }
    else{
        for(int i=index;i<n;i++){
            swap(arr[i],arr[index]);
            permutation(arr,index+1,n);
            swap(arr[i],arr[index]);
        }
    }
}

int main(){
    int n;
    printf("Give the number of element: ");
    scanf("%d",&n);

    int arr[n+5];
    printf("Give the element:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Permutation is : \n");
    permutation(arr,0,n);
    cout<<endl;

    do{
        for(int i=0;i<n;i++) printf("%d ",arr[i]);
        cout<<endl;
    }while(next_permutation(arr,arr+n));
    return 0;
}
