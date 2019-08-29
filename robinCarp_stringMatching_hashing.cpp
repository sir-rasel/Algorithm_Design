#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll base2=1997293877,mod2=2117566807,base1=1949313259,mod1=2091573227;
int maxx = 1000005;

/////natural hashing
//ll hashing(string s,ll b,ll m){
//    ll ret = 0,power=1;
//    for(int i=0;i<s.size();i++){
//        ret*=power;
//        ret+=str[i];
//        ret%=m;
//        power=(power*b)%m;
//    }
//    return ret;
//}
//
///// double hashing
//pair<ll,ll>doubleHash(string s){
//    return {hasing(s,b1,m1),hashing(s,b2,m2)};
//}
//
//ll doubleHash(string s){
//    ll ret = hashing(str,b1,m1);
//    ret<<=32;
//    ret|=hashing(s,b2,m2);
//    return ret;
//}

///single hashing
//struct Hash{
//    int len;
//    ll base,mod;
//    vector<ll>cumulativeHash,power;
//
//    Hash(){}
//    Hash(string s,ll b,ll m){
//        len = s.size(),mod=m,base=b;
//        cumulativeHash.resize(len+3,0);
//        power.resize(len+3,1);
//
//        for(int i=1;i<=len;i++)
//            power[i]=(power[i-1]*base)%mod;
//        for(int i=1;i<=len;i++){
//            cumulativeHash[i]=(cumulativeHash[i-1]*base)%mod;
//            cumulativeHash[i]=(cumulativeHash[i]+s[i-1])%mod;
//        }
//    }
//    ll rangeHash(int l,int r){
//        ll ret = ((ll)cumulativeHash[l]*(ll)power[r-l+1])%mod;
//        ret = (cumulativeHash[r+1]-ret)%mod;
//
//        if(ret<0) ret+=mod;
//
//        return ret;
//    }
//};
//
//int countMatch(string text,string pattern){
//    int cnt=0;
//    Hash textHash = Hash(text,base1,mod1);
//    Hash patternHash = Hash(pattern,base1,mod1);
//
//    ll matchValue = patternHash.rangeHash(0,pattern.size()-1);
//    int patternSize = pattern.size();
//
//    for(int i=0;i<(text.size()-patternSize+1);i++)
//        if(textHash.rangeHash(i,i+patternSize-1)==matchValue)
//            cnt++;
//
//    return cnt;
//}

///double Hashing
struct Hash{
    int len;
    ll base,mod;
    vector<int>cumulativeHash,power;

    Hash(){}
    Hash(string s,ll b,ll m){
        len = s.size(),mod=m,base=b;
        cumulativeHash.resize(len+3,0);
        power.resize(len+3,1);

        for(int i=1;i<=len;i++)
            power[i]=(power[i-1]*base)%mod;
        for(int i=1;i<=len;i++){
            cumulativeHash[i]=(cumulativeHash[i-1]*base)%mod;
            cumulativeHash[i]=(cumulativeHash[i]+s[i-1])%mod;
        }
    }
    inline int rangeHash(int l,int r){
        int ret = ((ll)cumulativeHash[l]*(ll)power[r-l+1])%mod;
        ret = (cumulativeHash[r+1]-ret)%mod;

        if(ret<0) ret+=mod;

        return ret;
    }
};

struct stringHash{
    Hash sh1, sh2;
    stringHash(){}
    stringHash(string s){
        sh1 = Hash(s, base1, mod1);
        sh2 = Hash(s, base2, mod2);
    }

    inline ll rangeHash(int l, int r){
        return ((ll)sh1.rangeHash(l, r) << 32) ^ sh2.rangeHash(l, r);
    }

};

int countMatch(string text,string pattern){
    int cnt=0;
    stringHash textHash = stringHash(text);
    stringHash patternHash = stringHash(pattern);

    ll matchValue = patternHash.rangeHash(0,pattern.size()-1);
    int patternSize = pattern.size();

    for(int i=0;i<(text.size()-patternSize+1);i++)
        if(textHash.rangeHash(i,i+patternSize-1)==matchValue)
            cnt++;

    return cnt;
}

int main(){
    int test,cs=1;
    scanf("%d",&test);
    while(test--){
        string text,pattern;
        cin>>text>>pattern;
        int ans = countMatch(text,pattern);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
