#include<bits/stdc++.h>
#define MAX 1000
#define pii pair<int,int>
using namespace std;

int fx[]={1,-1,0,0}; //ডিরেকশন অ্যারে
int fy[]={0,0,1,-1};
int cell[MAX][MAX]; //cell[x][y] যদি -১ হয় তাহলে সেলটা ব্লক
int d[MAX][MAX],vis[MAX][MAX]; //d means destination from source.
int row,col;

void bfs(int sx,int sy){ //Source node is in [sx][sy] cell.
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty()){
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++){
			int tx=top.first+fx[k];
			int ty=top.second+fy[k]; //Neighbor cell [tx][ty]
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0){ //validation check
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty)); //Pushing a new pair in the queue
			}
		}
	}
}

int main(){
    printf("Give the row and col: ");
    scanf("%d %d",&row,&col);
    printf("Give the grid:\n");
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            scanf("%d",&cell[i][j]);

    bfs(0,0);
    printf("Minimum label of %d to %d is: %d\n",row-1,col-1,d[row-1][col-1]);
    return 0;
}
