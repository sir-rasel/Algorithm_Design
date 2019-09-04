#include <stdio.h>
#include<math.h>
#define limit 10000020

typedef long long int ll;

ll pr[limit],phi[limit],mark[limit];
bool pri[limit];
ll k=1;

void sieve(){
    ll sq = sqrt(limit)+1;
    for(ll i=3;i<=sq;i+=2)
        if(!pri[i])
            for(ll j=i*i;j<limit;j+=2*i)
                pri[j]=true;

    pr[k++]=2;
    for(ll i=3;i<limit;i+=2)
        if(!pri[i]) pr[k++]=i;
}

void Euler_Sieve_phi(ll a,ll b){
    if(a==1) phi[0]=1;
    for(ll i=1;i<=k and pr[i]*pr[i]<=b;i++){
        ll j = a/pr[i];
        j*=pr[i];
        if(j<a) j+=pr[i];
        for(;j<=b;j+=pr[i]){
            if(!phi[j-a]){
                phi[j-a]=j;
                mark[j-a]=j;
            }
            while(mark[j-a]%pr[i]==0) mark[j-a]/=pr[i];
            phi[j-a]=(phi[j-a]/pr[i])*(pr[i]-1);
        }
    }
    for(ll i=a; i<=b; i++){
        ll n=phi[i-a];
        if(!n) n=i-1;
        if(mark[i-a]>1) n=(n/mark[i-a])*(mark[i-a]-1);
        printf("%lld\n",n);
    }
}

int main(){
    sieve();
    ll a,b;
    scanf("%lld %lld",&a,&b);
    Euler_Sieve_phi(a,b);
    return 0;
}
