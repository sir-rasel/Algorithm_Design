#include <bits/stdc++.h>
using namespace std;

queue<char>myQueue;

void subset(string seq,int pos){
    if(pos==seq.length()){
        queue<char>temp(myQueue);
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
        return;
    }
    subset(seq,pos+1);
    myQueue.push(seq[pos]);
    subset(seq,pos+1);
    myQueue.pop();
}

int main(){
    string seq;
    cin>>seq;
    int pos=0;
    subset(seq,pos);
    return 0;
}
