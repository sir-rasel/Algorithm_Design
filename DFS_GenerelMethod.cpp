#include <bits/stdc++.h>
using namespace std;

const int maxNode = 10000;
int temp=0;

vector<int>edge[maxNode];
bool visit[maxNode];
int Time[maxNode];

void dfs(int source){
    if(visit[source]==true) return;
    visit[source]=true;
    cout<<source<<" ";
    Time[source]=temp++;
    for(int i=0;i<edge[source].size();i++)
        if(!visit[edge[source][i]]) dfs(edge[source][i]);
}

int main(){
    int m;
    printf("Give the number of edge: ");
    scanf("%d",&m);
    printf("Give the edges:\n");
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int s;
    printf("Give the source node: ");
    scanf("%d",&s);
    dfs(s);
    cout<<endl;

    return 0;
}
