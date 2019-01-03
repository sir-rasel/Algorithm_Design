#include <bits/stdc++.h>
using namespace std;

const int maxNode = 10000;

vector<int>edge[maxNode];
bool visit[maxNode];
int level[maxNode];

int bfs(int source,int destination){
    memset(visit,false,sizeof(visit));
    queue<int>Q;
    Q.push(source);
    visit[source]=true;
    level[source]=0;
    while(!Q.empty()){
        int presentNode=Q.front();
        if(presentNode==destination) return level[destination];
        Q.pop();
        for(int i=0;i<edge[presentNode].size();i++){
            if(!visit[edge[presentNode][i]]){
                Q.push(edge[presentNode][i]);
                visit[edge[presentNode][i]]=true;
                level[edge[presentNode][i]]=level[presentNode]+1;
            }
        }
    }
    return INT_MAX;
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

    int s,d;
    printf("Give the source and destination node for shortest path: ");
    scanf("%d %d",&s,&d);
    int shortestPath = bfs(s,d);
    printf("Shortest path from %d to %d : %d\n",s,d,shortestPath);

    return 0;
}
