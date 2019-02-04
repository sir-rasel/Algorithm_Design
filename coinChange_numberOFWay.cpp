#include <bits/stdc++.h>
#define MAX_N 5
#define MAX_W 8000
using namespace std;

int coin[MAX_N+1]={50,25,10,5,1}; //value of coins available
int make; //we will try to make 18
int dp[MAX_N][MAX_W];
int call(int i,int amount){
    if(i>=5) { //All coins have been taken
        if(amount==0) return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount]; //no need to calculate same state twice
    int ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1=call(i,amount-coin[i]); //try to take coin i
    ret2=call(i+1,amount); //dont take coin i
    return dp[i][amount]=ret1+ret2; //storing and returning.
}

int main(){
    memset(dp,-1,sizeof(dp));
    while(cin>>make){
        cout<<call(0,make)<<endl;
    }
    return 0;
}
