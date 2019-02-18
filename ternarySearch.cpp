#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1, double z1, double x2, double y2, double z2){
    double value;
    value = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
    value = sqrt(value);
    return value;
}

double in_point(double x1, double y1, double z1, double x2, double y2, double z2,double m, double &x, double &y, double &z)
{
    x = m * x2 + (1-m)*x1;
    y = m * y2 + (1-m)*y1;
    z = m * z2 + (1-m)*z1;
}

double ternery_search(double x1, double y1,double z1,double x2,double y2,double z2,double x3,double y3,double z3)
{
    double low = 0;
    double high = 1;
    double mid;
    int counter = 300;
    double ans = 1000000000;
    while(counter--){
        counter++;
        double diff = (high - low);
        double mid1 = low+ diff/3;
        double mid2 = low+ (2*diff)/3;
        double px,py,pz;
        in_point(x1,y1,z1,x2,y2,z2,mid1,px,py,pz);
        double qx,qy,qz;
        in_point(x1,y1,z1,x2,y2,z2,mid2,qx,qy,qz);
        double dis1 = distance(px,py,pz,x3,y3,z3);
        double dis2 = distance(qx,qy,qz,x3,y3,z3);
        ans = min(ans,dis1);
        ans = min(ans,dis2);
        if(dis1<dis2) high = mid2;
        else low = mid1;
    }
    return ans;
}

int main(){
    int T,t;
    scanf("%d",&T);
    for(t = 1; t <= T; t++){
        double x1,y1,z1,x2,y2,z2,x3,y3,z3;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3);
        double value = ternery_search(x1,y1,z1,x2,y2,z2,x3,y3,z3);
        printf("Case %d: %0.10lf\n",t,value);
    }
    return 0;
}
