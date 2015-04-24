#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct pro{
	int s;
	int e;
};

bool cmp(pro a,pro b)
{
	return a.s<b.s;
}

int dp[30];

int main()
{
	int n;
	pro a[105];
	while(scanf("%d",&n)&&n>0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d %d",&a[i].s,&a[i].e);
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++)
//			printf("%d %d\n",a[i].s,a[i].e);
		memset(dp,0,sizeof(dp));
		int j=1,i=0;
		while(i<24&&j<=n)
		{
			if(i)
				dp[i]=max(dp[i-1],dp[i]);
			if(i==a[j].s)
			{
				dp[a[j].e]=max(dp[a[j].e],dp[i]+1);
				j++;
			}
	//		if(i>a[j].e)
	//			j++;
			if(i<a[j].s)
				i++;
		}
		int max0=0;
		for(int i=0;i<24;i++)
			max0=(dp[i],max0);
		printf("%d\n",max0);
	}
}
