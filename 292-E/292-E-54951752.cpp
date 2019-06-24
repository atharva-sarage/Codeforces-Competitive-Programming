/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 100005
int lo[8*mx+1],hi[8*mx+1],a[mx],b[mx];
pair<int,int> tree[8*mx+1];
bool lazy_node[8*mx];
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
void merge(int i0,int i1,int i2)
{
	tree[i0]={-1,-1};
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i]={-1,-1};
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
void prop(int i)
{
	if(lazy_node[i])
	{
		tree[2*i]={tree[i].ff,tree[i].ff+hi[2*i]-lo[2*i]};
		tree[2*i+1]={tree[i].ss-hi[2*i+1]+lo[2*i+1],tree[i].ss};
		lazy_node[2*i]=lazy_node[2*i+1]=true;
	}
	lazy_node[i]=false;
}
void increment(int i,int a,int b,int offset)
{
	//cout<<lo[i]<<" "<<hi[i]<<"\n";
	if(b<lo[i] || hi[i]<a)
		return ;
	if(a<=lo[i] && hi[i]<=b)
		{
		lazy_node[i]=true;
		//cout<<i<<" "<<lo[i]<<" "<<hi[i]<<" :"<<lo[i]+offset<<" "<<offset+hi[i]<<"\n";
		tree[i]={lo[i]+offset,offset+hi[i]};
		return ;
		}
	prop(i);
	increment(2*i,a,b,offset);
	increment(2*i+1,a,b,offset);
	merge(i,2*i,2*i+1);
}
void query(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
	{
		return ;
	}
	if(l<=lo[i] && hi[i]<=r)
	{
		if(tree[i].ff==-1)
			cout<<b[l]<<"\n";
		else
			cout<<a[tree[i].ff]<<"\n";
	}
	prop(i);
	query(2*i,l,r);
	query(2*i+1,l,r);
}

int main()
{
    IOS;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	init(1,1,n);
	build(1);
	while(q--)
	{
		int l,r,t;
		cin>>t;
		if(t==1)
		{
			int l,r,x;
			cin>>l>>r>>x;
			x--;
			//cout<<r<<" "<<r+x<<"\n";
			increment(1,r,r+x,l-r);
		}
		else
		{
			int l;
			cin>>l;
			query(1,l,l);
		}

	}
}