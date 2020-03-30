#include <bits/stdc++.h>
#define MAXN 50010
#define ll long long
#define inf LLONG_MAX/3

using namespace std;

struct Wave{
    int t,x,y,fx,fy;
}wave[MAXN];
int fx[MAXN],fy[MAXN];
bool cmp_x(Wave x,Wave y){
    return x.x<y.x;
}
bool cmp_y(Wave x,Wave y){
    return x.y<y.y;
}
bool cmp_t(Wave x,Wave y){
    return x.t<y.t;
}

struct Data {
	ll lazy,hislazy;
};
struct Tree {
	int left,right,ls,rs;
	Data min,notmin;
	ll val,sec,hisval;
	Tree(int l=0,int r=0,ll v=inf,ll hisv=inf):left(l),right(r),val(v),sec(inf),hisval(hisv) {
		notmin.lazy=min.lazy=notmin.hislazy=min.hislazy=ls=rs=0;
	}
};
struct SegmentTree {
	Tree tree[MAXN<<2];
	#define ls tree[index].ls
	#define rs tree[index].rs
	int size;
	void push_up(int index) {
		tree[index].val=min(tree[ls].val,tree[rs].val);
		if(tree[ls].val>tree[rs].val)tree[index].sec=min(tree[ls].val,tree[rs].sec);
		if(tree[ls].val<tree[rs].val)tree[index].sec=min(tree[rs].val,tree[ls].sec);
		if(tree[ls].val==tree[rs].val)tree[index].sec=min(tree[ls].sec,tree[rs].sec);
		tree[index].hisval=min(tree[ls].hisval,tree[rs].hisval);
	}
	void build_tree(int index,int Left,int Right) {
		tree[index]=Tree(Left,Right);
		if(Left==Right) {
			tree[index].val=tree[index].hisval=0;
			return;
		}
		int mid=(Left+Right)>>1;
		ls=index<<1;
		rs=index<<1|1;
		build_tree(ls,Left,mid);
		build_tree(rs,mid+1,Right);
		push_up(index);
	}
	void mupdate(int index,Data x) {
		tree[index].hisval=min(tree[index].hisval,tree[index].val+x.hislazy);
		tree[index].min.hislazy=min(tree[index].min.hislazy,tree[index].min.lazy+x.hislazy);
		tree[index].val+=x.lazy;
		tree[index].min.lazy+=x.lazy;
	}
	void update(int index,Data x) {
		tree[index].notmin.hislazy=min(tree[index].notmin.hislazy,tree[index].notmin.lazy+x.hislazy);
		tree[index].sec+=x.lazy;
		tree[index].notmin.lazy+=x.lazy;
	}
	void mpush_down(int index,int lv,int rv) {
		if(!tree[index].min.lazy&&!tree[index].min.hislazy)return;
		if(lv<=rv)mupdate(ls,tree[index].min);
		if(rv<=lv)mupdate(rs,tree[index].min);
		tree[index].min.lazy=tree[index].min.hislazy=0;
	}
	void push_down(int index) {
		if(tree[index].left==tree[index].right)return;
		int lv=tree[ls].val,rv=tree[rs].val;
		mpush_down(index,lv,rv);
		if(!tree[index].notmin.lazy&&!tree[index].notmin.hislazy)return;
		if(lv>rv)mupdate(ls,tree[index].notmin);
		if(rv>lv)mupdate(rs,tree[index].notmin);
		update(ls,tree[index].notmin);
		update(rs,tree[index].notmin);
		tree[index].notmin.lazy=tree[index].notmin.hislazy=0;
	}
	void modify(int index,int Left,int Right,int v) { //Çø¼ä+
		if(Left>tree[index].right||Right<tree[index].left)return;
		if(Left<=tree[index].left&&Right>=tree[index].right) {
			mupdate(index,(Data) {v,v});
			update(index,(Data) {v,v});
			return;
		}
		push_down(index);
		modify(ls,Left,Right,v);
		modify(rs,Left,Right,v);
		push_up(index);
	}
	void mmodify(int index,int Left,int Right,int v) { //×îÐ¡+
		if(tree[index].left>Right||tree[index].right<Left)return;
		if(v<=tree[index].val)return;
		if(Left<=tree[index].left&&tree[index].right<=Right&&v<tree[index].sec) {
			mupdate(index,(Data) {v-tree[index].val,v-tree[index].val});
			return;
		}
		push_down(index);
		mmodify(ls,Left,Right,v);
		mmodify(rs,Left,Right,v);
		push_up(index);
	}
	ll query(int index,int Left,int Right,bool flag) {
		if(Left>tree[index].right||Right<tree[index].left)return inf;
		if(Left<=tree[index].left&&Right>=tree[index].right)return flag?tree[index].val:tree[index].hisval;
		push_down(index);
		return min(query(ls,Left,Right,flag),query(rs,Left,Right,flag));
	}
}ST;

int main(){
    ll ans=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&wave[i].x,&wave[i].y),wave[i].t=i;
    sort(wave+1,wave+1+n,cmp_x);
    int nowk=1;
    fx[nowk]=wave[1].x,wave[1].fx=nowk,nowk++;
    for(int i=2;i<=n;i++){
        if(wave[i].x>fx[nowk-1]){
            fx[nowk]=wave[i].x,wave[i].fx=nowk,nowk++;
        }
    }
    ST.build_tree(1,1,n);
    sort(wave+1,wave+1+n,cmp_t);
    for(int i=n;i>=1;i--){
        ll tmp=ST.query(1,wave[i].fx,wave[i].fx,1);
        if(tmp<wave[i].y){
            ans+=wave[i].y-tmp;
            ST.mmodify(1,1,wave[i].fx,wave[i].y);
        }
    }
    sort(wave+1,wave+1+n,cmp_y);
    nowk=1;
    fy[nowk]=wave[1].y,wave[1].fy=nowk,nowk++;
    for(int i=2;i<=n;i++){
        if(wave[i].y>fy[nowk-1]){
            fy[nowk]=wave[i].y,wave[i].fy=nowk,nowk++;
        }
    }
    ST.build_tree(1,1,n);
    sort(wave+1,wave+1+n,cmp_t);
    for(int i=n;i>=1;i--){
        ll tmp=ST.query(1,wave[i].fy,wave[i].fy,1);
        if(tmp<wave[i].x){
            ans+=wave[i].x-tmp;
            ST.mmodify(1,1,wave[i].fy,wave[i].x);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
