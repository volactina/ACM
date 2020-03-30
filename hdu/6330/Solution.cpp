#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int rowlen=2*a+1+2*b,rownum=0,colen=2*c+2*b+1;
        for(int row=0;row<2*b;row++){
            int backdotnum=rowlen-(2*a+1)-(colen-rownum)+1;
            if(row%2==0){
                for(int j=0;j<2*b-row;j++) printf(".");
                for(int j=0;j<a;j++) printf("+-");
                printf("+");
                int cnt=0;
                if(backdotnum<=0){
                    for(int j=0;j<row/2;j++) printf(".+");
                }else{
                    cnt=rowlen-backdotnum-(2*b-row)-(2*a+1);
                    for(int i=0;i<cnt/2;i++) printf(".+");
                }
            }else{
                for(int j=0;j<2*b-row;j++) printf(".");
                for(int j=0;j<a;j++) printf("/.");
                int cnt=0;
                if(backdotnum<=0){
                    for(int j=0;j<row/2+1;j++) printf("/|");
                }else{
                    cnt=rowlen-backdotnum-(2*b-row)-(2*a+1);
                    for(int i=0;i<cnt/2;i++) printf("/|");
                    printf("/");
                }
            }
            if(backdotnum>0) for(int i=0;i<backdotnum;i++) printf(".");
            printf("\n"),rownum++;
        }
        for(int row=0;row<2*c;row++){
            int backdotnum=rowlen-(2*a+1)-(colen-rownum)+1;
            if(row%2==0){
                for(int j=0;j<a;j++) printf("+-");
                printf("+");
                int cnt=0;
                if(backdotnum<=0){
                    cnt=rowlen-2*a-1;
                }else{
                    cnt=rowlen-2*a-backdotnum-1;
                }
                for(int i=0;i<cnt/2;i++) printf(".+");
            }else{
                for(int j=0;j<a;j++) printf("|.");
                printf("|");
                int cnt=0;
                if(backdotnum<=0){
                    cnt=rowlen-2*a-1;
                }else{
                    cnt=rowlen-2*a-1-backdotnum;
                }
                for(int i=0;i<cnt/2;i++) printf("/|");
                if(backdotnum>0) printf("/");
            }
            if(backdotnum>0){
                for(int i=0;i<backdotnum;i++) printf(".");
            }
            printf("\n"),rownum++;
        }
        for(int i=0;i<a;i++) printf("+-");
        printf("+");
        int dotnum=rowlen-(2*a+1);
        for(int i=0;i<dotnum;i++) printf(".");
        printf("\n");
    }
    return 0;
}
