#include <bits/stdc++.h>
using namespace std;

vector<char>myQueue;

void subset(string seq,int pos){
    if(pos==seq.length()){
        vector<char>temp(myQueue);
        while(!temp.empty()){
            cout<<temp.back()<<" ";
            temp.pop_back();
        }
        cout<<endl;
        return;
    }
    subset(seq,pos+1);
    myQueue.push_back(seq[pos]);
    subset(seq,pos+1);
    myQueue.pop_back();
}

int main(){
    string seq;
    cin>>seq;
    int pos=0;
    subset(seq,pos);
    return 0;
}
