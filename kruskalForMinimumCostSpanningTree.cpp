#include<bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const {
        return w < p.w;
    }
};
vector<edge>e;

void makeSet(int parent[],int rankOfParent[],int n){
    for(int i=0;i<n;i++) parent[i]=i,rankOfParent[i]=1;
}

int findRepresentative(int parent[],int i){
    if(parent[i]==i) return i;
    else {
        int representative=findRepresentative(parent,parent[i]);
        parent[i]=representative;
        return representative;
    }
}

bool unionTwoSet(int parent[],int rankOfParent[],int i,int j){
    int u = findRepresentative(parent,i);
    int v = findRepresentative(parent,j);
    if(u!=v){
        if(rankOfParent[u]<rankOfParent[v])
            parent[u]=v,rankOfParent[v]+=rankOfParent[u];
        else parent[v]=u,rankOfParent[u]+=rankOfParent[v];
        return true;
    }
    return false;
}

int kruskalMst(int n){
    sort(e.begin(), e.end());
    int parent[n+5],rankOfParent[n+5];
    makeSet(parent,rankOfParent,n);

    int edgeCount = 0, minimumCost = 0;
    for (int i = 0; i < (int) e.size(); i++) {
        bool flag = unionTwoSet(parent,rankOfParent,e[i].u,e[i].v);
        if(flag){
            edgeCount++;
            minimumCost += e[i].w;
        }
        if (edgeCount == n - 1) break;
    }
    return minimumCost;
}

int main(){
    int n,m;
    printf("Give number of node and edge: ");
    scanf("%d %d",&n,&m);

    printf("Give edge and weight:\n");
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e.push_back({u,v,w});
    }
    printf("Minimum cost of spanning tree : %d\n",kruskalMst(n));
    return 0;
}
