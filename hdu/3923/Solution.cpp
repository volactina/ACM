1.	#include <cstdio>
2.	 
3.	#define LL __int64
4.	const LL mm=1000000007;
5.	LL mod, pow[10005];
6.	int n, m;
7.	 
8.	LL gcd(LL a, LL b)
9.	{
10.	    return b==0 ? a : gcd(b,a%b);
11.	}
12.	 
13.	LL rotat()     //旋转时的不动点
14.	{
15.	    LL ans = 0;
16.	    for (int i=0; i<m; ++i)
17.	        ans = (ans+pow[gcd(i,m)]) % mod;
18.	    return ans;
19.	}
20.	 
21.	LL overturn()  //翻转时的不动点，分奇偶讨论
22.	{
23.	    LL ans = 0;
24.	    if(m & 1)
25.	        ans = (ans+m*pow[(m+1)/2]) % mod;
26.	    else
27.	        ans = (ans+m/2*(pow[m/2+1]+pow[m/2])) % mod;
28.	    return ans;
29.	}
30.	 
31.	int main ()
32.	{
33.	    int cas, t=0;
34.	    scanf("%d", &cas);
35.	    while(cas--)
36.	    {
37.	        LL ans = 0;
38.	        scanf("%d%d", &n, &m);
39.	        mod = 2*m*mm;
40.	        pow[0] = 1;
41.	        for(int i=1; i<=m; ++i)
42.	            pow[i] = (pow[i-1]*n) % mod;
43.	        ans += rotat();
44.	        ans  = (ans + overturn()) % mod;
45.	        printf("Case #%d: %I64d\n", ++t, (ans/2/m)%mm);
46.	    }
47.	    return 0;
48.	}
