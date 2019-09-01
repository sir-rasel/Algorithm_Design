/// General method
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

matrix mul(matrix A, matrix B){
    matrix C(K+1, vector<ll>(K+1));
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++)
            for (int k = 1; k <= K; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, ll p){
    if (p == 1) return A;
    if (p % 2) return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

ll fib(ll N){
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    if (N == 1) return 1;
    T = pow(T, N-1);

    ll res = 0;
    for (int i = 1; i <= K; i++)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int main(){
    ll n;
    while(cin>>n) printf("%lld\n",fib(n+1));
    return 0;
}

/// Only for fibonacci number
//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long int ll;
//const ll mod = 1000000007;
//
//map<ll, ll> F;
//
//ll fib(ll n) {
//	if (F.count(n)) return F[n];
//	ll k=n/2;
//	if (n%2==0)
//		return F[n] = (fib(k)*fib(k) + fib(k-1)*fib(k-1)) % mod;
//	else
//		return F[n] = (fib(k)*fib(k+1) + fib(k-1)*fib(k)) % mod;
//}
//
//int main(){
//	ll n;
//	F[0]=F[1]=1;
//	while(cin>>n) printf("%lld\n",fib(n));
//    return 0;
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long int ll;
//const ll mod = 1000000007;
//unordered_map<ll,ll> Fib;
//
//ll fib(ll n){
//    if(n<2) return 1;
//    if(Fib.find(n) != Fib.end()) return Fib[n];
//    Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % mod;
//    return Fib[n];
//}
//
//int main(){
//    ll n;
//    while(cin>>n) printf("%lld\n",fib(n));
//    return 0;
//}
