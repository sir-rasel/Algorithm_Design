#include<bits/stdc++.h>
using namespace std;

int primsMst(vector<pair<int,int> > edge[],int n){
    int cost=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector <bool> mst(n,false);
    pq.push({0,0});

    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(mst[u]==false) cost+=w;
        mst[u]=true;

        for(auto node:edge[u]){
            int v = node.first;
            int w = node.second;

            if(mst[v]==false) pq.push({w,v});
        }
    }
    return cost;
}

int main(){
    int n,m;
    printf("Give the number of node and edge: ");
    scanf("%d %d",&n,&m);
    vector<pair<int,int> > edge[n+5];

    printf("Give the edges and weight:\n");
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }

    printf("The cost of minimum spanning tree: %d\n",primsMst(edge,n));
    return 0;
}
