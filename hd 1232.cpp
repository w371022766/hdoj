#include<cstdio>
#include<cstring>

int pre[1005];
bool flag[1005];

int Find(int x)
{
	int r=x;
	while(pre[r]!=r)
		r=pre[r];
	int i=x,j;
	while(pre[i]!=i)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

void mix(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx!=fy)
		pre[fx]=fy;
}

int main()
{
	int n,m,v1,v2,ans;
	while(scanf("%d",&n)&&n>0)
	{
		scanf("%d",&m);
		for(int i=0;i<1005;i++)
			pre[i]=i;
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d",&v1,&v2);
			mix(v1,v2);
		}
		memset(flag,0,sizeof(flag));
		ans=0;
		
		for(int i=1;i<=n;i++)
			flag[Find(i)]=1;
		
		for(int i=1;i<=n;i++)
			if(flag[i])
				ans++;
		printf("%d\n",ans-1);
	}
	return 0;
}
