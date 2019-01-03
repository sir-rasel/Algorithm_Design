#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[],int start,int end);
int randomize_partition(int a[],int start,int end);
void quick_sort(int a[],int start,int end);
void swap(int *a, int *b);

int main(){
    int arr[100],n,i;
    printf("Input the number of element : ");
    scanf("%d",&n);
    int start=0;
    int end=n-1;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,start,end);
    printf("Array after sorting : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void swap(int *a, int *b){ /// swaping function
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int start,int end){ /// pertition function
    int pi,pivot,i,temp;
    pi=start;
    pivot=a[end];
    for(i=start;i<end;i++){
        if(a[i]<=pivot){
            swap(&a[i],&a[pi]);
            pi++;
        }
    }
    swap(&a[end],&a[pi]);
    return pi;
}

int randomize_partition(int a[],int start,int end){ /// randomized partition function
    int pi,temp;
    time_t t;
    srand((unsigned) time(&t));
    pi=start+(rand()%(end-start+1));
    swap(&a[end],&a[pi]);
    partition(a,start,end);
}

void quick_sort(int a[],int start,int end){ /// quick sort function
    int pi;
    if(start<end){
        pi=randomize_partition(a,start,end);
        quick_sort(a,start,pi-1);
        quick_sort(a,pi+1,end);
    }
    return;
}
