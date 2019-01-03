#include <bits/stdc++.h>
using namespace std;

const int maxNode = 10000;

vector< pair<int,int> >edges[maxNode];
int Distance[maxNode];

int bfs (int start,int finish){
    deque <int > Q;
    Q.push_back(start);
    memset(Distance,2,sizeof(Distance));
    Distance[start] = 0;
    while(!Q.empty ()){
        int v = Q.front();
        Q.pop_front();
        for(int i = 0 ; i < edges[v].size(); i++){
            if(Distance[edges[v][i].first] > Distance[v]+edges[v][i].second) {
                Distance[edges[v][i].first] = Distance[v]+edges[v][i].second;
                if(edges[v][i].second==0) Q.push_front(edges[v][i].first);
                else Q.push_back(edges[v][i].first);
            }
        }
        if(v==finish) return Distance[finish];
    }
    return INT_MAX;
}

int main(){
    int m;
    printf("Give the number of edge: ");
    scanf("%d",&m);
    printf("Give the edges:\n");
    for(int i=0;i<m;i++){
        int u,v,cost;
        scanf("%d %d %d",&u,&v,&cost);
        edges[u].push_back({v,cost});
        edges[v].push_back({u,cost});
    }

    int s,d;
    printf("Give the source and destination node for shortest path: ");
    scanf("%d %d",&s,&d);
    int shortestPath = bfs(s,d);
    printf("Shortest path from %d to %d : %d\n",s,d,shortestPath);

    return 0;
}
