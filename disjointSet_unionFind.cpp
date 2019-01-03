#include<bits/stdc++.h>
using namespace std;

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

void unionTwoSet(int parent[],int rankOfParent[],int i,int j){
    int u = findRepresentative(parent,i);
    int v = findRepresentative(parent,j);
    if(u==v) printf("Already friends\n");
    else {
        if(rankOfParent[u]<rankOfParent[v])
            parent[u]=v,rankOfParent[v]+=rankOfParent[u];
        else parent[v]=u,rankOfParent[u]+=rankOfParent[v];
    }
}

int main(){
    int n;
    printf("Give the number of element: ");
    scanf("%d",&n);
    int parent[n+5];
    int rankOfParent[n+5];

    makeSet(parent,rankOfParent,n);

    printf("Give the number of union combination: ");
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("Give the combination of a union operation between %d to %d: ",0,n);
        int a,b;
        scanf("%d %d",&a,&b);
        unionTwoSet(parent,rankOfParent,a,b);
    }

    printf("Give the number of find combination: ");
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        printf("Give the combination of a find operation between %d to %d: ",0,n);
        int a,b;
        scanf("%d %d",&a,&b);
        if(findRepresentative(parent,a)==findRepresentative(parent,b)) printf("Friends\n");
        else printf("Not friends\n");
    }
    return 0;
}
