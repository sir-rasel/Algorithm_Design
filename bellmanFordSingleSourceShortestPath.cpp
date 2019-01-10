#include<bits/stdc++.h>
#define INF 100000
using namespace std;

struct edge{
    int u,v,w;
};

int n,e;
int source,destination;

int bellmanFord(edge edges[]){
    int distance[n+5];
    for(int i=0;i<n;i++) distance[i]=INF;
    distance [source] = 0;

    for(int i=0;i<n-1;i++)
        for(int m=0;m<e;m++)
            distance[edges[m].v]=min(distance[edges[m].v],distance[edges[m].u]+edges[m].w);

    return distance[destination];
}

int main(){
    printf("Give the number of node and edges: ");
    scanf("%d %d",&n,&e);
    edge edges[e+5];

    printf("Give the edges and weight:\n");
    for(int i=0;i<e;i++)
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);

    printf("Give the source and destination node: ");
    scanf("%d %d",&source,&destination);

    printf("Shortest distance from %d to %d is %d\n",source,destination,bellmanFord(edges));
    return 0;
}
