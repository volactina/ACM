#include <bits/stdc++.h>

using namespace std;

const double eps=1e-6;
int fcmp(double x){
    if (fabs(x)<eps) return 0;
    return x<0?-1:1;
}

double matrix(double x11,double x12,double x13,double x21,double x22,double x23,double x31,double x32,double x33){
    return x11*x22*x33+x21*x32*x13+x31*x12*x23-x31*x22*x13-x11*x32*x23-x21*x12*x33;
}

int main()
{
    int t;
    cin>>t;
    while (t--){
        double x[4],y[4],z[4];
        for (int i=0;i<4;i++) cin>>x[i]>>y[i]>>z[i];
        double s=-matrix(x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3])
                 +matrix(x[0],y[0],z[0],x[2],y[2],z[2],x[3],y[3],z[3])
                 -matrix(x[0],y[0],z[0],x[1],y[1],z[1],x[3],y[3],z[3])
                 +matrix(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2]);
        if (fcmp(s)==0) cout<<"Yes"<<endl;else cout<<"No"<<endl;
    }
    return 0;
}
