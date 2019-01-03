#include <bits/stdc++.h>
using namespace std;

int egcd(int a,int b,int &x,int &y,int i){
    if(a==0) {
        x=0,y=1;
        return b;
    }
    int x1,y1;
    int d = egcd(b%a,a,x1,y1,i+1);

    x = y1 - (b/a)*x1;
    y = x1;

    return d;
}

int main(){
    int x,y;
    int g = egcd(10,6,x,y,1);
    printf("Res - GCD:%d, X=%d, Y=%d\n",g,x,y);
    return 0;
}
