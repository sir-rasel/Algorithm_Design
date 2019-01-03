#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll modpower(ll a, ll b, ll mod){
    ll x = 0,y = a % mod;
    while (b > 0) {
        if (b % 2 == 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

ll bigmod(ll base, ll exponent, ll mod){
    ll x = 1;
    ll y = base%mod;
    while (exponent > 0){
        if (exponent % 2 == 1)
            x = modpower(x,y,mod);
        y = modpower(y,y,mod);
        exponent = exponent / 2;
    }
    return x % mod;
}

bool millarRobinIsPrime(ll p,int iteration){
    if (p < 2) return false;
    if (p != 2 && p % 2==0) return false;
    ll s = p - 1;
    while (s % 2 == 0) s /= 2;
    for (int i = 0; i <= iteration; i++) {
        time_t t;
        srand((unsigned) time(&t));
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = bigmod(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = modpower(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0) return false;
    }
    return true;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--){
        ll num;
        scanf("%lld",&num);
        if(millarRobinIsPrime(num,50)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
