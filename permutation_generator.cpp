#include <bits/stdc++.h>
using namespace std;

stack<char>perm;
bool chose[100]={false};
string a = "012";

void gen(){
    if(perm.size()==a.length()){
        stack<char>p(perm);
        while(!p.empty()){
            cout<<p.top();
            p.pop();
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<a.length();i++){
        if(chose[i]) continue;
        chose[i]=true;
        perm.push(a[i]);
        gen();
        chose[i]=false;
        perm.pop();
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
