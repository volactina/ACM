//自动生成全排列
//#include <math.h>
#include <stdio.h>
#include <algorithm>
#define DEBUG false
using namespace std;
double x[5],y[5];
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double totlen(int p[]){
        //按照p数组的顺序访问下来的路程和
        if(DEBUG) printf("totlen:\n");
        double ans=dist(0,0,x[p[0]],y[p[0]]);
        if(DEBUG) printf("flying to (%lf,%lf),now ans=%lf\n",x[p[0]],y[p[0]],ans);
        for(int i=1;i<5;i++){
            ans+=dist(x[p[i-1]],y[p[i-1]],x[p[i]],y[p[i]]);
            if(DEBUG) printf("flying to (%lf,%lf),now ans=%lf\n",x[p[i]],y[p[i]],ans);
        }
        ans+=dist(x[p[4]],y[p[4]],0,0);
        if(DEBUG) printf("flying to home,now ans=%lf\n",ans);
        return ans;
    }
int main(){
    for(int i=0;i<5;i++){
        scanf("%lf %lf",&x[i],&y[i]);
        if(DEBUG) printf("%lf,%lf",x[i],y[i]);
    }
    if(DEBUG) printf("\n");
    int p[]={0,1,2,3,4};
    double ans=totlen(p);
    while(next_permutation(p,p+5)){
        if(DEBUG){
            for(int i=0;i<5;i++) printf("%d ",p[i]);
            printf("\n");
            printf("%lf\n",totlen(p));
        }
        ans=min(ans,totlen(p));
    }
    int result=(int)ans;
    printf("%d\n",result);
    /*
    int n;
    while(scanf("%d",&n)&&n){
        int a[1000];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);//可以自行测试一下删除后的结果
        do{
            for(int i=0;i<n;i++)
                printf("%d ",a[i]);
            printf("\n");
        }while(next_permutation(a,a+n));
    }
    */
    return 0;
}