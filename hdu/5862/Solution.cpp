#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define MAXN 100010
#define ll long long//会爆int,可能的最大值是n^2/4
#define VERTICAL_UP 1
#define HORIZONTAL 2
#define VERTICAL_DOWN 3

using namespace std;

/*
vertex从1开始标号，奇数代表左（上）端点，偶数是右（下）端点
按照id排序的话,1..2*hori_num都是水平线的端点,2*hori_num+1..2*n都是竖直线的端点,n-hori_num=verti_num
*/
struct node{
    int id,x,y,type;
}vertex[MAXN<<2];
bool cmp_id(node x,node y){return x.id<y.id;}
bool cmp_x(node x,node y){return x.x<y.x;}
bool cmp_y(node x,node y){return x.y<y.y;}
bool cmp(node x,node y){
    if (x.y==y.y){
        if(x.type==y.type) return x.id<y.id;
        return x.type<y.type;
    }
    return x.y>y.y;
}

int cnt[MAXN<<4];
void update(int id,int l,int r,int num,int flag){
    if(l==r&&l==num){cnt[id]+=flag;return;}
    int mid=(l+r)>>1;
    if(num<=mid) update(id<<1,l,mid,num,flag);else update(id<<1|1,mid+1,r,num,flag);
    cnt[id]=cnt[id<<1]+cnt[id<<1|1];
    return;
}
int query(int id,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return cnt[id];
    int mid=(l+r)>>1;
    if(qr<=mid) return query(id<<1,l,mid,ql,qr);
    else if (ql>=mid+1)return query(id<<1|1,mid+1,r,ql,qr);
    else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,verti_num=0,hori_num=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2){//竖直线从后往前存
                if(y1<y2) swap(y1,y2);//确保奇数点是上端点
                verti_num++;
                vertex[2*(n-verti_num+1)-1].type=VERTICAL_UP,vertex[2*(n-verti_num+1)].type=VERTICAL_DOWN;
                vertex[2*(n-verti_num+1)-1].id=2*(n-verti_num+1)-1,vertex[2*(n-verti_num+1)].id=2*(n-verti_num+1);
                vertex[2*(n-verti_num+1)-1].x=x1,vertex[2*(n-verti_num+1)-1].y=y1;
                vertex[2*(n-verti_num+1)].x=x2,vertex[2*(n-verti_num+1)].y=y2;
            }else if(y1==y2){//水平线从前往后存
                if(x1>x2) swap(x1,x2);//确保奇数点是左端点
                hori_num++;
                vertex[2*hori_num-1].type=vertex[2*hori_num].type=HORIZONTAL;
                vertex[2*hori_num-1].id=2*hori_num-1,vertex[2*hori_num].id=2*hori_num;
                vertex[2*hori_num-1].x=x1,vertex[2*hori_num-1].y=y1;
                vertex[2*hori_num].x=x2,vertex[2*hori_num].y=y2;
            }
        }
        //离散化,x坐标和y坐标分别离散化,注意sort的数组下标范围,排序0..n-1时下标为+0,+n,排序1..n时下标为+1,+n+1
        sort(vertex+1,vertex+2*n+1,cmp_x);
        int last_x=vertex[1].x,cnt_x=1;
        for (int i=1;i<=2*n;i++){
            if(vertex[i].x==last_x) vertex[i].x=cnt_x; else last_x=vertex[i].x,vertex[i].x=++cnt_x;
        }
        sort(vertex+1,vertex+2*n+1,cmp_y);
        int last_y=vertex[1].y,cnt_y=1;
        for (int i=1;i<=2*n;i++){
            if(vertex[i].y==last_y) vertex[i].y=cnt_y;else last_y=vertex[i].y,vertex[i].y=++cnt_y;
        }
        sort(vertex+1,vertex+2*n+1,cmp_id);
        //开始建树，用于查询一段x区间上竖直线的个数
        memset(cnt,0,sizeof(cnt));
        //正确算法为自上而下扫描，遇到竖直线的上端点则update+1,有水平线则查询,有竖直线下端点则update-1，顺序不能错
        ll ans=0;
        sort(vertex+1,vertex+2*n+1,cmp);
        int nowk=1;
        while(nowk<=2*n){
            if(vertex[nowk].type==VERTICAL_UP) update(1,1,cnt_x,vertex[nowk++].x,1);
            else if (vertex[nowk].type==VERTICAL_DOWN) update(1,1,cnt_x,vertex[nowk++].x,-1);
            else if (vertex[nowk].type==HORIZONTAL){
                ans+=query(1,1,cnt_x,vertex[nowk].x,vertex[nowk+1].x),nowk+=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
