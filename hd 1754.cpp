#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 200005
int tree[maxn*4];

void build(int start,int low,int high)
{
	if(low==high)
	{
		scanf("%d",&tree[start]);
		return ;
	}
	else
	{
		int  mid=(high+low)/2;
		build(start*2,low,mid);
		build(start*2+1,mid+1,high);
		tree[start]=max(tree[2*start],tree[2*start+1]);
	}
}

void update(int start,int a,int b,int low,int high)
{
	if(low==high)
	{
		tree[start]=b;
		return ;
	}
	else
	{
		int mid=(low+high)/2;
		if(a<=mid)
			update(start*2,a,b,low,mid);
		else
			update(2*start+1,a,b,mid+1,high);
		tree[start]=max(tree[start*2],tree[start*2+1]);
	}
}

int query(int start,int a,int b,int low,int high)
{
	int ans=0;
	if(a<=low&&b>=high)
		return tree[start];
	else
	{
		int mid=(low+high)/2;
		if(a<=mid)
			ans=max(query(2*start,a,b,low,mid),ans);
		if(b>mid)
			ans=max(query(2*start+1,a,b,mid+1,high),ans);
	}
	return ans;
		
}

int main()
{
	memset(tree,0,sizeof(0));
	int n,m,a,b;
	char c;
	scanf("%d %d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%c %d %d",&c,&a,&b);
		if(c=='Q')	
			printf("%d\n",query(1,a,b,1,n));
		if(c=='U')
			update(1,a,b,1,n);
	}
	return 0;
}
