#include <stdio.h>

long long int gcd(long long int a,long long int b);
long long int findlcm(long long int a, long long int b);

int main(){
    long long int a,b,n,arr[101],g,l,max=0;
    int i,count=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    l=arr[0];
    for(i=1;i<n;i++){
        l=findlcm(l,arr[i]);
    }
    printf("%lld\n",l);
    return 0;
}

long long int gcd(long long int a,long long int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

long long int findlcm(long long int a, long long int b)
{
    long long int lcm;
    lcm=a/gcd(a,b)*b;
    return lcm;
}
