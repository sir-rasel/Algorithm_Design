#include <bits/stdc++.h>
#define Max 1000006
using namespace std;

int phi[Max];
bool mark[Max];
void Euler_Sieve_phi(int n){
    for(int i=1;i<=n;i++) phi[i]=i;
    mark[1]=true;

    for(int i=2;i<=n;i++){
        if(!mark[i]){
            for(int j=i;j<=n;j+=i){
                mark[j]=true;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

int main(){
    int n,m;
    printf("Input number n: ");
    scanf("%d",&n);
    Euler_Sieve_phi(n);
    printf("Number of co-prime is: %d\n",phi[n]);
    return 0;
}

