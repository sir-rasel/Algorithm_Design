/// Floyd Cycle finding algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    int z,i,m,l,cs=1;
    while(scanf("%d %d %d %d",&z,&i,&m,&l)==4 and (z!=0 and i!=0 and m!=0 and l!=0)){
        int seed=l,h=l,t=l;
        while(true){
            t = ((t*z)+i)%m;
            h = ((h*z)+i)%m;
            h = ((h*z)+i)%m;
            if(t==h) break;
        }

        ///Find the length of cycle l
        int l=0;
        while(true){
            t = ((t*z)+i)%m;
            l++;
            if(t==h) break;
        }

        ///Find the first node of cycle m
        int m=0;
        while(true){
            t = ((t*z)+i)%m;
            seed = ((seed*z)+i)%m;
            m++;
            if(t==seed) break;
        }

        printf("Case %d: %d %d\n",cs++,m,l);
    }
    return 0;
}
