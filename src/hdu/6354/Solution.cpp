#include <bits/stdc++.h>
#define MAXT 1005
#define MAXN 110
#define debug false
const double pi=acos(-1);
const double eps=1e-8;
using namespace std;
struct inputnode{
    int m;
    double R;
    double x[MAXN],y[MAXN],r[MAXN];
};
struct outputnode{
    double myans,ans;
};
struct debugnode{
    inputnode i;
    outputnode o;
}DEBUG[MAXT];
void show_debugnode(debugnode x){
    cout<<x.i.m<<" "<<x.i.R<<endl;
    for(int i=0;i<x.i.m;i++){
        cout<<x.i.x[i]<<" "<<x.i.y[i]<<" "<<x.i.r[i]<<endl;
    }
    cout<<"myans="<<x.o.myans<<endl;
    cout<<"ans="<<x.o.ans<<endl;
    return;
}
int fcmp(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
int main()
{
    if(debug) freopen("D:\\ACM\\2018MultiTraining\\hdu-5\\data\\1005.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int casenum=0;casenum<t;casenum++){
        int m;
        double R,ans=0;
        cin>>m>>R;
        if(debug) DEBUG[casenum].i.m=m,DEBUG[casenum].i.R=R;
        ans=2*pi*R;
        for(int debugm=0;debugm<m;debugm++){
            double x,y,r;
            cin>>x>>y>>r;
            if(debug) DEBUG[casenum].i.x[debugm]=x,DEBUG[casenum].i.y[debugm]=y,DEBUG[casenum].i.r[debugm]=r;
            double dd=x*x+y*y;
            if((fcmp(sqrt(dd)-(R+r))>=0)||(fcmp(sqrt(dd)-(R-r))<0)) continue;
            if(fcmp(R-r)==0) continue;
            if(R>r){
                double D=2.0*sqrt(r*r-((R*R-r*r-dd)*(R*R-r*r-dd)/(4.0*dd)));
                double angleR=2.0*asin(D/(2.0*R));
                ans-=angleR*R;
                double angler=2.0*asin(D/(2.0*r));
                if(dd+r*r<R*R) ans+=(2*pi-angler)*r;else ans+=angler*r;
            }else{
                double D=2.0*sqrt(R*R-((r*r-R*R-dd)*(r*r-R*R-dd)/(4.0*dd)));
                double angler=2.0*asin(D/(2.0*r));
                ans+=angler*r;
                double angleR=2.0*asin(D/(2.0*R));
                if(dd+R*R<r*r) ans-=(2*pi-angleR)*R;else ans-=angleR*R;
            }
        }
        if(!debug) printf("%.8lf\n",ans);
        if(debug) DEBUG[casenum].o.myans=ans;
    }
    if(debug) fclose(stdin);
    if(debug){
        freopen("D:\\ACM\\2018MultiTraining\\hdu-5\\data\\1005.out","r",stdin);
        int t=0;
        while(~scanf("%lf",&DEBUG[t].o.ans)){
            if(fcmp(DEBUG[t].o.ans-DEBUG[t].o.myans)!=0){
                show_debugnode(DEBUG[t]);
                return 0;
            }
            t++;
        }
        cout<<"correct"<<endl;
    }
    if(debug) fclose(stdin);
    return 0;
}
