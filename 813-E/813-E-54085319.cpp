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
vector <int> tree[4*mx+1];
int lo[4*mx+1],hi[4*mx+1],a[mx],b[mx],c[mx],prev1[mx];
vector <int> vec[mx];
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
int merge(int i0,int i1,int i2)
{
	int s1=tree[i1].size();
	int s2=tree[i2].size();
	int i=0,j=0;
	while(i<s1 && j<s2)
	{
		if(tree[i1][i]<=tree[i2][j])
			tree[i0].pb(tree[i1][i++]);
		else if(tree[i1][i]>tree[i2][j])
			tree[i0].pb(tree[i2][j++]);
	}
	while(i<s1)
	{
		tree[i0].pb(tree[i1][i++]);
	}
	while(j<s2)
	{
		tree[i0].pb(tree[i2][j++]);	
	}
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i].pb(c[l]);
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
int query(int i,int l,int r,int val)
{
	if(r<lo[i] || hi[i]<l)
		{
		return 0;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return upper_bound(tree[i].begin(),tree[i].end(),val)-tree[i].begin();
	}
	return query(2*i,l,r,val)+query(2*i+1,l,r,val);
}
int get_prev1(int i,int k1)
{
	if(k1==1)
		return b[i];
	else
		return get_prev1(b[i],k1-1);
}
int main()
{
	IOS;
	int n,k,q;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vec[a[i]].pb(i);
	}
	cin>>q;
	for(int i=1;i<=100000;i++)
	{
		if(!vec[i].empty())
		{
			for(int j=vec[i].size()-1;j>=0;j--)
			{
				if(j-k>=0)
					c[vec[i][j]]=vec[i][j-k];
				else
					c[vec[i][j]]=-1;
			}
		}
	}
	init(1,1,n);;
	build(1);
	int last=0;
	while(q--)
	{
		int x,y,l,r;
		cin>>x>>y;
		// l=x;
		// r=y;
		l=(x+last)%n+1;
		r=(y+last)%n+1;
		if(l>r)
			swap(l,r);
		//cout<<l<<" "<<r<<": ";
		last=query(1,l,r,l-1);
		cout<<last<<endl;
	}
}