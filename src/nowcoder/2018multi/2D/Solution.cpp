#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,max_sell=0,min_sell_op=0,max_buy=INT_MIN,min_buy_op=0;
        cin>>n;
        for (int i=0;i<n;i++){
            ll p;
            cin>>p;
            ll new_max_sell=max_sell,new_min_sell_op=min_sell_op,new_max_buy=max_buy,new_min_buy_op=min_buy_op;
            if(max_sell<=max_buy+p){
                new_max_sell=max_buy+p;
                if(max_sell==max_buy+p) new_min_sell_op=min(min_sell_op,min_buy_op+1);else new_min_sell_op=min_buy_op+1;

            }
            if(max_buy<=max_sell-p){
                new_max_buy=max_sell-p;
                if(max_buy==max_sell-p) new_min_buy_op=min(min_sell_op+1,min_buy_op);else new_min_buy_op=min_sell_op+1;
            }
            max_sell=new_max_sell,min_sell_op=new_min_sell_op,max_buy=new_max_buy,min_buy_op=new_min_buy_op;
        }
        cout<<max_sell<<" "<<min_sell_op<<endl;
    }
    return 0;
}
