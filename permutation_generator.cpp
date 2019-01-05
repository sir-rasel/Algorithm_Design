#include <bits/stdc++.h>
using namespace std;

vector<char>perm;
bool chose[100]={false};
string a = "012";

void gen(){
    if(perm.size()==a.length()){
        vector<char>p(perm);
        for(int i=0;i<a.length();i++) cout<<perm[i];
        cout<<endl;
        return;
    }
    for(int i=0;i<a.length();i++){
        if(chose[i]) continue;
        chose[i]=true;
        perm.push_back(a[i]);
        gen();
        chose[i]=false;
        perm.pop_back();
    }
}

int main(){
    gen();
    cout<<endl;
    do{
        cout<<a<<endl;
    }while(next_permutation(a.begin(),a.end()));
    return 0;
}
