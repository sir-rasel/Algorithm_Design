#include <bits/stdc++.h>
#define limit 46350
using namespace std;

vector<int> sieve(){
    bool prime[limit];
    memset(prime,true,sizeof(prime));
    int sq = floor(sqrt(limit))+1;
    for(int i=3;i<sq;i+=2){
        if(prime[i]){
            for(int j=i*i;j<limit;j+=2*i){
                prime[j]=false;
            }
        }
    }
    vector<int>temp;
    temp.push_back(2);
    for(int i=3;i<limit;i+=2){
        if(prime[i]) temp.push_back(i);
    }
    return temp;
}

void segmentSieve(long long int low,long long int high,vector<int>prime){
    bool mark[high-low+1];
    memset(mark,true,sizeof(mark));
    int sq = sqrt(high)+1;
    for(int i=0;prime[i]<=sq;i++){
        int currentPrime = prime[i];
        long long int baseValue = (low/currentPrime)*currentPrime;
        if(baseValue<low) baseValue+=currentPrime;
        for(long long int j=baseValue;j<=high;j+=currentPrime){
            mark[j-low] = false;
        }
        if(baseValue == currentPrime) mark[baseValue-low]=true;
    }
    for(int i=0;i<high-low+1;i++){
        if(mark[i]) printf("%d\n",i+low);
    }
}

int main(){
    vector<int>prime=sieve();
    int test;
    scanf("%d",&test);
    while(test--){
        long long int low,high;
        scanf("%lld %lld",&low,&high);
        segmentSieve(low,high,prime);
    }
    return 0;
}
