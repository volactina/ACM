#include <bits/stdc++.h>
#define ll long long
#define MAXN 500010
using namespace std;
int n;
vector<int> a;
bool judge(int x);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a.clear();
		for (int i=0;i<n;++i)
		{
			int tmp;
			scanf("%d",&tmp);
			a.push_back(tmp);
		}
		int l=0,r=100000017;
		while(r-l>=2)
		{
			int mid=(l+r)/2;
			if(judge(mid)) l=mid;
			else r=mid;
		}
		cout<<l<<endl;
	}
	return 0;
}
bool judge(int x)
{
	ll ned=0,g=0;
	for (int i=0;i<n;++i)
		if(a[i]<x) ned+=x-a[i];else g+=(a[i]-x)/2;
	if(g>=ned) return true;
	return false;
}