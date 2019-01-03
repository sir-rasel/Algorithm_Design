#include <bits/stdc++.h>
using namespace std;

void MinMax(int &minimum,int &maximum,int start,int finish,int arr[]){
    if(start == finish) minimum = maximum = arr[start];
    else if(start+1 == finish) {
        if(arr[start]>arr[finish]) minimum = arr[finish],maximum = arr[start];
        else minimum = arr[start],maximum = arr[finish];
    }
    else{
        int mid = finish/2;
        int min1,max1,min2,max2;
        MinMax(min1,max1,start,mid,arr);
        MinMax(min2,max2,mid+1,finish,arr);

        if(min1 < min2) minimum = min1;
        else minimum = min2;

        if(max1 > max2) maximum = max1;
        else maximum = max2;
    }
}

int main(){
    int n;
    printf("Give the number of element: ");
    scanf("%d",&n);
    int arr[n+5];

    printf("Give the element of array: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int minimumValue,maximumValue;
    MinMax(minimumValue,maximumValue,0,n-1,arr);
    printf("Min = %d, Max = %d\n",minimumValue,maximumValue);
    return 0;
}
