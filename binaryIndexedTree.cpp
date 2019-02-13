#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAXN = 1e6 + 5;
const int MAXV = 5e5;
const ll MOD = 1e9 + 7;

ll BIT[MAXN], a[MAXN], n,q;
ll phi[MAXV + 5], p[MAXV + 5];

ll inline mod(ll x) {
	return (x%MOD + MOD)%MOD;
}

void compute_phi() {
    for(int i = 1; i <= MAXV; i++) phi[i] = i;
    for(int i = 2; i <= MAXV; i++)
        if (phi[i] == i) {
            for(int j = i; j <= MAXV; j += i) {
                phi[j] -= phi[j] / i;
                phi[j] = mod(phi[j]);
            }
        }
}

void compute_pillai() {
    for(int i = 1; i <= MAXV; i++)
        for(int j = i; j <= MAXV; j += i) {
            p[j] += i * phi[j / i];
            p[j] = mod(p[j]);
        }
}

void update(int x, ll val){
    for(; x <= n; x += x&-x){
        BIT[x] += val;
        BIT[x] = mod(BIT[x]);
    }
}

ll query(int x){
    ll sum = 0;
    for(; x > 0; x -= x&-x){
        sum += BIT[x];
        sum=mod(sum);
    }
     return sum;
}

int main(){
    compute_phi();
    compute_pillai();
    memset(BIT, 0, sizeof(BIT));

    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        update(i,p[a[i]]);
    }

    scanf("%lld",&q);
    while(q--){
        getchar();
        char c;
        int u,v;
        scanf("%c %d %d",&c,&u,&v);
        if(c=='C'){
            ll ans = mod(query(v)-query(u)+p[a[u]]);
            printf("%lld\n",ans);
        }
        else if(c=='U'){
            update(u,mod(p[v]-p[a[u]]));
            a[u]=v;
        }
    }
    return 0;
}
