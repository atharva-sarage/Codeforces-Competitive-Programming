#include<bits/stdc++.h>
using namespace std;
# define mx 150005
int tree[4*mx+1],lo[4*mx+1],hi[4*mx+1],a[mx];
void init(int i,int a,int b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	int m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
}
int merge(int i1,int i2,int flag)
{
	if(flag==1)
		return i1|i2;
	else
		return i1^i2;	
}
void build(int i,int flag)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i]=a[l];
		return;
	}
	build(2*i,flag^1);
	build(2*i+1,flag^1);
	tree[i]=merge(tree[2*i],tree[2*i+1],flag);
}
void update(int i,int pos,int val,int flag )
{
	int l=lo[i];
	int r=hi[i];
	if(lo[i]==hi[i] && lo[i]==pos)
	{
		tree[i]=val;
		return;
	}
	int m=(l+r)/2;
	if(pos<=m)
		update(2*i,pos,val,flag^1);
	else
		update(2*i+1,pos,val,flag^1);

	tree[i]=merge(tree[2*i],tree[2*i+1],flag);
}
int main()
{
	int n,m;
	cin>>n>>m;
	n=pow(2,n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	init(1,1,n);
	int flag=0;
	if((int) log2(n)%2==1)
		flag=1;

	build(1,flag);	
	while(m--)
	{
		int p,b;
		cin>>p>>b;
		update(1,p,b,flag);
		cout<<tree[1]<<endl;
	}
}