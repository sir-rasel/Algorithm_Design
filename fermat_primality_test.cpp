#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll bigmod(ll a,ll b,ll m){
    if(b==0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x*x)%m;
    if(b%2==1) x = (x*a)%m;
    return x;
}

bool fermatsIsPrime(ll p,int iter){
    if(p==1) return false;
    for(int i=0;i<iter;i++){
        time_t t;
        srand((unsigned) time(&t));
        ll res = rand()%(p-1)+1;
        if(bigmod(res,p-1,p)!=1) return false;
    }
    return true;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--){
        ll num;
        scanf("%lld",&num);
        if(fermatsIsPrime(num,1000)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
