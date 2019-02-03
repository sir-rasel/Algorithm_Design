#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_W 1000
using namespace std;

typedef long long int ll;

int n,CAP;
int weight[MAX_N+1],cost[MAX_N+1];

ll dp[MAX_N+1][MAX_W+1];

/// top down approach
//ll knapsack(int i,int w){
//    if(i==n) return 0;
//    if(dp[i][w]!=-1) return dp[i][w];
//    ll profit1=0,profit2=0;
//    if(w+weight[i]<=CAP)
//        profit1=cost[i]+knapsack(i+1,w+weight[i]);
//
//    profit2=knapsack(i+1,w);
//    dp[i][w]=max(profit1,profit2);
//    return dp[i][w];
//}

/// bottom up approach
ll knapsack(int i,int w){
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=CAP;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int w=1;w<=CAP;w++){
            if(weight[i-1]<=w){
                dp[i][w] = max(cost[i-1]+dp[i-1][w-weight[i-1]],dp[i-1][w]);
            }
            else dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][CAP];
}

int main(){
    freopen("input.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&CAP);
    for(int i=0; i<n; i++) scanf("%d %d",&weight[i],&cost[i]);
    printf("%lld\n",knapsack(n,CAP));
    return 0;
}
