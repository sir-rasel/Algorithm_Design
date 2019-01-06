#include <bits/stdc++.h>
#define INF 100000
using namespace std;

/*
int dijakstra(vector<pair<int,int> >edge[],int source,int destination,int n){
	vector<int>cost(n+1,INF);
	cost[source]=0;
	queue<pair<int,int> >Q;
	vector<bool>visit(n+1,false);
	Q.push({source,0});

	while(!Q.empty()){
		int temp1 = Q.front().first;
		int weight = Q.front().second;
		visit[temp1]=true;
		Q.pop();

		for(auto it:edge[temp1]){
			int temp = it.first;
			int weight = it.second;

			cost[temp]=min(cost[temp],cost[temp1]+weight);

			if(!visit[temp]) Q.push({temp,weight});
		}
	}
	return cost[destination];
} */

int dijakstra(vector<pair<int,int> >edge[],int source,int destination,int n){
	vector<int>cost(n+1,INF);
	cost[source]=0;
	priority_queue<pair<int,int> >Q;
	Q.push({0,source});

	while(!Q.empty()){
		int weight = Q.top().first;
		int node = Q.top().second;
		Q.pop();

		for(auto it:edge[node]){
			int temp = it.first;
			int weight = it.second;

			if(cost[temp]>cost[node]+weight){
                cost[temp]=cost[node]+weight;
                Q.push({-cost[temp],temp});
			}
		}
	}
	return cost[destination];
}

int main(){
    int n,m;
	printf("Give the number of node and edge: ");
	scanf("%d %d",&n,&m);
	vector<pair<int,int> >edge[n+5];

	printf("Give the edges and cost: ");
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}

	int source,destination;
	printf("Give the source node and destination node: ");
	scanf("%d %d",&source,&destination);

	printf("Shortest distance from %d to %d is %d\n",source,destination,dijakstra(edge,source,destination,n));

	return 0;
}
