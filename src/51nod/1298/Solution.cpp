#include <bits/stdc++.h>
using namespace std;

const double eps=1e-6;
int fcmp(double x){
    if (fabs(x)<=eps) return 0;
    return x<0?-1:1;
}

double PointToSegDist(double px, double py, double xa, double ya, double xb, double yb){
    double AP_AB=(px-xa)*(xb-xa)+(py-ya)*(yb-ya);
    double AB_AB=(xb-xa)*(xb-xa)+(yb-ya)*(yb-ya);
    double AB=sqrt(AB_AB);
    double k=AP_AB/AB_AB;
    double AP_AP=(px-xa)*(px-xa)+(py-ya)*(py-ya);
    double AP=sqrt(AP_AP);
    double BP_BP=(px-xb)*(px-xb)+(py-yb)*(py-yb);
    double BP=sqrt(BP_BP);
    if (fcmp(k)<0){
        return AP;
    }else if (fcmp(k-1)<=0){
        double d=sqrt(AP_AP-(AP_AB/AB)*(AP_AB/AB));
        return d;
    }else{
        return BP;
    }
}

bool in_circle(double cx,double cy,double cr,double x,double y){
    return fcmp((cx-x)*(cx-x)+(cy-y)*(cy-y)-cr*cr)<=0;
}

bool is_intersect(double cx,double cy,double cr,double x1,double y1,double x2,double y2){
    return fcmp(PointToSegDist(cx,cy,x1,y1,x2,y2)-cr)<=0&&(!in_circle(cx,cy,cr,x1,y1)||!in_circle(cx,cy,cr,x2,y2));
}

int main()
{
    int t;
    cin>>t;
    while (t--){
        bool ans=false;
        int cx,cy,cr,x[3],y[3];
        cin>>cx>>cy>>cr;
        for (int i=0;i<3;i++) cin>>x[i]>>y[i];
        for (int i=0;i<2;i++){
            for (int j=i+1;j<3;j++){
                if (is_intersect(cx,cy,cr,x[i],y[i],x[j],y[j])){
                    ans=true;
                    break;
                }
            }
            if (ans) break;
        }
        if (ans) cout<<"Yes"<<endl;else cout<<"No"<<endl;
    }
    return 0;
}
