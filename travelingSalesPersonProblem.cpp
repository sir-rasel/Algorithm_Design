#include<bits/stdc++.h>
#define node 10
#define maxCost 999999
using namespace std;

int dp[1<<node][node],n,startingNode;
int graph[node][node];
int visitedAll;

void takeInput(){
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	printf("\nEnter the Cost Matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    visitedAll = (1<<n)-1; /// make mask state
    memset(dp,-1,sizeof(dp)); /// initially make dp to -1
}

int tsp(int mask,int pos){
    if(mask==visitedAll) return graph[pos][startingNode];
    if(dp[mask][pos]!=-1) return dp[mask][pos];
    int optimalCost = maxCost;
    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newCost = graph[pos][city]+tsp(mask|(1<<city),city);
            optimalCost = min(optimalCost,newCost);
        }
    }
    return dp[mask][pos]=optimalCost;
}

int main(){
	takeInput();
	printf("Give the starting node of sales person: ");
	scanf("%d",&startingNode);
	int cost = tsp(0|(1<<startingNode),startingNode);
	printf("Minimum Traveling cost by salesperson : %d\n",cost);
	return 0;
}
