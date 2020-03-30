#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        double a,b;
        cin>>a>>b;
        const double pi=acos(-1);
        double ans=pi*a+2.0*b;
        char s[1000];
        sprintf(s,"%.7lf",ans);
        int len=strlen(s);
        for(int i=0;i<len-1;i++){
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
