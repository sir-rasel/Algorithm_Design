#include <bits/stdc++.h>
using namespace std;

int Euler_phi(int n);

int main(){
    int n,m;
    printf("Input number n: ");
    scanf("%d",&n);
    m=Euler_phi(n);
    printf("Number of co-prime is: %d",m);
    return 0;
}

int Euler_phi(int n){
    int i,j,k;
    double phi=n;
    k=sqrt(n+1);
    int a[k];
    for(i=2;i<=sqrt(n+1);i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            phi*=(1-1.0/i);
        }
    }
    if(n!=1) phi*=(1-1.0/n);
    return int(phi);
}
