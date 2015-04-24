#include<cstdio>
#include<cstring>
#define maxn 50005
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
		tree[start]=tree[2*start]+tree[2*start+1];
	}
}

void update(int start,int a,int b,int low,int high)
{
	if(low==high)
		tree[start]+=b;
	else
	{
		int mid=(high+low)/2;
		if(a<=mid)
			update(2*start,a,b,low,mid);
		else
			update(2*start+1,a,b,mid+1,high);
		tree[start]=tree[2*start+1]+tree[2*start];
	}
}

int query(int start,int a,int b,int low,int high)
{
	if(a<=low&&b>=high)
		return tree[start];
	else
	{
		int sum=0;
		int mid=(low+high)/2;
		if(a<=mid)
			sum+=query(2*start,a,b,low,mid);
		if(b>mid)
			sum+=query(2*start+1,a,b,mid+1,high);
		return sum;
	}
		
}

int main()
{
	int t,cnt=1,n,a,b;
	scanf("%d",&t);
	char str[10];
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		build(1,1,n);
		printf("Case %d:\n",cnt++);
//		printf("%d\b",query(1,2,6,1,n));
		while(1)
		{
			scanf("%s",str);
			if(str[0]=='A')
			{
				scanf("%d %d",&a,&b);
				update(1,a,b,1,n);
			}
			if(str[0]=='S')
			{
				scanf("%d %d",&a,&b);
				update(1,a,-b,1,n);
			}
			if(str[0]=='Q')
			{
				scanf("%d %d",&a,&b);
				printf("%d\n",query(1,a,b,1,n));
			}
			if(str[0]=='E')
				break;
		}
	}
	return 0;
}
